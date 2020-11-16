#include "A.h"
#include <iostream>
#include<string>
using namespace std;
int main()
{
	string st = "Laurel Laurel";

	A *test= new A(st);
	cout << test->get() << endl;

	//A kopia(*test);
	//cout << kopia.get() << endl;

	A* kopia1 = new A(*test);
	cout << kopia1->get() << endl;

	A rowna = *kopia1;
	cout << rowna.get() << endl;


	//A *rowna = &kopia;
	//cout << rowna->get() << endl;
}
