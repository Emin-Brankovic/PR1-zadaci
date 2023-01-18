#include <iostream>

using namespace std;
int unos(int i, int broj, int* niz, int size);
//void pretragaBroja(int* niz, int size, int broj, int i);

void main()
{
	int vel;
	int broj;
	cout << "Unesite velicinu niza: ", cin >> vel;
	int* niz = new int[vel];
	int indeks = unos(0, 2, niz, vel);
	for (int i = 0; i < indeks; i++)
	{
		cout << *(niz + i) << " ";
	}
	/*cout << "Unesite broj koji trazite u nizu: ", cin >> broj;
	pretragaBroja(niz, vel, broj, 0);*/

	delete[]niz;
	niz = nullptr;
}

int unos(int i, int broj, int* niz, int size)
{

	if (i > size - 1) return i;

	*(niz + i) = broj;	
	broj *= 2;
	if (broj < 0) return i;
	unos(i + 1, broj, niz, size);
}

void pretragaBroja(int* niz, int size, int broj,int i)
{
	
	if (i > size - 1) return;

	if (*(niz + i) == broj)
	{
		cout << broj << " je pronadjen u nizu na indeksu: " << i << endl;
	}
		
	if(i==size-1)
	{
		cout << "Vas broj " << broj << " se ne nalazi u nizu" << endl;
	}
	pretragaBroja(niz, size, broj, i + 1);
}
