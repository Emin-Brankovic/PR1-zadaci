/*Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati rekurzivnu funkciju koja će taj niz popuniti random brojevima u opsegu od 1 do 100. Za generisanje random brojeva koristiti rand() % 100 + 1. 
Punjenje niza se prekida kada se popuni cijeli niz ili kada se tri puta uzastopno dobije isti random broj. 
U ovom zadatku je zabranjeno indeksirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.
(Obavezno sve riješiti jednom rekurzivnom funcijom.)*/

#include <iostream>
#include <time.h>
using namespace std;
void unos(int* niz, int size, int i, int prethodni,int);
void ispis(int* niz, int size, int i);

void main()
{ 
	srand(time(0));
	int size;
	cout << "Unesite velicinu niza: ", cin >> size;

	int* niz = new int[size];
	unos(niz, size, 0, 0, 0);
	ispis(niz, size, 0);
	delete[] niz;
	niz = nullptr;
}

void unos(int* niz, int size, int i,int prethodni,int br)
{
	if (i > size - 1) return;
	if (br == 3) return;
	int broj = rand() % 100 + 1;
	*(niz + i) = broj;
	if (prethodni == broj) br++;
	else br = 0;
	
	unos(niz, size, i + 1, prethodni = broj,br);
}

void ispis(int* niz, int size, int i)
{
	if (i > size - 1) return;

	cout << *(niz + i) << " ";
	ispis(niz, size, i + 1);
}
