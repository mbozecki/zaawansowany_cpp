Zad9.exe: Zad9.obj A.obj
	link /DEBUG /OUT:Zad9.exe Zad9.obj A.obj

Zad9.obj: Zad9.cpp
	cl /std:c++17 /EHsc /c /Zi /W4 /WX /Zi /Fo:Zad9.obj Zad9.cpp

	link /DEBUG /OUT:A.exe A.obj

A.obj: A.cpp A.h
	cl /std:c++17 /EHsc /c /Zi /W4 /WX /Zi /Fo:A.obj A.cpp A.h