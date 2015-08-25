#ifndef MODULESWINDOW_H
#define MODULESWINDOW_H

#include "gui/qwindowapi.h"
#include <xml/Lecture.h>
#include <xml/module.h>
#include <xml/SaveXML.h>
#include <xml/type.h>
#include <xml/zia.h>

class ModulesWindowClass : public QWindowAPI
{
    Q_OBJECT

public:
    ModulesWindowClass(const char *name, int width, int height, bool frame, QString logo, QString filename);
    ~ModulesWindowClass();
    ModulesWindowClass  *Instance();

private:
    void                BuildWindow();
    ModulesWindowClass  *instance;
    char                *name;
    int                 width;
    int                 height;
    bool                frame;
    QString             logo;
    QString             filename;
    QListView           *CreateList(QWidget *widget, int height, int width, int pos_x, int pos_y);
    Lecture_DOM         *XmlReader;
    Zia                 *XmlLoader;
    QPushButton         *AddButton;
    QPushButton         *DeleteButton;
    int                 CurrentIndex;
    QList<QString>      ModulesList;

public slots:
    void                SaveIndex(QModelIndex index);
    void                AddModule();
    void                DeleteModule();
    void                HandleFile(QString file);

};

#endif // MODULESWINDOW_H
