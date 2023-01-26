/*Napisati program u kojem je potrebno unijeti odabrani broj cifara počevši od cifre najveće težinske vrijednosti, pa od njih sastaviti i ispisati prirodni broj.
Unos cifara se prekida kada se unese broj manji od 0 ili veći od 9*/
#include <iostream>

using namespace std;


void main()
{
	int cifra,novi=0;
	do
	{
		cout << "X: ", cin >> cifra;
		if (cifra >= 0 && cifra <= 9)
			novi = novi * 10 + cifra;
	} while (cifra>=0 && cifra<=9);
	cout << novi;
}
