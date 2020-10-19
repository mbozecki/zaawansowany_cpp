#include "Wektor.h"
#include <iostream>


template <typename T1, int T2>
Wektor<T1,T2>::Wektor()
{
	for (int i = 0; i < T2; i++)
	{
		tab[i] = 0;
	}
}

template <typename T1, int T2>
T1& Wektor<T1,T2>::operator [](int num)
{
	if (num < T2)
	{
		return tab[num];
	}
	else
	{
		std::cout << "Odwolanie poza tablice";
		exit(0);
	}
}

template <typename T1, int T2>
T1 Wektor<T1,T2>::operator *(const std::vector<T1>& v)
{
	if (T2 != 2 || v.size() != 2)
	{
		throw ("Zla ilosc elementow!");
	}
	else
	{
		return ((tab[0] * v[0]) + (tab[1] * v[1]));
	}

}