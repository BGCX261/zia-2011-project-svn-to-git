#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "request.h"

Request::Request()
{

}

string Request::getMethod()
{
    return(this->method);
}

void Request::setMethod(string _temp)
{
    this->method = _temp;
}

string Request::getRessource()
{
    return(this->ressource);
}

void Request::setRessource(string _temp)
{
    this->ressource = _temp;
}

string Request::getHttpVersion()
{
    return(this->httpVersion);
}

void Request::setHttpVersion(string _temp)
{
    this->httpVersion = _temp;
}

string Request::getType()
{
    return(this->type);
}

void Request::setType(string _temp)
{
    this->type = _temp;
}

float	Request::getVersion()
{
	string version = httpVersion.substr(5, httpVersion.size());
	istringstream ss(version);
	float v;

	ss >> v;
	return (v);
}

string	Request::getAcceptedType()
{
return (this->accepted_type);
}

void	Request::setAcceptedType(string _temp)
{
	this->accepted_type = _temp;
}