#pragma once
#include <vector>
template <typename T1, int T2>
class Wektor
{
	typedef T1 value_type;
	T1 tab[T2];
public:
	Wektor();
	T1& operator [](int num);
	T1 operator *(const std::vector<T1>& v);
};