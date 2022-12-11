Napišite program, poštujući sve faze procesa programiranja,
koji će ispisati sve troznamenkaste brojeve koji su jednaki sumi faktorijela svojih znamenki – ABC = A! + B! + C! Upotrijebite funkcije:

#include <iostream>

using namespace std;
bool provjera(int);
int faktorijel(int n);

void main()
{
	for (int i = 100; i < 1000; i++)
	{
		if (provjera(i))
			cout <<"" << i << endl;
	}
}

bool provjera(int n)
{
	int suma = 0;
	int broj = n;
	while (broj>0)
	{
		int zadnja = broj % 10;
		suma += faktorijel(zadnja);
		broj /= 10;
	}
	if (suma == n)
		return true;
	else
		return false;
}

int faktorijel(int n)
{
	if (n < 1)
		return n;
	int faktorijel = 1;
	for (int i = 1; i <= n; i++)
	{
		faktorijel *= i;
	}

	return faktorijel;
}
