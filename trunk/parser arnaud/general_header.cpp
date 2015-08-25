#include "stdafx.h"
#include "general_header.h"

GeneralHeader::GeneralHeader()
{

}

void GeneralHeader::setCacheControl(string _temp)
{
    this->cacheControl = _temp;
}

string GeneralHeader::getCacheControl()
{
    return(this->cacheControl);
}

void GeneralHeader::setConnection(string _temp)
{
    this->connection = _temp;
}

string GeneralHeader::getConnection()
{
    return(this->connection);
}

void GeneralHeader::setData(string _temp)
{
    this->data = _temp;
}

string GeneralHeader::getData()
{
    return(this->data);
}

void GeneralHeader::setPragma(string _temp)
{
    this->pragma = _temp;
}

string GeneralHeader::getPragma()
{
    return(this->pragma);
}

void GeneralHeader::setTrailer(string _temp)
{
    this->trailer = _temp;
}

string GeneralHeader::getTrailer()
{
    return(this->trailer);
}

void GeneralHeader::setTransferEncoding(string _temp)
{
    this->transferEncoding = _temp;
}

string GeneralHeader::getTransferEncoding()
{
    return(this->transferEncoding);
}

void GeneralHeader::setUpgrade(string _temp)
{
    this->upgrade = _temp;
}

string GeneralHeader::getUpgrade()
{
    return(this->upgrade);
}

void GeneralHeader::setVia(string _temp)
{
    this->via = _temp;
}

string GeneralHeader::getVia()
{
    return(this->via);
}

void GeneralHeader::setWarning(string _temp)
{
    this->warning = _temp;
}

string GeneralHeader::getWarning()
{
    return(this->warning);
}
