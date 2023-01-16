/*Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti. 
Napisati funkciju koja će taj niz popuniti serijom Fibonacci brojeva počevši od broja 1.
Za pronalazenje elemenata Fibonacci serije obavezno koristiti rekurzivnu funkciju. 
Punjenje niza se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.

(U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)*/

#include <iostream>

using namespace std;
void unos(int niz[], int i, int size);
int fib(int broj);

void main()
{
	int size;
	cout << "Unijeti velicinu niz: ", cin >> size;
	int* niz = new int[size];
	unos(niz, 0, size);
	for (int i = 0; i < size; i++)
		cout << niz[i] << " ";
	delete[] niz;
	niz = nullptr;
}

void unos(int niz[], int i, int size)
{
	if(i>size-1) return;
	int broj= fib(i);
	if (broj < 0) return;
	niz[i] = broj;
	unos(niz, i + 1, size);
}

int fib(int broj)
{
	if (broj == 0) return 1;
	if (broj == 1) return 1;

	return fib(broj - 1) + fib(broj - 2);
}
