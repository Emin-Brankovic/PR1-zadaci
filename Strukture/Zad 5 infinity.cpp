/*2D niz na slici predstavlja šahovsku tablu. Napraviti i testirati u main programu slijedeće funkcije:

Funkcija za unos elemenata tako da se u svako crno polje unese parni broj sa neparnim brojem cifara a u svako bijelo polje unese neparni broj sa parnim brojem cifara.
Funkcija koja će računati aritmetičku sredinu svih brojeva na crnim poljima iznad glavne dijagonale.
Za olaksanje rjesenja, mozete izabrati prototip funkcija po zelji te kreirati dodatne funkcije po potrebi.

(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)*/

#include <iostream>
#include <time.h>
using namespace std;

const int vel = 10;
void ispis(int niz[][vel]);
void unos(int niz[][vel]);
int brojCifara(int broj);
float srednjaIznadGl(int niz[][vel]);

void main()
{
  srand(time(0));
	int niz[vel][vel];
	unos(niz);
	cout << endl;
	ispis(niz);
	cout << endl;
	cout << "Srednja vrijednost: " << srednjaIznadGl(niz);
}

int brojCifara(int broj)
{
	int brojac = 0;
	while (broj>0)
	{
		broj /= 10;
		brojac++;
	}
	return brojac;
}

void unos(int niz[][vel])
{
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if ((i+j)%2==0)
			{
				do
				{
					niz[i][j] = rand() % 10000;
				} while (*(*(niz+i)+j) % 2 != 0 || brojCifara(niz[i][j]) % 2 == 0); // provjera da li je paran broj sa neparnim brojem cifara
			}
			else
			{
				do
				{
					niz[i][j] = rand() % 10000;
				} while (niz[i][j] % 2 == 0 || brojCifara(niz[i][j]) % 2 != 0); //provjera da li je neparan broj sa parnim brojem cifara
			}
		}
	}
}

void ispis(int niz[][vel])
{
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			cout << niz[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

float srednjaIznadGl(int niz[][vel])
{
	float srednja=0.0f;
	int brojac=0;
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if ((i + j) % 2 == 0 && j>i) 
			{
				cout << niz[i][j] << "\t ";
				srednja += niz[i][j];
				brojac++;
			}
			else
			{
				cout << "* " << "\t";
			}
			
		}
		cout << endl;
	}
	return float(srednja / brojac);
}
