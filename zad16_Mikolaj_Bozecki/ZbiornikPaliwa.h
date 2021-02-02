#pragma once
#include <mutex>
class ZbiornikPaliwa
{
	unsigned int ilosc = 0;
	std::mutex paliwo_mutex;
public:
	ZbiornikPaliwa(unsigned int ilosc);
	unsigned int Pobierz(unsigned int ile_pobrac);
};

