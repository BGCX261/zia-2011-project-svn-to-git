#include "gui/moduleswindow.h"
#include <QString>
#include <iostream>
#include <QFileDialog>

ModulesWindowClass::ModulesWindowClass(const char *name, int width, int height, bool frame, QString logo, QString filename) : QWindowAPI(name, width, height, frame, logo, filename)
{
    this->instance = NULL;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->width = width;
    this->height = height;
    this->frame = frame;
    this->logo = logo;
    this->filename = filename;
    this->setFixedSize(width, height);
    this->setWindowTitle(name);
    this->BuildWindow();
}

ModulesWindowClass::~ModulesWindowClass()
{

}

void                    ModulesWindowClass::HandleFile(QString file)
{
    std::string filename;
    this->XmlReader = new Lecture_DOM();
    this->XmlLoader = new Zia();

    this->XmlReader->lire(*this->XmlLoader);
    //check module
    if (file.toStdString().find_last_of("/"))
        filename = file.toStdString().substr(file.toStdString().find_last_of("/") + 1, file.toStdString().size());
    this->XmlLoader->addModule(QString(filename.c_str()), file);
    this->XmlLoader->maj();
    this->ModulesList += filename.c_str();
    this->iStandardModel->appendRow(new QStandardItem(QIcon("connected.png"), QString(filename.c_str())));
}

void                    ModulesWindowClass::AddModule()
{
    QFileDialog         *filedialog = new QFileDialog();

    connect(filedialog, SIGNAL(fileSelected(QString)), this, SLOT(HandleFile(QString)));
    filedialog->show();
}

void                    ModulesWindowClass::DeleteModule()
{
    this->XmlReader = new Lecture_DOM();
    this->XmlLoader = new Zia();

    this->XmlReader->lire(*this->XmlLoader);
    for (int i = 0; i < this->ModulesList.length(); i++)
        if (i == this->CurrentIndex)
        {
            this->XmlLoader->deleteModule(this->ModulesList[i]);
            this->XmlLoader->maj();
            this->iStandardModel->removeRow(i);
            this->ModulesList.removeAt(i);
        }
}

void                    ModulesWindowClass::BuildWindow()
{
    this->CreateText(this, "List of loaded modules :", 200, 40, 10, 10);
    this->CreateList(this, 400, 250, 10, 50);
    this->AddButton = this->CreateButton(this, "Add module", 20, 100, 10, 450);
    this->DeleteButton = this->CreateButton(this, "Delete module", 20, 100, 120, 450);
    connect(this->AddButton, SIGNAL(clicked()), this, SLOT(AddModule()));
    connect(this->DeleteButton, SIGNAL(clicked()), this, SLOT(DeleteModule()));
}

ModulesWindowClass      *ModulesWindowClass::Instance()
{
    if (this->instance == NULL)
        this->instance = new ModulesWindowClass(this->name, this->width, this->height, this->frame, this->logo, this->filename);
    return this->instance;
}

void                    ModulesWindowClass::SaveIndex(QModelIndex index)
{
    this->CurrentIndex = index.row();
}

QListView               *ModulesWindowClass::CreateList(QWidget *widget, int height, int width, int pos_x, int pos_y)
{
    QListView *list = new QListView(widget);
    iStandardModel = new QStandardItemModel(this);
    QString icon;
    this->XmlReader = new Lecture_DOM();
    this->XmlLoader = new Zia();

    this->XmlReader->lire(*this->XmlLoader);
    list->move(pos_x, pos_y);
    list->setFixedSize(width, height);
    list->setIconSize(QSize(30, 30));
    list->setModel(iStandardModel);
    list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int i = 0; i < this->XmlLoader->modules.length(); i++)
    {
        QStandardItem* item1 = new QStandardItem(QIcon("connected.png"), this->XmlLoader->modules[i].getName());
        this->ModulesList += this->XmlLoader->modules[i].getName();
        iStandardModel->appendRow(item1);
    }
    list->setModel(iStandardModel);
    list->show();
    connect(list, SIGNAL(clicked(QModelIndex)), this, SLOT(SaveIndex(QModelIndex)));
    return (list);
}
