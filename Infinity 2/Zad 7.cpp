/*Napisati program koji će omogućiti korisniku unos broja n (uz uslov 10 <= n <= 1000). Zatim simulirati unos n slučajnih vrijednosti. 
Simuliranje unosa ostvariti funkcijom rand() % 1000 + 1. 
Izračunati statističke podatke u kojem procentu se od n generisanih slučajnih vrijednosti pojavljuje prost broj.
Npr. Ako je generisano 10 brojeva (n = 10): 5,7,4,13,17,20,25,23,30,45, u ovom uzorku od 10 brojeva postoji 5 prostih brojeva pa je procenat prostih brojeva u ovom slučaju 50%.
(Napomena: Po želji kreirati dodatne funkcije da se olakša rješavanje zadatka.)*/

#include <iostream>
#include <time.h>
using namespace std;
bool isProst(int broj);
void procenat(int n);

void main()
{
	srand(time(0));
	int n;
	do
	{
		cout << "Unijeti broj ponavljanja: ", cin >> n;
	} while (n<10 || n>1000);
	procenat(n);
}

bool isProst(int broj)
{
	if (broj < 2) return false;
	for (int i = 2; i < broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}

void procenat(int n)
{
	float brojac = 0,broj;
	for (int i = 0; i < n; i++)
	{
		broj = rand() % 1000 + 1;
		if (isProst(broj))
			brojac++;
	}
	cout << "Procenat prosti brojeva je: " << round((brojac/n) * 100) << "%" << endl;
}
