#pragma once
#include <string>
class A
{
	char* ch;
public:
	A();
	A(const std::string &s);
	A(const A& a);
	A& operator=(const A& a);
	char * get();
	~A();
};

