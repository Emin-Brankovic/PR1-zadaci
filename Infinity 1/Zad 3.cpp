/*Napisati program u kojem je potrebno unijeti odabrani broj cifara počevši od cifre najveće težinske vrijednosti, pa od njih sastaviti i napisati prirodni broj.
Unos cifara se prekida kada se unese broj manji od 0, ukoliko korisnik unese cifru veću od 9, ispisati poruku da cifra nije validna, ali se unos ne prekida.*/
#include <iostream>

using namespace std;

void main()
{
	int cifre,broj = 0;
	do
	{
		cout << "Cifra: ", cin >> cifre;
		if (cifre > 9)
			cout << "Cifra nije valinda" << endl;
		else if(cifre>=0 && cifre<=9)
		{
			broj = broj * 10 + cifre;
		}
	} while (cifre>=0);
	cout << broj << endl;
}
