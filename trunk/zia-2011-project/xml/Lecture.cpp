#include "Lecture.h"
#include <xml/zia.h>

Lecture_DOM::Lecture_DOM()
{
QFile file("ziad.xml");
if (!file.open(QIODevice::ReadOnly))
    return;
if (!doc.setContent(&file))
{
    file.close();
    return;
}
file.close();
}

bool Lecture_DOM::ValidityFile()
{
    QString contenuFichier;
    QFile file("ziad.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      return (false);
    else
    {
            contenuFichier = file.readAll();
            file.close();
            if (contenuFichier.lastIndexOf("<?xml version=\"1.0\"?>") == -1)
               return (false);
    }
    return (true);
}

Lecture_DOM::~Lecture_DOM()
{

}

void Lecture_DOM::lire(Zia& proj)
{
QDomNodeList extensionsTab;
QDomNodeList forbiddenTab;
QDomNodeList processTab;
QDomNodeList effectTab;
QDomElement mesure;
QDomElement racine = doc.documentElement();
QDomNode noeud = racine.firstChild();

while(!noeud.isNull())
{
    mesure = noeud.toElement();
    if (mesure.tagName() == "port")
        proj.setPort(mesure.firstChild().toText().data().toInt());
    if (mesure.tagName() == "documentRoot")
        proj.setDocumentRoot(mesure.firstChild().toText().data());
    if (mesure.tagName() == "default-extensions")
    {
        extensionsTab = noeud.childNodes();
        for (unsigned int j = 0 ; j < extensionsTab.length() ; j++)
            if (extensionsTab.item(j).toElement().tagName() == "extension")
                proj.default_extensions.push_back(extensionsTab.item(j).firstChild().toText().data());
    }
    if (mesure.tagName() == "forbidden-path")
    {
        forbiddenTab = noeud.childNodes();
        for (unsigned int j = 0 ; j < forbiddenTab.length() ; j++)
            if (forbiddenTab.item(j).toElement().tagName() == "path")
                proj.forbidden_path.push_back(forbiddenTab.item(j).firstChild().toText().data());
    }
    if (mesure.tagName() == "modules")
    {
        processTab = noeud.childNodes();
        for (unsigned int j = 0 ; j < processTab.length() ; j++)
        {
                Module mod;
                effectTab = processTab.item(j).childNodes();
                for(unsigned int k = 0 ; k < effectTab.length() ; k++)
                {
                    if (effectTab.item(k).toElement().tagName() == "path")
                        mod.setPath(effectTab.item(k).firstChild().toText().data());
                    if (effectTab.item(k).toElement().tagName() == "name")
                        mod.setName(effectTab.item(k).firstChild().toText().data());
                    if (effectTab.item(k).toElement().tagName() == "type")
                        mod.addType(effectTab.item(k).firstChild().toText().data());
                }
                proj.modules.push_back(mod);
        }
    }
    noeud = noeud.nextSibling();
}
}
