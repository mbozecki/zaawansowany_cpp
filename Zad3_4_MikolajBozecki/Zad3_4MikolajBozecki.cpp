//Zadanie 3 i 4 lista 2 Mikołaj Bożęcki

#include <iostream>
#include <vector>
#include "Wektor.h"
#include "Wektor.cpp"
using namespace std;


int main()
{
	Wektor<int,10>W;

	cout << W[3] << endl;
	W[3] = 4;
	cout << W[3] << endl;

	Wektor <int, 2>W1;
	W1[0] = 5;
	W1[1] = 10;
	vector<int> V;
	V.push_back(2);
	V.push_back(8);
	cout << W1 * V << endl;

}
