/*Napisati program koji će omogućiti korisniku da unese velicinu jednodimenzionalnog dinamickog niza integer vrijednosti. 
Napisati rekurzivnu funkciju koja će taj niz puniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512 itd., 
tako da je svaki slijedeci broj jednak prethodnom pomnozenom sa 2, pocevsi od broja 2.
Rekurzija se prekida kad se popuni cijeli niz ili kad se desi overflow na integer varijabli. 
U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. 
Obavezno koristiti aritmetiku pokazivaca. Za olaksanje rjesenja, mozete izabrati prototip funkcija po zelji.*/
#include <iostream>

using namespace std;

void unos(int* niz, int size, int indeks, int broj);

void main()
{
	int size;
	cout << "Velicina: ", cin >> size;	
	int* niz = new int[size];
	unos(niz, size, 0, 2);
	//for (int i = 0; i < size; i++)
	//	cout << niz[i] << " ";
	delete[] niz;
	niz = nullptr;
}

void unos(int* niz, int size, int indeks,int broj)
{
	if (indeks >= size) return;
	if (broj < 0) return;
	*(niz + indeks) = broj;
	unos(niz, size, indeks+1, broj*2);
}
