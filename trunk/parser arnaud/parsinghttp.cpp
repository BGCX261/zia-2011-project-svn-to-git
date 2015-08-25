#include "stdafx.h"
#include "parsinghttp.h"

ParsingHttp::ParsingHttp()
{

}

void ParsingHttp::setMessage(string _temp)
{
    this->message = _temp;
}

string ParsingHttp::getMessage()
{
    return(this->message);
}
