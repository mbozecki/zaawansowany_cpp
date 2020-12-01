#include <stdio.h>
#include <time.h>
#include <omp.h>
int main()
{
	const int N = 1000000000;
	int i = 0;
	double sum = 0;
	clock_t t0 = clock();

#pragma omp parallel for private(i) reduction(+:sum) //num_threads(8)
	for (i = N - 1; i >= 0; --i)
	{
		sum += 1.0 / (i + 1.0);
	}

	clock_t t1 = clock();
	printf("s = %g\n", sum);
	printf("t = %g\n", ((double)t1 - t0) / CLOCKS_PER_SEC);
}

//uzycie wersji rownoleglej przyspiesza caly program o okolo 6-7 razy w porownaniu do szeregowej

//num threads 1 -> 5,74s ; s=18,08
//2 -> 2,93s ; s=18,87
//4 -> 1,44s ; s=19,0267
//8 (MAX) -> 0,92s ; s=19,4017

//Aby wychodzil zawsze poprawny wynik, nalezy zamienic FLOAT sum na DOUBLE sum

//Czas z funkcji clock() zwraca liczbę cykli, które uplynely od chwili uruchomienia programu, nie liczy on zwykłego czasu (wall clock)
