/*Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti. 
Napisati rekurzivnu funkciju koja će taj niz popuniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512, itd., 
tako da je svaki sljedeći broj jednak prethodnom pomnoženom sa 2, počevši od broja 2.
Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.
U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.*/
#include <iostream>

using namespace std;
int unos(int* niz, int size, int indeks, int broj);


void main()
{
	int size;
	cout << "Unijeti velicinu niza: ", cin >> size;
	int* niz = new int[size];
	int indeks = unos(niz, size, 0, 2);
	for (int i = 0; i < indeks; i++)
		cout << *(niz + i) << " ";

	delete[] niz;
	niz = nullptr;
}

int unos(int* niz, int size, int indeks, int broj) // razlgo sto je int jer ako se desi overflow a zelimo ispisati ispisat ce junk vrijednosti na indeksima koji niza koji su preostali
{                                                   // ako se ne trazi ispis onda uradi void return type
	if (indeks == size) return indeks ;
	if (broj < 0) return indeks;
	*(niz + indeks) = broj;
	return unos(niz, size, indeks + 1, broj * 2);
}
