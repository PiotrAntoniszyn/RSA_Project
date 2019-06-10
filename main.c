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

duza RMTest()
{
    srand(time(NULL));
    int flag;
    do{
        duza a,d,p,x;
        int i,j,s,n;
        flag=1;
        duza w;

        do
        {
            while(w<100000000000)
            {
                w = rand();
            }

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


        if(flag==1)
        {
            printf("Liczba jest pierwsza: ");
            return p;
        }
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
	while (euler != 0)
	{
		t = euler;
		euler = e % euler;
		e = t;
	}

	return e;
}
duza odwModulo(duza e, duza euler)
{
    duza u = 1;
    duza x = 0;
    duza w = e;
    duza z = euler;
    duza q;
    while(w)
    {

        if(w<z)
        {
            q = u;
            u = x;
            x = q;
            q = w;
            w = z;
            z = q;
        }
        q = w / z;
        u = u - (q*x);
        w = w - (q*z);
        if(z == 1)
        {
            if(x < 0) x += euler;

            return x;
        }
        //else printf("BRAK");
    }

}
duza wykladnik_e(duza euler, duza e, duza modul)
{
    e=3;
	for(e = 3; (nwd(e,euler) != 1) && (e<modul); e += 2)
    {
        printf("%llu\n",e);
    }
    return e;


}



int main()
{
    duza p,q,e,m,n,d;
    duza tmp;
    duza x;
	p = RMTest();
    printf("p: %llu\n",p);
	q = RMTest();
	printf("q: %llu\n",q);

    m = euler(p,q);
	printf("%llu\n",m);

    n = modul(p,q);
	printf("%llu\n",n);

    e = wykladnik_e(m,e,n);

    d = odwModulo(e,m);

	printf("%llu\n",d);

	printf("Klucz publiczny: (%llu, %llu)\n",e,n);
	printf("Klucz tajny: (%llu, %llu)\n",d,n);


	return 0;
}
