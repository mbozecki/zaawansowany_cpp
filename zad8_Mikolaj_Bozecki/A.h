#pragma once
#include <string>
class A
{
	char* ch;
	size_t len;
public:
	A();
	A(const std::string& s);
	A(const A& a);
	A(A&& a);
	const char* get() const;
	~A();
};

