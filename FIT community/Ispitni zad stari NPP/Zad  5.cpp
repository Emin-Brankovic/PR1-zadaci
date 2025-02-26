//Napišite program u kojem ćete deklarirati niz od 7 cijelih brojeva. Uz pomoć funkcije:
//void unos (int [], int); omogućite unos elemenata u niz;
//float prosjecna(int [], int); izračunati prosječnu vrijednost elemenata niza;
//bool opadajuci (int [], int); provjeriti jesu li elementi niza poredani u opadajuæem poretku (n1 > n2 > n3 > n4 > n5 > n6 > n7);

#include <iostream>

using namespace std;
void unos(int niz[]);
float prosjekNiza(int niz[]);
bool isOpadajuci(int niz[]);

void main()
{
	int niz[7];
	unos(niz);
	cout << "Prosjek clanova niza je: " << prosjekNiza(niz) << endl;
	if (isOpadajuci(niz))
		cout << "Niz je opadajuci" << endl;
	else
		cout << "Niz nije opadajuci" << endl;
}

void unos(int niz[])
{
	cout << "Unesite clanove niza" << endl;
	for (int i = 0; i < 7; i++)
	{
		cin >> niz[i];
	}
}

float prosjekNiza(int niz[])
{
	float prosjek=0;
	for (int i = 0; i < 7; i++)
	{
		prosjek += niz[i];
	}

	return prosjek / 7;
}

bool isOpadajuci(int niz[])
{
	for (int i = 1; i < 7; i++)
	{
		if (niz[i - 1] < niz[i]) 
			return false;
	}
	return true;
}
