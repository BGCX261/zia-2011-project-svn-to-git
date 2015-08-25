#include "gui.h"
#include "gui/moduleswindow.h"
#include <QMessageBox>
#include <StaticFunctions.h>

gui::gui(const char *name, int width, int height, bool frame, QString logo, QString filename) : QWindowAPI(name, width, height, frame, logo, filename)
{
    QPalette palette;
    QImage  image;

    this->setFixedSize(height, width);
    this->setWindowTitle(name);
    if (!filename.isNull() && !filename.isEmpty())
    {
        image.load(filename);
        palette.setBrush(this->backgroundRole(), image);
        this->setPalette(palette);
        this->setWindowIcon(QIcon(logo));
    }
    if (frame)
    setWindowFlags(Qt::FramelessWindowHint);
    this->port = 0;
    this->DocumentRoot.clear();
    this->XmlPath.clear();
    this->state = false;
    this->tmp = new ModulesWindowClass("Gestionnaire de fenetres", 300, 500, false, NULL, NULL);
    this->mod = NULL;
    this->BuildWindow();
    this->LoadXmlValues();
}

gui::~gui()
{
    delete this->StartButton;
    delete this->StopButton;
    delete this->RestartButton;
    delete this->ModulesManager;
}

void        gui::ModulesWindow()
{
    this->mod = tmp->Instance();
    this->mod->show();
}

void                    *threadCallNotifierGui(void *data)
{
    struct  CPanelState *ThreadState;
    QImage image = QImage();

    image.load("img/offline.png");
    ThreadState = static_cast<CPanelState*>(data);
    pthread_join(*ThreadState->thread, NULL);
    ThreadState->guiPointer->stop();
    pthread_exit(ThreadState->CPanelErrno);
}

void                    *threadCallGUI(void *data)
{
    struct  CPanelData  *gui;

    gui = static_cast<CPanelData*>(data);
    if ((*gui->CPanelErrno = gui->network->StartServer()) != OK)
    {
        gui->thread->p = NULL;
        pthread_exit(gui->CPanelErrno);
    }
}

int        gui::start()
{
    struct  CPanelData     *gui;
    struct  CPanelState    *ThreadState;

    gui = new CPanelData;
    ThreadState = new CPanelState;
    if (this->state == true)
    {
        QMessageBox::critical(this, "Erreur", "Le serveur est deja lance");
        return 0;
    }
    if (this->port == 0 || this->DocumentRoot.empty())
    {
        QMessageBox::critical(this, "Erreur", "Please fill in correctly input values");
        std::cout << this->port << this->DocumentRoot;
        return 0;
    }
    this->XmlReader = new Lecture_DOM();
    this->XmlLoader = new Zia();
    this->XmlReader->lire(*this->XmlLoader);
    this->XmlLoader->modifPort(this->port);
    this->XmlLoader->modifDocumentRoot(QString(this->DocumentRoot.c_str()));
    this->XmlLoader->maj();
    this->network = new AbstractSocketClassWindows(this->port, this->DocumentRoot, HandleXArgv("ziad.xml"));
    this->state = true;
    this->CPanelErrno = 1;
    gui->network = this->network;
    gui->CPanelErrno = &this->CPanelErrno;
    gui->thread = &this->thread;
    ThreadState->state = &this->state;
    ThreadState->CPanelErrno = &this->CPanelErrno;
    ThreadState->thread = &this->thread;
    ThreadState->StateImage = this->StateImage;
    ThreadState->guiPointer = this;
    delete this->StateImage;
    this->StateImage = this->CreateImage(this, "img/online", 32, 32, 450, 30);
    if (pthread_create(&this->thread, NULL, threadCallGUI, gui) == -1)
        return PTHREADERROR;
    if (pthread_create(&this->threadNotifier, NULL, threadCallNotifierGui, ThreadState) == -1)
        return PTHREADERROR;
}

int        gui::stop()
{
    if (this->state == false)
        return -1;
    if (pthread_cancel(this->thread) == -1)
        std::cout << "Could not delete thread " << this->thread.p << std::endl;
    if (pthread_cancel(this->threadNotifier) == -1)
        std::cout << "Could not delete thread " << this->thread.p << std::endl;
    this->network->StopServer();
    this->state = false;
    delete this->StateImage;
    this->StateImage = this->CreateImage(this, "img/offline", 32, 32, 450, 30);
    return 0;
}

int        gui::restart()
{
    if (this->state == true)
        this->stop();
    this->start();
}

void        gui::PortInputChange(QString data)
{
    this->port = data.toInt();
}

void        gui::DocumentRootInputChange(QString data)
{
    this->DocumentRoot = data.toStdString();
}

void        gui::HandleDocumentRoot(QString folder)
{
    this->DocumentRoot = folder.toStdString();
    this->DocumentRootInput->setText(folder);
}

void        gui::DocumentRootBrowse()
{
    QFileDialog         *filedialog = new QFileDialog();

    connect(filedialog, SIGNAL(fileSelected(QString)), this, SLOT(HandleDocumentRoot(QString)));
    filedialog->setFileMode(QFileDialog::DirectoryOnly);
    filedialog->show();
}

bool        gui::tray()
{
    if (!QSystemTrayIcon::isSystemTrayAvailable())
     {
        QMessageBox::critical(0, QObject::tr("Systray"), QObject::tr("There is no system tray on this system."));
        return 1;
     }
    TrayIcon = new QSystemTrayIcon(this);
    QIcon icon("img/trayIcon.png");
    TrayIcon->setIcon(icon);
    connect(this->TrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(slotTrayActivated(QSystemTrayIcon::ActivationReason)));
    if (isHidden())
    {
        show();
        TrayIcon->hide();
    }
    else
    {
        hide();
        TrayIcon->show();
    }
}

void            gui::slotTrayActivated(QSystemTrayIcon::ActivationReason reason)
{
   switch (reason) {
   case QSystemTrayIcon::DoubleClick:
         show();
         TrayIcon->hide();
      break;
   case QSystemTrayIcon::Information:
        //show();
         //TrayIcon->hide();
   default:
      ;
   }
}

void        gui::ConnectMyObjects()
{
    connect(this->ModulesManager, SIGNAL(clicked()), this, SLOT(ModulesWindow()));
    connect(this->StartButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(this->StopButton, SIGNAL(clicked()), this, SLOT(stop()));
    connect(this->RestartButton, SIGNAL(clicked()), this, SLOT(restart()));
    connect(this->PortInput, SIGNAL(textChanged(QString)), this, SLOT(PortInputChange(QString)));
    connect(this->DocumentRootInput, SIGNAL(textChanged(QString)), this, SLOT(DocumentRootInputChange(QString)));
    connect(this->DocumentRootPath, SIGNAL(clicked()), this, SLOT(DocumentRootBrowse()));
    connect(this->CloseCross, SIGNAL(clicked()), this, SLOT(close()));
    connect(this->Minimize, SIGNAL(clicked()), this, SLOT(tray()));
}

void        gui::BuildWindow()
{
    (this->CloseCross = this->CreateClickableImage(this, "img/cross.png", 16, 16, 580, 2))->setCursor(Qt::PointingHandCursor);
    (this->Minimize = this->CreateClickableImage(this, "img/minimize.png", 16, 16, 560, 2))->setCursor(Qt::PointingHandCursor);
    this->CreateImage(this, "img/title", 80, 143, 20, 25);
    this->CreateText(this, "State :", 50, 20, 400, 35)->setStyleSheet("color:#ffffff;font-weight:bold");
    this->CreateImage(this, "img/offline", 32, 32, 450, 30);
    (this->StartButton = this->CreateClickableImage(this, "img/start.png", 60, 60, 120, 100))->setCursor(Qt::PointingHandCursor);
    this->CreateText(this, "Start", 50, 20, 135, 170)->setStyleSheet("color:#ffffff;font-weight:bold");
    (this->StopButton = this->CreateClickableImage(this, "img/stop.png", 60, 60, 260, 100))->setCursor(Qt::PointingHandCursor);
    this->CreateText(this, "Stop", 50, 20, 276, 170)->setStyleSheet("color:#ffffff;font-weight:bold");
    (this->RestartButton = this->CreateClickableImage(this, "img/refresh.png", 60, 60, 400, 100))->setCursor(Qt::PointingHandCursor);
    this->CreateText(this, "Restart", 50, 20, 411, 170)->setStyleSheet("color:#ffffff;font-weight:bold");
    this->CreateText(this, "Port :", 50, 20, 50, 220)->setStyleSheet("color:#ffffff;font-weight:bold");
    this->PortInput = this->CreateInputBox(this, 20, 40, 90, 220, 0);
    this->CreateText(this, "DocumentRoot :", 200, 20, 50, 260)->setStyleSheet("color:#ffffff;font-weight:bold");
    this->DocumentRootInput = this->CreateInputBox(this, 20, 140, 190, 260, 0);
    this->DocumentRootPath = this->CreateButton(this, "Browse", 20, 120, 340, 260, NULL);
    this->ModulesManager = this->CreateButton(this, "Gestionnaire de modules", 20, 180, 350, 220, NULL);
    this->StateImage = this->CreateImage(this, "img/offline", 32, 32, 450, 30);
    this->ConnectMyObjects();
}

void     gui::LoadXmlValues()
{
    if (Lecture_DOM::ValidityFile() == false)
        return;
    this->XmlReader = new Lecture_DOM();
    this->XmlLoader = new Zia();
    this->XmlReader->lire(*this->XmlLoader);
    this->port = this->XmlLoader->getPort();
    this->DocumentRoot = this->XmlLoader->getDocumentRoot().toStdString();
    this->DocumentRootInput->setText(this->DocumentRoot.c_str());
    this->PortInput->setText(QString::number(this->port));
}

void     gui::printState(int code)
{
    std::cout << code;
    if (code == BINDERROR)
        QMessageBox::critical(NULL, "Erreur", "Notifier : Error Code 3 : Server failed to bind given port");
    else if (code == INVALIDSOCKET)
        QMessageBox::critical(NULL, "Erreur", "Notifier : Error Code 1 : Server failed to create a socket");
    else if (code == LISTENERROR)
        QMessageBox::critical(NULL, "Erreur", "Notifier : Error Code 4 : Server failed to listen on the binded port");
    else if (code == PTHREADERROR)
        QMessageBox::critical(NULL, "Erreur", "Notifier : Error Code 5 : Server failed to create a thread");
    else if (code == ACCEPTERROR)
        QMessageBox::critical(NULL, "Erreur", "Notifier : Error Code 6 : Server does not accept new connection");
}
