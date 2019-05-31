long long int euler(long long int p, long long int q) 
{
	return (p - 1)*(q - 1);
}

long long int modu³(long long int p, long long int q) 
{
	return p * q;
}

long long int nwd(long long int e, long long int euler) 
{
	long long int t;
	while (euler =!0)
	{
		t = euler;
		euler = e % euler;
		e = t;
	}
	
	return e;
}

long long int wykladnik_e(long long int euler, long long int modul )
{
	long long int e;
	for (e = 3; nwd(e, euler) != 1; e += 2);
}

