#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <iostream>
#include <stdint.h>


// 64 bitowy generator pseudolosowy
//---------------------------------
long long int Losuj(long long int a, long long int b)
{
	long long int w = rand();
	int i;

	for (i = 1; i <= 8; i++)
	{
		w = w << 8;
		w |= rand();
	}
	return a + (w % (b - a));
}
long long int euler(long long int p, long long int q)
{
	return (p - 1)*(q - 1);
}

long long int modul(long long int p, long long int q)
{
	return p * q;
}

long long int nwd(long long int e, long long int euler)
{
	long long int t;
	while (euler = !0)
	{
		t = euler;
		euler = e % euler;
		e = t;
	}

	return e;
}

long long int wykladnik_e(long long int euler, long long int modul)
{
	long long int e;
	for (e = 3; nwd(e, euler) != 1; e += 2);
}
int main()
{
	long long int x;
	time_t tt;
	x = time(&tt);
	long long int a;
	a = Losuj(rand(), x);
	printf("%llu", a);
	printf("Hello world!\n");
	return 0;
}
