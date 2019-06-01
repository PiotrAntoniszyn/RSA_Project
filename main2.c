#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <iostream>
#include <stdint.h>
#include <stdbool.h>

typedef unsigned long long duza;
// 64 bitowy generator pseudolosowy
//---------------------------------
duza Losuj(duza a,duza b)
{
  duza w;
  int i;

  for(i = 1; i <= 8; i++)
  {
    w <<= 8;
    w |= rand() % 256;
  }
  return a + (w % (b - a));
}
duza randGen(duza a, duza b)
{
	duza w;
	int i;

	for (i = 1; i <= 8; i++)
	{
		w = w << 8;
		w |= rand();
	}
	return a + (w % (b - a));
}
// Funkcja mno¿y a i b mod n
//--------------------------
duza MnozModulo(duza a, duza b, duza n)
{
  duza m,w;

  w = 0;
  for(m = 1; m; m <<= 1)
  {
    if(b & m) w = (w + a) % n;
    a = (a << 1) % n;
  }
  return w;
}

// Funkcja oblicza a^e mod n
//--------------------------
duza PotegujModulo(duza a, duza e, duza n)
{
  duza m,p,w;

  p = a; w = 1;
  for(m = 1; m; m <<= 1)
  {
    if(e & m) w = MnozModulo(w,p,n);
    p = MnozModulo(p,p,n);
  }
  return w;
}

void RMTest()
{   bool t;
    int flag;
    do{
        duza a,d,p,x;
        int i,j,s,n;
        flag=1;
        duza w;
        time_t tt;

        do
        {
            w = rand()+1231412124123123213;
            p = randGen(rand(),w);
        }while(p%2==0);
        n=20;
        s = 0;
        for(d=p-1;d%2==0;s++) d/=2;
        for(i=0;i<n;i++)
        {
            a= Losuj(2,p-2);
            x = PotegujModulo(a,d,p);
            if((x==1)||(x==p-1))continue;
            for(j=1;(j<s)&& (x!=p-1);j++)
            {
                x = MnozModulo(x,x,p);
                if(x==1)
                {
                    flag=0;break;
                }
            }
            if(flag==0)break;
            if(x!=p-1)
            {
                flag=0;break;
            }
        }

        printf("%llu",p);
        printf("\n");
        if(flag==1) printf("Liczba jest pierwsza");
        if(flag==0) printf("Liczba nie jest pierwsza");
        printf("\n");
    }while(flag==0);

}

duza euler(duza p, duza q)
{
	return (p - 1)*(q - 1);
}

duza modul(duza p, duza q)
{
	return p * q;
}

duza nwd(duza e, duza euler)
{
	duza t;
	while (euler = !0)
	{
		t = euler;
		euler = e % euler;
		e = t;
	}

	return e;
}

duza wykladnik_e(duza euler, duza modul)
{
	duza e;
	for (e = 3; nwd(e, euler) != 1; e += 2);
}
int main()
{
	RMTest();
	return 0;
}
