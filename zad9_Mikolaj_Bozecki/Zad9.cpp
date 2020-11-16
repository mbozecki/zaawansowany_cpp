#include "A.h"
#include <iostream>
#include<string>
using namespace std;
int main()
{

	string st2 = "tekst docelowy";
	A *a1 = new A(st2);
	A *b1 = new A();
	b1->copy(*a1);
	cout << a1->get() << endl;
	cout << b1->get() << endl;

	A *c1 = new A();
	c1->rcopy( A("h"));
	cout << c1->get() << endl;

	//A *rowna = &kopia;
	//cout << rowna->get() << endl;
}
