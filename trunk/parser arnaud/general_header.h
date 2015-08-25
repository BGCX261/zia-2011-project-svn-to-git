#ifndef GENERALHEADER_H
#define GENERALHEADER_H
#include <string>
using namespace std;

class GeneralHeader
{
    string cacheControl;
    string connection;
    string data;
    string pragma;
    string trailer;
    string transferEncoding;
    string upgrade;
    string via;
    string warning;

public:
    GeneralHeader();
    void setCacheControl(string);
    string getCacheControl();
    void setConnection(string);
    string getConnection();
    void setData(string);
    string getData();
    void setPragma(string);
    string getPragma();
    void setTrailer(string);
    string getTrailer();
    void setTransferEncoding(string);
    string getTransferEncoding();
    void setUpgrade(string);
    string getUpgrade();
    void setVia(string);
    string getVia();
    void setWarning(string);
    string getWarning();
};

#endif // GENERALHEADER_H
