Zad8Ls3.exe: Zad8Ls3.obj A.obj
	link /DEBUG /OUT:Zad8Ls3.exe Zad8Ls3.obj A.obj

Zad8Ls3.obj: Zad8Ls3.cpp
	cl /std:c++17 /EHsc /c /Zi /W4 /WX /Zi /Fo:Zad8Ls3.obj Zad8Ls3.cpp

	link /DEBUG /OUT:A.exe A.obj

A.obj: A.cpp A.h
	cl /std:c++17 /EHsc /c /Zi /W4 /WX /Zi /Fo:A.obj A.cpp A.h
