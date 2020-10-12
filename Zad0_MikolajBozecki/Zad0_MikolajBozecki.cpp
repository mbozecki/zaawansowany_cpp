//Zadanie 0 Mikolaj Bozecki

#include <iostream>
class Bazowa 
{
public:
	void wypisz_zwykle()
	{
		std::cout << "Wypisz zwykle z bazowej\n";
	};
	virtual void wypisz_wirtualne()
	{
		std::cout << "Wypisz wirtualne z bazowej\n";
	}
};

class Pochodna : public Bazowa
{
public:
	void wypisz_zwykle()
	{
		std::cout << "Wypisz zwykle z pochodnej\n";
	};
	virtual void wypisz_wirtualne()
	{
		std::cout << "Wypisz wirtualne z pochodnej\n";
	}
};


int main()
	{
	Bazowa Baz;
	Pochodna Poc;

	Baz.wypisz_zwykle();
	Baz.wypisz_wirtualne();

	Poc.wypisz_zwykle();
	Poc.wypisz_wirtualne();

	std::cout << "Roznica, ktora nas interesuje zachodzi podczas rzutowania w gore: \n";
	Bazowa *ptr = &Poc;
	ptr->wypisz_zwykle(); //zostaje wywolana metoda klasy bazowej
	ptr->wypisz_wirtualne(); //zostaje wywolana metoda klasy pochodnej
	std::cout << "Jak widac w ostatniej linijce, dzieki uzyciu metody wirtualnej bedzie wywolywana wersja odpowiadajaca rzeczywistemu typowi (czyli klasy, a nie wskaznika)";
	return 0;
}