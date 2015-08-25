#ifndef QWINDOWAPI_H
#define QWINDOWAPI_H

#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QTextEdit>
#include <QListView>
#include <QLineEdit>
#include <QMessageBox>
#include <QMouseEvent>
#include <QStandardItem>

class   QWindowAPI : public QWidget
{

public:
    QWindowAPI(const char *name, int width, int height, bool frame, QString logo, QString filename);
    virtual ~QWindowAPI();

protected:
    QStandardItemModel  *iStandardModel;
    QPoint              m_Diff;

    virtual QPushButton *CreateButton(QWidget *widget, const char *name, int height, int width, int pos_x, int pos_y, const QString stylesheet = "");
    virtual QListView   *CreateList(QWidget *widget, int height, int width, int pos_x, int pos_y) = 0;
    virtual QLineEdit   *CreateInputBox(QWidget *widget, int height, int width, int pos_x, int pos_y, int mode);
    virtual QLabel      *CreateLink(QWidget *widget, QString text, int pos_x, int pos_y, const QString type = NULL);
    virtual QLabel      *CreateText(QWidget *widget, QString text, int width, int height, int pos_x, int pos_y);
    virtual QLabel      *CreateImage(QWidget *widget, const QString filename, int height, int width, int pos_x, int pos_y);
    virtual QPushButton *CreateClickableImage(QWidget *widget, const QString filename, int height, int width, int pos_x, int pos_y);
    virtual void        mousePressEvent(QMouseEvent *event);
    virtual void        mouseReleaseEvent(QMouseEvent *event);
    virtual void        mouseMoveEvent(QMouseEvent *event);

};

#endif // MYWINDOW_H
