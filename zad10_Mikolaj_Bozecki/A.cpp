#include "A.h"
#include <iostream>
#include <string>
A::A()
{
	std::cout << "A:A()";
}
A::A(const std::string& s)
{
	std::cout << "konstruktor const string &s" << std::endl;
	len = s.length();
	ch = new char[len + 1];
	s.copy(ch, len + 1);
	ch[len] = '\0';

}
A::A(const A& a) //konstruktor kopiujacy
{
	len = a.len;
	ch = new char[len + 1];
	std::memcpy(ch, a.ch, len + 1);
	std::cout << "wywolano konstruktor kopiujacy" << std::endl;
	
}
A::A(A&& a)//konstruktor przenoszacy
{
	len = a.len;
	ch = a.ch;
	a.ch = nullptr;
	std::cout << "wywolano konstruktor przenoszacy" << std::endl;
}
const char* A::get() const
{
	return ch;
}
A::~A()
{
	std::cout << "destruktor wywolany!" << std::endl;
	delete[] ch;
}
