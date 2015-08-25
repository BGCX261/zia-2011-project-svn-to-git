#include "stdafx.h"
#include "match.h"
#include <iostream>

my_match::my_match(){
}

my_match::~my_match(){
}

void	my_match::match_method(std::string command)
{
	unsigned int i;
	std::string com[5]={"Get","Put","Delete","Post","Head"};
	bool ok = false;

	
	for (i = 0; i < 5; i++) {
		if (com[i].compare(command) == 0) {
			ok = true;
			break;
		}
	}
	
	if (ok) {
		switch (i) {
		case Get:
			Getmethod ();
			break;
		case Put:
			Putmethod ();
			break;
		case Delete:
			Deletemethod ();
			break;
		case Post:
			Postmethod ();
			break;
		case Head:
			Headmethod();
			break;
		default:
			std::cout << "Invalid method" << std::endl;
			break;
		}
	}else{
		std::cout << ("Unknown or invalid command\n") << std::endl;
	}

}

void	my_match::Getmethod()
{
	std::cout << "Method Get"<< std::endl;
}

void	my_match::Putmethod()
{
	std::cout << "Method Put"<< std::endl;
}

void	my_match::Deletemethod()
{
	std::cout << "Method Delete"<< std::endl;
}

void	my_match::Postmethod()
{
	std::cout << "Method Post"<< std::endl;
}

void	my_match::Headmethod()
{
	std::cout << "Method Head" << std::endl;
}