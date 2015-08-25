#ifndef ENTITYHEADER_H
#define ENTITYHEADER_H
#include <string>
using namespace std;

class EntityHeader
{
string allow;
string contentEnconding;
string contentLanguage;
string contentLenght;
string contentLocation;
string contentMD5;
string contentRange;
string contentType;
string Expires;
string lastModified;
string extensionHeader;
public:
    EntityHeader();
    string getAllow();
    void setAllow(string);
    string getContentEncoding();
    void setContentEncoding(string);
    string getContentLanguage();
    void setContentLanguage(string);
    string getContentLenght();
    void setContentLenght(string);
    string getContentLocation();
    void setContentLocation(string);
    string getContentMD5();
    void setContentMD5(string);
    string getContentRange();
    void setContentRange(string);
    string getContentType();
    void setContentType(string);
    string getExpires();
    void setExpires(string);
    string getLastModified();
    void setLastModified(string);
    string getExtensionHeader();
    void setExtensionHeader(string);
};

#endif // ENTITYHEADER_H
