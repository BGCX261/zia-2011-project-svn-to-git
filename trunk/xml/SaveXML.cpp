#include "SaveXML.h"
#include "zia.h"

EcritureDom::EcritureDom()
{
mesures = doc.createElement("zia");
doc.appendChild(mesures);
file.setFileName("ziad.xml");
if (!file.open(QIODevice::WriteOnly))
return;
out.setDevice(&file);
}

 void EcritureDom::maj_fichier(Zia& proj)
 {
     int i;
     QDomElement documentRoot = doc.createElement("documentRoot");
     mesures.appendChild(documentRoot);
     QDomText t1 = doc.createTextNode(proj.getDocumentRoot());
     documentRoot.appendChild(t1);

     QDomElement port = doc.createElement("port");
     mesures.appendChild(port);
     QDomText t2 = doc.createTextNode(QString::number(proj.getPort()));
     port.appendChild(t2);

     if (proj.default_extensions.size() > 0)
     {
        QDomElement extensions = doc.createElement("default-extensions");
         mesures.appendChild(extensions);
        for (int i = 0 ; i < proj.default_extensions.size() ; i++)
        {
           QDomElement extension = doc.createElement("extension");
           extensions.appendChild(extension);
           QDomText f1 = doc.createTextNode(proj.default_extensions[i]);
           extension.appendChild(f1);
        }
     }

     if (proj.forbidden_path.size() > 0)
     {
        QDomElement forbidden = doc.createElement("forbidden-path");
         mesures.appendChild(forbidden);
         for (int i = 0 ; i < proj.forbidden_path.size() ; i++)
         {
            QDomElement path = doc.createElement("path");
            forbidden.appendChild(path);
            QDomText f1 = doc.createTextNode(proj.forbidden_path[i]);
            path.appendChild(f1);
         }
     }
     if (proj.modules.size() > 0)
     {
        QDomElement modules = doc.createElement("modules");
         mesures.appendChild(modules);
        for (i = 0 ; i < proj.modules.size() ; i++)
        {
         QDomElement module = doc.createElement("module");
         modules.appendChild(module);

         QDomElement name = doc.createElement("name");
         module.appendChild(name);
         QDomText f1 = doc.createTextNode(proj.modules[i].getName());
         name.appendChild(f1);

         QDomElement path = doc.createElement("path");
         module.appendChild(path);
         QDomText f2 = doc.createTextNode(proj.modules[i].getPath());
         path.appendChild(f2);
         for (int j = 0 ; j < proj.modules[i].type.size() ; j++)
         {
             QDomElement type = doc.createElement("type");
             module.appendChild(type);
             QDomText f3 = doc.createTextNode(proj.modules[i].type[j]);
             type.appendChild(f3);
         }
        }
     }
}

EcritureDom::~EcritureDom()
    {
    QDomNode noeud = doc.createProcessingInstruction("xml","version=\"1.0\"");
    doc.insertBefore(noeud,doc.firstChild());
    doc.save(out,2);
    file.close();
}

