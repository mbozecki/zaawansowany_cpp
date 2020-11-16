#include "A.h"
#include <iostream>
#include <string>
A::A()
{
	//char* ch = NULL;
	std::cout << "A:A()";
}
A::A(const std::string &s)
{
	std::cout << "konstruktor const string &s" << std::endl;
	//ch = new char[sizeof s.size()];
	//strcpy(ch, s.c_str());
	ch = new char[s.size()+1];
	s.copy(ch, s.size() + 1);
	ch[s.size()] = '\0';

}
A::A(const A& a)
{
	std::cout << "konstruktor kopiujacy" << std::endl;
	ch = a.ch;
}
A& A::operator=(const A& a)
{
	std::cout << "operator =" << std::endl;
	ch = a.ch;
	return *this;
}
char *A::get()
{
	return ch;
}
A::~A()
{
	if (ch != NULL)
	{
		delete ch;
		std::cout << "destruktor wywolany!" << std::endl;
	}
	
	
}

void A::copy(const A& a)
{
	std::cout << "copy" << std::endl;
	ch = a.ch;
}

void A::rcopy(A&& a)
{
	std::cout << "rcopy" << std::endl;
	ch = std::move(a.ch);

}