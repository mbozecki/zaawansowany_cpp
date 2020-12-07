#include "A.h"
#include <iostream>
#include<string>
#include <vector>
using namespace std;

template <typename T>
const A copy(T&& a) {
	if (std::is_rvalue_reference<decltype(a)>::value)
	{
		A a1= std::move(a);
		return a1;
	}
	else
	{
		A a1(a);
		return a1;
	}
}

int main()
{
	string st = "Laurel Laurel";

	A a1(st);
	cout << a1.get() << endl;
	A a2=copy(a1);
	cout << a2.get() << endl;
	A a3 = copy(A("Yanny"));
	cout << a3.get() << endl;
	

	return 0;
}
