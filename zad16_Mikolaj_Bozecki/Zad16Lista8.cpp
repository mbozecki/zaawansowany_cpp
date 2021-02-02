#include <iostream>
#include "ZbiornikPaliwa.h"
#include "Silnik.h"
using namespace std;
int main()
{
	Silnik silnik1(5, 2); //pięć jednostek paliwa co dwie sekundy,
	Silnik silnik2(1, 1); //jedna jednostka paliwa co sekundę,
	Silnik silnik3(2, 3); //dwie jednostki paliwa co trzy sekundy
	
	for (int i = 0; i < 10; i++)
	{
		int tmp = rand() % (20 - 10) + 10; //rand z min 10
		shared_ptr<ZbiornikPaliwa> zbiornik =make_shared<ZbiornikPaliwa>(tmp);	
		cout << "Podlaczono zbiornik " << i + 1 << " o pojemnosci " << tmp << endl;
		silnik1.dolacz(zbiornik);
		silnik2.dolacz(zbiornik);
		silnik3.dolacz(zbiornik);
	}

	return 0;
}
