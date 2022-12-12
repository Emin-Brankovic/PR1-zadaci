#include <iostream>

using namespace std; 
void unos(char niz[]);
void ispis(char niz[]);
bool isMalo(char slovo);
void promijeni(char niz_slova[], int niz_brojeva[]);
int bin(int broj);
void binarni(int niz[]);

void main()
{
	char niz[5];
	int niz_brojeva[5];
	unos(niz);
	promijeni(niz, niz_brojeva);
	ispis(niz);
	cout<< endl;
	binarni(niz_brojeva);
}

void unos(char niz[])
{
	char slovo;
	cout << "Unesite mala slova u niz" << endl;
	for (int i = 0; i < 5; i++)
	{
		
		do
		{
			cin >> slovo;
		} while (!isMalo(slovo));
		niz[i]=slovo;
	}
}
void ispis(char niz[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << niz[i] << " ";
	}
}

bool isMalo(char slovo)
{
	
	return slovo >= 'a' && slovo <= 'z';
}

void promijeni(char niz_slova[], int niz_brojeva[])
{
	int slovo=0;
	for (int i = 0; i < 5; i++)
	{
		niz_brojeva[i] = niz_slova[i];
	}

}

int bin(int broj)
{
	int binarni = 0, ostatak, brojac = 0;
	while (broj > 0)
	{
		ostatak = broj % 2;
		binarni = binarni + ostatak * pow(10.0, brojac);
		brojac++;
		broj /= 2;
	}
	return binarni;
}

void binarni(int niz[])
{
	int bina;
	for (int i = 0; i < 5; i++)
	{
		bina = niz[i];
		niz[i] = bin(bina);

		cout << niz[i] << " ";
	}
}
