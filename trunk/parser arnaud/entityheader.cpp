#include "stdafx.h"
#include "entityheader.h"

EntityHeader::EntityHeader()
{

}

string EntityHeader::getAllow()
{
    return(this->allow);
}

void EntityHeader::setAllow(string _temp)
{
    this->allow = _temp;
}

string EntityHeader::getContentEncoding()
{
    return(this->contentEnconding);
}

void EntityHeader::setContentEncoding(string _temp)
{
    this->contentEnconding = _temp;
}

string EntityHeader::getContentLanguage()
{
    return(this->contentLanguage);
}

void EntityHeader::setContentLanguage(string _temp)
{
    this->contentLanguage = _temp;
}

string EntityHeader::getContentLenght()
{
    return(this->contentLenght);
}

void EntityHeader::setContentLenght(string _temp)
{
    this->contentLenght = _temp;
}

string EntityHeader::getContentLocation()
{
    return(this->contentLocation);
}

void EntityHeader::setContentLocation(string _temp)
{
    this->contentLocation = _temp;
}

string EntityHeader::getContentMD5()
{
    return(this->contentMD5);
}

void EntityHeader::setContentMD5(string _temp)
{
    this->contentMD5 = _temp;
}

string EntityHeader::getContentRange()
{
    return(this->contentRange);
}

void EntityHeader::setContentRange(string _temp)
{
    this->contentRange = _temp;
}

string EntityHeader::getContentType()
{
    return(this->contentType);
}

void EntityHeader::setContentType(string _temp)
{
    this->contentType = _temp;
}

string EntityHeader::getExpires()
{
    return(this->Expires);
}

void EntityHeader::setExpires(string _temp)
{
    this->Expires = _temp;
}

string EntityHeader::getLastModified()
{
    return(this->lastModified);
}

void EntityHeader::setLastModified(string _temp)
{
    this->lastModified = _temp;
}

string EntityHeader::getExtensionHeader()
{
    return(this->extensionHeader);
}

void EntityHeader::setExtensionHeader(string _temp)
{
    this->extensionHeader = _temp;
}
