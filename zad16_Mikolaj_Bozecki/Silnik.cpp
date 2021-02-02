#include "Silnik.h"
#include <iostream>

Silnik::Silnik(unsigned int interwal, unsigned int ilosc_paliwa)
{
	this->interwal =interwal;
	this->ilosc_paliwa = ilosc_paliwa;
	th= thread(&Silnik::praca, this);
	
}

void Silnik::dolacz(shared_ptr<ZbiornikPaliwa> zbiornik)
{
	lock_guard<mutex> lock(zbiorniki_mtx);
	zbiorniki_paliwa.push_back(move(zbiornik));

}

void Silnik::praca()
{

	this_thread::sleep_for(chrono::seconds(interwal));		
	unique_lock<mutex> zbiorniki_lock(zbiorniki_mtx);

	while (zbiorniki_paliwa.size())
	{
		unsigned int pozostalo_paliwa = zbiorniki_paliwa[0]->Pobierz(ilosc_paliwa);

		if (pozostalo_paliwa == 0)
		{
			zbiorniki_paliwa.erase(zbiorniki_paliwa.begin());
			cout << "Pozostalo " << zbiorniki_paliwa.size() + 1 << " zbiornikow paliwa" << endl;
			cout << "Z paliwa skorzystal silnik: " << this_thread::get_id() << endl;

			if (zbiorniki_paliwa.size() != 0)
			{
				pozostalo_paliwa = zbiorniki_paliwa[0]->Pobierz(ilosc_paliwa);
			}
		}

		zbiorniki_lock.unlock();
		this_thread::sleep_for(chrono::seconds(interwal));
		zbiorniki_lock.lock();
	}
}

void Silnik::pobierz_paliwo(unsigned int ile_pobrac)
{
	if (zbiorniki_paliwa.size() == 0)
	{
		cout << "Zbiornik pusty" << endl;
	}
	else if (zbiorniki_paliwa[zbiorniki_paliwa.size() - 1]->Pobierz(ile_pobrac) == 0) {
			zbiorniki_paliwa.pop_back();
	}
}

Silnik::~Silnik() {
	th.join();
}
