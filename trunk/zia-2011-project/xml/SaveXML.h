#ifndef SAVEXML_H
#define SAVEXML_H
#include "QObject"
#include <Qt/qdom.h>
#include "QFile"
#include "QTextStream"
#include "zia.h"

class EcritureDom : public QObject
{
Q_OBJECT
public:
EcritureDom();
~EcritureDom();
public slots :
void maj_fichier(Zia& proj);
private :
QDomDocument doc;
QDomElement mesures;
QFile file;
QTextStream out;
};

#endif // SAVEXML_H
