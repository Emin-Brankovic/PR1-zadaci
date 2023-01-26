/*Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti. 
Napisati i testirati rekurzivnu funkciju koja će taj niz popuniti serijom Fibonacci brojevima.
Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli. 
Zatim napisati i testirati drugu rekurzivnu funkciju koja će u tom nizu naći određenu vrijednost koju korisnik unese sa tastature. 
U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.*/
#include <iostream>

using namespace std;
int fib(int broj);
void unos(int* niz, int size, int i, int broj);
int potraga(int* niz, int size, int i, int broj);


void main()
{
	int size,broj;
	cout << "Velicina: ", cin >> size;
	int* niz = new int[size];
	unos(niz, size, 0, 0);
	cout << "Broj za pretragu: ", cin >> broj;
	int rez = potraga(niz, size, 0, broj);
	if (rez == -1)
		cout << "Nema broja" << endl;
	else
		cout << "Ima broja na indeksu " << rez << endl;
	delete[] niz;
	niz = nullptr;
}

int fib(int broj)
{
	if (broj == 0) return 0;
	if (broj == 1) return 1;

	return fib(broj - 1) + fib(broj - 2);
}

void unos(int* niz, int size, int i,int broj)
{
	if (i >= size) return;
	if (broj < 0) return;
	broj = fib(i);
	*(niz + i) = broj;
	unos(niz, size, i + 1, broj);
}

int potraga(int* niz, int size, int i, int broj)
{
	if (i >= size) return -1;
	if (*(niz + i) == broj) return i;
	return potraga(niz, size, i + 1, broj);
}
