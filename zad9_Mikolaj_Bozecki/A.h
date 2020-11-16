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
	void copy(const A& a);
	void rcopy(A &&a);
	char * get();
	~A();
};

