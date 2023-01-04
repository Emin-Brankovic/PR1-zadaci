/*Napišite program koji će omogućiti kreiranje niza od 7 cijelih brojeva, te uz pomoć rekurzivnih
funkcija omogućiti:
· unos elemenata,
· ispis elemenata,
· izračunati sumu svih elemenata niza,
· sumu pozitivnih elemenata niza,
· sumu elemenata niza s parnim indeksom.*/

#include <iostream>

using namespace std; 
void unos(int niz[], int size, int i);
void ispis(int niz[], int size, int i);
int suma(int niz[], int size, int i, int sum);
int SumaPoz(int niz[], int size, int i, int sum);
int SumaParniIndeks(int niz[], int size, int i, int sum);

void main()
{
	const int size = 7;
	int niz[size];
	unos(niz, size, 0);
	ispis(niz, size, 0);
	cout << endl;
	cout << "Suma niza je: " << suma(niz, size, 0, 0) << endl;
	cout << "Suma pozitivnih elemanata niza je: " << SumaPoz(niz, size, 0, 0) << endl;
	cout << "Suma elemenata sa parnim indeksom je: " << SumaParniIndeks(niz, size, 0, 0) << endl;
}

void unos(int niz[], int size, int i)
{
	if (i > size - 1) return;
	cout << "Unijeti " << i + 1 << ". clan niza" << endl;
	cin >> niz[i];
	unos(niz, size, i + 1);
}

void ispis(int niz[], int size, int i)
{
	if (i == size) return;
	cout << niz[i] << " ";
	ispis(niz, size, i + 1);
}

int suma(int niz[], int size, int i,int sum)
{
	if (i == size) return sum;
	return suma(niz, size, i + 1, sum += niz[i]);
}

int SumaPoz(int niz[], int size, int i, int sum)
{
	if (i == size) return sum;
	if (niz[i] > 0) return SumaPoz(niz, size, i + 1, sum += niz[i]);
	else
	{
		return SumaPoz(niz, size, i + 1,sum);
	}
}

int SumaParniIndeks(int niz[], int size, int i, int sum)
{
	if (i == size) return sum;
	if (i % 2 == 0) return SumaParniIndeks(niz, size, i + 1, sum += niz[i]);
	else
	{
		return SumaParniIndeks(niz, size, i + 1, sum);
	}
}
