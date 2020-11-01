#pragma once
#include <vector>

// PB: Typ T2 nie powinien pozwalać na ujemne wartośći, najlepiej użyć std::size_t
template <typename T1, int T2>
class Wektor
{
	typedef T1 value_type;
	T1 tab[T2];
public:
	Wektor();

	// PB: Brak drugiego operatora indeksowania - do pobierania składowych z niemodyfikowalnych obiektów
	T1& operator [](int num);
	T1 operator *(const std::vector<T1>& v);
};