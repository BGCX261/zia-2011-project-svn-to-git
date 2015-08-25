#ifndef _MATCH_H_
#define _MATCH_H_
#include <iostream>

class my_match
{
public:
	my_match();
	~my_match();
	void match_method(std::string parse_methode);

	void	Getmethod();
	void	Putmethod();
	void	Deletemethod();
	void	Postmethod();
	void	Headmethod();

protected:
private:
	enum commands { Get, Put, Delete, Post, Head};
};

#endif //_MATCH_H_