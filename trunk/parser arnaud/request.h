#ifndef REQUEST_H
#define REQUEST_H
#include <string>
using namespace std;

class Request
{
public:
    string method;
    string ressource;
    string type;
    string httpVersion;
	string accepted_type;

	string getAcceptedType();
	void setAcceptedType(string);
	float getVersion();
    string getMethod();
    void setMethod(string);
    string getRessource();
    void setRessource(string);
    string getHttpVersion();
    void setHttpVersion(string);
    string getType();
    void setType(string);
    Request();
};

#endif // REQUEST_H
