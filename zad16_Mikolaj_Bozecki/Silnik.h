#pragma once
#include <vector>
#include <thread>
#include "ZbiornikPaliwa.h"
#include <chrono>
using namespace std;
class Silnik
{
	unsigned int interwal;
	unsigned int ilosc_paliwa;
	thread th;
	mutex zbiorniki_mtx;
	vector<shared_ptr<ZbiornikPaliwa>> zbiorniki_paliwa;
	void praca();
public:
	Silnik(unsigned int interwal, unsigned int ilosc_paliwa);
	void dolacz(shared_ptr<ZbiornikPaliwa> zbiornik);
	void pobierz_paliwo(unsigned int ile_pobrac);
	~Silnik();
};

