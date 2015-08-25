#ifndef PARSINGHTTP_H
#define PARSINGHTTP_H
#include <string>
using namespace std;

class ParsingHttp
{
    string message;
public:
    ParsingHttp();
    void parser();
    void setMessage(string);
    string getMessage();
};

#endif // PARSINGHTTP_H
