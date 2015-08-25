#ifndef GUI_H
#define GUI_H

#include <QtGui/QtGui>
#include <gui/qwindowapi.h>
#include "ICommandPanel.h"
#include <iostream>
#include <xml/Lecture.h>
#include <xml/module.h>
#include <xml/SaveXML.h>
#include <xml/type.h>
#include <xml/zia.h>
#include <gui/moduleswindow.h>

void                    *threadCallGui(void *data);
void                    *threadCallNotifierGui(void *data);

class gui : public QWindowAPI, public ICommandPanel
{
    Q_OBJECT

public:
    gui(const char *name, int width, int height, bool frame, QString logo, QString filename);
    ~gui();
    static void    printState(int code);

private:
    QPushButton                 *ModulesManager;
    QPushButton                 *StartButton;
    QPushButton                 *StopButton;
    QPushButton                 *RestartButton;
    QLineEdit                   *PortInput;
    QLineEdit                   *DocumentRootInput;
    QSystemTrayIcon             *TrayIcon;
    QPushButton                 *DocumentRootPath;
    QPushButton                 *CloseCross;
    QPushButton                 *Minimize;
    QLabel                      *StateImage;
    Lecture_DOM                 *XmlReader;
    Zia                         *XmlLoader;
    ModulesWindowClass          *tmp;
    ModulesWindowClass          *mod;
    inline  virtual QListView   *CreateList(QWidget *widget, int height, int width, int pos_x, int pos_y) {}

    pthread_t                   thread;
    pthread_t                   threadNotifier;
#ifdef WIN32
    AbstractSocketClassWindows  *network;
#endif

    void                BuildWindow();
    void                ConnectMyObjects();
    void                LoadXmlValues();

public slots:
    void                ModulesWindow();
    int                 start();
    int                 stop();
    int                 restart();
    void                PortInputChange(QString data);
    void                DocumentRootInputChange(QString data);
    void                DocumentRootBrowse();
    void                HandleDocumentRoot(QString folder);
    void                slotTrayActivated(QSystemTrayIcon::ActivationReason reason);
    bool                tray();

};

struct  CPanelState
{
    bool            *state;
    QLabel          *StateImage;
    int             *CPanelErrno;
    pthread_t       *thread;
    gui             *guiPointer;
};

#endif // GUI_H
