// esprit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
//#include <SFML/Graphics.hpp> 
#include <sstream>
#include <boost/spirit.hpp>
#include <string>
#include <vector>
#include "syntax.h"
#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "header.h"


int _tmain(int argc, _TCHAR* argv[])
{
	std::string chaine = "GET /avatar/d4f0ced2219f1b2fcae51308dbbea0e7?s=32&d=identicon&r=PG HTTP/2.8\nAccept : text/html";
	header head;
	Syntax syn(head);

	parse_info<string::const_iterator> pInfo = parse(chaine.begin(), chaine.end(), syn);

	std::cout << "methode = "<<head.request.getMethod().c_str() << std::endl;
	std::cout << "ressource = "<<head.request.getRessource().c_str() << std::endl;
	std::cout << "http version = "<<head.request.getHttpVersion() << std::endl;
	std::cout << "type = "<<head.request.getType().c_str() << std::endl;
	std::cout << "version en float = "<<head.request.getVersion() << std::endl;
	std::cout << "accetped type = " << head.request.getAcceptedType() << std::endl;

	while (1);
	return 0;
}

