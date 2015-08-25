#ifndef REQUESTHEADER_H
#define REQUESTHEADER_H
#include <string>
using namespace std;

class RequestHeader
{
    string accept;
    string acceptCharset;
    string acceptEncoding;
    string acceptLanguage;
    string authorization;
    string expect;
    string from;
    string host;
    string ifMatch;
    string ifModifiedSince;
    string ifNoneMatch;
    string ifRange;
    string ifUnmodifiedSince;
    string maxForwards;
    string proxyAuthorization;
    string range;
    string referer;
    string te;
    string userAgent;
public:
    RequestHeader();
    string getAccept();
    void setAccept(string);
    string getAcceptCharset();
    void setAcceptCharset(string);
    string getAcceptEncoding();
    void setAcceptEncoding(string);
    string getAcceptLanguage();
    void setAcceptLanguage(string);
    string getAuthorization();
    void setAuthorization(string);
    string getExpect();
    void setExpect(string);
    string getFrom();
    void setFrom(string);
    string getHost();
    void setHost(string);
    string getIfMatch();
    void setIfMatch(string);
    string getIfModifiedSince();
    void setIfModifiedSince(string);
    string getIfNoneMatch();
    void setIfNoneMatch(string);
    string getIfRange();
    void setIfRange(string);
    string getIfUnmodifiedSince();
    void setIfUnmodifiedSince(string);
    string getMaxForwards();
    void setMaxForwards(string);
    string getProxyAuthorization();
    void setProxyAuthorization(string);
    string getRange();
    void setRange(string);
    string getReferer();
    void setReferer(string);
    string getTe();
    void setTe(string);
    string getUserAgent();
    void setUserAgent(string);
};

#endif // REQUESTHEADER_H
