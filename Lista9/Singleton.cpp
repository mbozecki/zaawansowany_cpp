#include "Singleton.h"
#include <iostream>

Singleton::Singleton() {
	std::cout << &classinstance << " +" << std::endl;
}
Singleton* Singleton::instance()
{
	if (classinstance == 0)
	{
		classinstance = new Singleton();
	}

	return classinstance;
}

void Singleton::calls()
{
	callsnum++;
	std::cout << &classinstance <<", calls wywolano po raz: " << callsnum << std::endl;
}

Singleton::~Singleton() {
	std::cout << &classinstance << "-" << std::endl;
}
int Singleton::callsnum = 0;
Singleton* Singleton::classinstance = 0;