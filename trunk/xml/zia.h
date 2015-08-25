#ifndef ZIA_H
#define ZIA_H
#include <QString>
#include <QList>
#include <xml/module.h>

class Zia
{
    QString documentRoot;
    int port;
public:
    QList<Module> modules;
    QList<QString> default_extensions;
    QList<QString> forbidden_path;
    void addModule(QString, QString);
    void deleteModule(QString);
    void setDocumentRoot(QString);
    void setPort(int);
    void modifDocumentRoot(QString);
    void modifPort(int);
    void addTypeByList(QString _module, QList<QString> _type);
    void addTypeByOne(QString _module, QString _type);
    void deleteType(QString _module, QString _type);
    void maj();
    int getPort() const;
    QString getDocumentRoot() const;
    Zia();
    Zia(const Zia&);
    Zia& operator=(const Zia&);
};

#endif // ZIA_H
