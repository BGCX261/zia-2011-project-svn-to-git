#include "zia.h"
#include "SaveXML.h"
#include "module.h"
#include "QMessageBox"

Zia::Zia()
{

}

void Zia::addModule(QString _name, QString _path)
{
    for (int i = 0 ; i < this->modules.size() ; i++)
    {
        if (this->modules[i].getName() == _name)
            return;
    }
    Module temp;
    temp.setName(_name);
    temp.setPath(_path);
    this->modules.push_back(temp);
}

void Zia::deleteModule(QString _name)
{
    for (int i = 0 ; i < this->modules.size() ; i++)
    {
        if (this->modules[i].getName() == _name)
        {
            this->modules.removeAt(i);
            return;
        }
    }
}

void Zia::setDocumentRoot(QString _documentRoot)
{
    this->documentRoot = _documentRoot;
}

void Zia::modifDocumentRoot(QString _documentRoot)
{
    this->documentRoot = _documentRoot;
}

void Zia::setPort(int _port)
{
    this->port = _port;
}

void Zia::modifPort(int _port)
{
    this->port = _port;
}

int Zia::getPort() const
{
    return (this->port);
}

void Zia::maj()
{
    EcritureDom fichier;
    fichier.maj_fichier(*this);
}

void Zia::addTypeByOne(QString _module, QString _type)
{
    for (int i = 0 ; i < this->modules.size() ; i++)
    {
        if (this->modules[i].getName() == _module)
        {
            for (int j = 0 ; j < this->modules[i].type.size() ; j++)
            {
                if (this->modules[i].type[j] == _type)
                    return;
            }
            this->modules[i].addType(_type);
            EcritureDom fichier;
            fichier.maj_fichier(*this);
        }
    }
}

void Zia::addTypeByList(QString _module, QList<QString> _type)
{
    for (int i = 0 ; i < this->modules.size() ; i++)
    {
        if (this->modules[i].getName() == _module)
        {
            for (int k = 0 ; k < _type.size() ; k++)
            {
                for (int j = 0 ; j < this->modules[i].type.size() ; j++)
                {
                  if (this->modules[i].type[j] == _type[k])
                      return;
                }
                this->modules[i].addType(_type[k]);
            }
        }
    }
}

void Zia::deleteType(QString _module, QString _type)
{
    for (int i = 0 ; i < this->modules.size() ; i++)
    {
        if (this->modules[i].getName() == _module)
        {
            for (int j = 0 ; j < this->modules[i].type.size() ; j++)
            {
                if (this->modules[i].type[j] == _type)
                    this->modules[i].type.removeAt(j);
            }
        }
    }
}

QString Zia::getDocumentRoot() const
{
    return (this->documentRoot);
}

Zia::Zia(const Zia& _zia)
{
    if (this != &_zia)
    {
      this->port = _zia.port;
      this->documentRoot = _zia.documentRoot;
      this->modules = _zia.modules;
    }
}

Zia& Zia::operator=(const Zia& _zia)
{
    this->port = _zia.port;
    this->documentRoot = _zia.documentRoot;
    this->modules = _zia.modules;
    return(*this);
}
