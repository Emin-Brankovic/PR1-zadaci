/*Napisati program koji će omogućiti korisniku da unese veličinu n jednodimenzionalnog dinamičkog niza integer vrijednosti (n > 2). 
Napisati rekurzivnu funkciju koja će taj niz puniti serijom brojeva tako da je svaki sljedeći broj jednak umnošku dva prethodna broja,
a prva dva elementa su 1 i 3 (1, 3, 3, 9, 27, ...).
Zatim napraviti drugu rekurzivnu funkciju koja će izračunati zbir svih elemenata tog niza (voditi računa o tipu podatka zbog veličine broja).
(Obavezno koristiti aritmetiku pokazivača)*/

#include <iostream>

using namespace std;
int unos(int niz[], int i, int size);
int sum(int niz[], int i, int size, int suma);

void main()
{
	int n;
	do
	{
		cout << "Unesite velecinu niz: ", cin >> n;

	} while (n<2);
	int* niz = new int[n];
	niz[0] = 1;
	niz[1] = 3;
	int indeks=unos(niz, 2, n); // koristi se vraceni indeks kao granica za ispis i salje za sumu
	for (int i = 0; i < indeks; i++) 
		cout << niz[i] << " ";
	cout << endl;
	cout << "Suma je: " << sum(niz, 0, indeks, 0);

	delete[] niz;
	niz = nullptr;
}

int unos(int niz[], int i,int size) // rekurzivna funkcija koja puni niz al vraca indeks kada se desi overflow
{
	if (i > size - 1) return i;

	int br1 = *(niz + i - 1);
	int br2= *(niz + i - 2);
	if (br1*br2 < 0)
		return i;
	else
	{
	*(niz + i) = br1 * br2;

	}
	return unos(niz, i + 1, size);
}

int sum(int niz[], int i, int size, int suma)
{
	if (i > size - 1) return suma;
	suma += *(niz + i);
	if (suma < 0) return suma;
	return sum(niz, i + 1, size, suma);
}
