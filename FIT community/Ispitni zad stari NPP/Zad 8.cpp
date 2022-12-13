/*Napišite program u kojem ćete :
omogućiti unos niza od 6 realnih brojeva u intervalu od -7.0 do +7.0 pomoću funkcije: void unos (float [], int);
definirati i upotrijebiti funkciju int najvecineg(float [], int); koja će pronaći i vratiti poziciju najvećeg negativnog elementa u nizu; (Moguće je da u nizu uopće ne bude negativnih brojeva – ispisati odgovarajuću poruku.)
definirati i upotrijebiti funkciju float suman(float[], int); koja treba izračunati i vratiti sumu negativnih elemenata niza; (Moguće je da u nizu uopće ne bude negativnih brojeva.)
Ispis pozicije najvećeg negativnog elementa, sume negativnih elemenata kao i odgovarajućih poruka vršite u funkciji main.*/

#include <iostream>

using namespace std;
void unos(float niz[]);
int najvecineg(float niz[]);
float suman(float niz[]);
bool isNegativni(float niz[]);

void main()
{
	float niz[6];
	unos(niz);
	if (isNegativni(niz))
	{
		cout << "Pozicija najveceg negativnog broja " << najvecineg(niz) << endl;
		cout << "Suma negativnih clanova niza je: " << suman(niz) << endl;
	}
	else
	{
		cout << "U nizu nema negativnih brojeva" << endl;
	}

}

void unos(float niz[])
{
	float broj;
	for (int i = 0; i < 6; i++)
	{
		do
		{
			cin >> broj;
		} while (broj<-7.0f || broj>7.0f);
		niz[i] = broj;
	}
}

int najvecineg(float niz[])
{
	float najveci = -7.0f;
	int indeks = 0;
	int indeksnaj;
	for (int i = 0; i < 6; i++)
	{
		indeks++;
		if (niz[i]<0.0f && niz[i] > najveci)
		{
			najveci = niz[i];
			indeksnaj = indeks;
		}
	}
	return indeksnaj;
}

float suman(float niz[])
{
	float suma = 0;
	for ( int i = 0; i <6; i++)
	{
		if (niz[i] < 0)
			suma += niz[i];
	}
	return suma;
}

bool isNegativni(float niz[])
{
	for (int i = 0; i < 6; i++)
	{
		if (niz[i] < 0)
			return true;
	}
	return false;
}
