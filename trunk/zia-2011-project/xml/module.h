#ifndef MODULE_H
#define MODULE_H
#include <QString>
#include <QList>

class Module
{
    QString path;
    QString name;
public:
    QList<QString> type;
    Module();
    void addType(QString);
    void setName(QString);
    void setPath(QString);
    QString getName() const;
    QString getPath() const;
    Module(const Module&);
    Module& operator=(const Module&);
};

#endif // MODULE_H
