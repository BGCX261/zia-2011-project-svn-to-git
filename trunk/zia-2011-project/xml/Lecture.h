#ifndef LECTURE_DOM_HH
#define LECTURE_DOM_HH
#include <xml/zia.h>
#include <QtXml/QDomDocument>
#include <qfile.h>
#include <QIODevice>

class Lecture_DOM : QObject
{
QDomDocument doc;
public:
Lecture_DOM();
static bool ValidityFile();
~Lecture_DOM();
void lire(Zia& proj);
private :
};

#endif // LECTURE_DOM_H
