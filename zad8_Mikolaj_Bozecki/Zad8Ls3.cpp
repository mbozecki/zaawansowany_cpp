#include "A.h"
#include <iostream>
#include<string>
#include <vector>
using namespace std;
int main()
{
	string st = "Laurel Laurel";

	A a1(st);
	A a2(a1);

	std::vector<A> vec;
	vec.push_back(A{st});
	vec.push_back(A{"st2"});

	return 0;
}
