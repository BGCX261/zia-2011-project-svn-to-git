#include "module.h"

Module::Module()
{

}

void Module::setName(QString _name)
{
    this->name = _name;
}

void Module::setPath(QString _path)
{
    this->path = _path;
}

QString Module::getName() const
{
    return (this->name);
}

QString Module::getPath() const
{
    return (this->path);
}

Module::Module(const Module& _module)
{
    if (this != &_module)
    {
      this->path = _module.path;
      this->name = _module.name;
      this->type = _module.type;
    }
}

Module& Module::operator=(const Module& _module)
{
    this->path = _module.path;
    this->name = _module.name;
    this->type = _module.type;
    return (*this);
}

void Module::addType(QString _type)
{
    int i;

    for (i = 0 ; i < this->type.size() ; i++)
    {
        if (this->type[i] == _type)
            return;
    }
    this->type.push_back(_type);
}
