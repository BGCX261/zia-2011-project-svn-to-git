#include "stdafx.h"
#include "requestheader.h"

RequestHeader::RequestHeader()
{

}

string RequestHeader::getAccept()
{
    return(this->accept);
}

void RequestHeader::setAccept(string _temp)
{
    this->accept = _temp;
}

string RequestHeader::getAcceptCharset()
{
    return(this->acceptCharset);
}

void RequestHeader::setAcceptCharset(string _temp)
{
    this->acceptCharset = _temp;
}

string RequestHeader::getAcceptEncoding()
{
    return(this->acceptEncoding);
}

void RequestHeader::setAcceptEncoding(string _temp)
{
    this->acceptEncoding = _temp;
}

string RequestHeader::getAcceptLanguage()
{
    return(this->acceptLanguage);
}

void RequestHeader::setAcceptLanguage(string _temp)
{
    this->acceptLanguage = _temp;
}

string RequestHeader::getAuthorization()
{
    return(this->authorization);
}

void RequestHeader::setAuthorization(string _temp)
{
    this->authorization = _temp;
}

string RequestHeader::getExpect()
{
    return(this->expect);
}

void RequestHeader::setExpect(string _temp)
{
    this->expect = _temp;
}

string RequestHeader::getFrom()
{
    return(this->from);
}

void RequestHeader::setFrom(string _temp)
{
    this->from = _temp;
}

string RequestHeader::getHost()
{
    return(this->host);
}

void RequestHeader::setHost(string _temp)
{
    this->host = _temp;
}

string RequestHeader::getIfMatch()
{
    return(this->ifMatch);
}

void RequestHeader::setIfMatch(string _temp)
{
    this->ifMatch = _temp;
}

string RequestHeader::getIfModifiedSince()
{
    return(this->ifModifiedSince);
}

void RequestHeader::setIfModifiedSince(string _temp)
{
    this->ifModifiedSince = _temp;
}

string RequestHeader::getIfNoneMatch()
{
    return(this->ifNoneMatch);
}

void RequestHeader::setIfNoneMatch(string _temp)
{
    this->ifNoneMatch = _temp;
}

string RequestHeader::getIfRange()
{
    return(this->ifRange);
}

void RequestHeader::setIfRange(string _temp)
{
    this->ifRange = _temp;
}

string RequestHeader::getIfUnmodifiedSince()
{
    return(this->ifUnmodifiedSince);
}

void RequestHeader::setIfUnmodifiedSince(string _temp)
{
    this->ifUnmodifiedSince = _temp;
}

string RequestHeader::getMaxForwards()
{
    return(this->maxForwards);
}

void RequestHeader::setMaxForwards(string _temp)
{
    this->maxForwards = _temp;
}

string RequestHeader::getProxyAuthorization()
{
    return(this->proxyAuthorization);
}

void RequestHeader::setProxyAuthorization(string _temp)
{
    this->proxyAuthorization = _temp;
}

string RequestHeader::getRange()
{
    return(this->range);
}

void RequestHeader::setRange(string _temp)
{
    this->range = _temp;
}

string RequestHeader::getReferer()
{
    return(this->referer);
}

void RequestHeader::setReferer(string _temp)
{
    this->referer = _temp;
}

string RequestHeader::getTe()
{
    return(this->te);
}

void RequestHeader::setTe(string _temp)
{
    this->te = _temp;
}

string RequestHeader::getUserAgent()
{
    return(this->userAgent);
}

void RequestHeader::setUserAgent(string _temp)
{
    this->userAgent = _temp;
}
