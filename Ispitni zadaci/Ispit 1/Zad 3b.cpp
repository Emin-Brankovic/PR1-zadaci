/*Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati funkciju koja će taj niz popuniti serijom Fibonacci brojeva počevši od broja 1.
Za pronalazenje elemenata Fibonacci serije obavezno koristiti rekurzivnu funkciju.
Punjenje niza se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli. U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama.
Obavezno koristiti aritmetiku pokazivača.*/

#include <iostream>

using namespace std;
int fib(int n);
void unos(int* niz, int size, int i);
void ispis(int* niz, int size, int i);

void main()
{
	int size;
	cout << "Unijeti velicinu niza: ", cin >> size;
	int* niz = new int[size];
	unos(niz, size, 0);
	ispis(niz, size, 0);

	delete[] niz;
	niz = nullptr;
}

int fib(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	return fib(n - 1) + fib(n - 2);
}

void unos(int* niz, int size, int i)
{
	int broj = fib(i+1);
	if (i == size) return;
	if (broj < 0) return;
	*(niz + i) = broj;

	unos(niz, size, i + 1);
}

void ispis(int* niz, int size, int i)
{
	if (i == size) return;
	cout << *(niz + i) << " ";
	ispis(niz, size, i + 1);
}
