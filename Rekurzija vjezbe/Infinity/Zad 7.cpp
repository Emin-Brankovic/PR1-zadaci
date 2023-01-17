/*Kreirati jednodim dinam niz n velicine i napuniti ga serijom kubova svakog proslog broja pocevsi od 2. 
Prekida se kada se deesi overflow, napuni niz.Ispisati niz rekurzivno!
Koristiti aritmetiku pointera!*/

#include <iostream>

using namespace std;
int unos(int* niz, int size, int i, int broj);
void ispis(int* niz, int size, int i);

void main()
{
	int size;
	cout << "Unijeti velicinu niza: ", cin >> size;
	int* niz = new int[size];
	int indeks = unos(niz, size, 0, 2);
	ispis(niz, indeks, 0);
}

int unos(int* niz, int size, int i,int broj)
{
	if (i > size - 1) return i;
	if (broj < 0) return i;

	*(niz + i) = broj;
	broj = pow(broj, 3);

	unos(niz, size, i + 1, broj);
}

void ispis(int* niz, int size, int i)
{
	if (i>size-1) return;
	cout << *(niz + i) << " ";
	ispis(niz, size, i+1);
}
