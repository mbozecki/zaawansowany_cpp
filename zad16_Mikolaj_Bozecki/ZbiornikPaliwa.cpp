#include "ZbiornikPaliwa.h"

ZbiornikPaliwa::ZbiornikPaliwa(unsigned int ilosc)
{
	this->ilosc = ilosc;
	
}

unsigned int ZbiornikPaliwa::Pobierz(unsigned int ile_pobrac)
{
	std::lock_guard<std::mutex> lock(paliwo_mutex);
	if (ile_pobrac > ilosc) return 0;
	ilosc-=ile_pobrac;
	return ile_pobrac;
}
