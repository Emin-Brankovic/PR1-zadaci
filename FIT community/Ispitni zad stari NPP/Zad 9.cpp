/*Napišite program koji će omogućiti kreiranje matrice prirodnih brojeva 2x3. Pretpostavka je da postoji funkcija koja omogućava unos prirodnih brojeva (ne treba ju definirati); Kreirajte funkcije:
void kopiraj(int[][3], int [][5]); zadaća funkcije da kopira sve elemente iz jedne matrice (2x3) u drugu matricu (2x5) pri čemu se prve dvije kolone prve matrice kopiraju dva puta;
funkcije: int suma(int [], int); čija je zadaća izračunati sumu retka kojeg izabere korisnik za matricu koju izabere korisnik; obavezno onemogućiti korisnika da izabere nepostojeću matricu i nepostojeći redak;
Ispis sume i izbor matrice i retka vršite u funkciji main.*/

#include <iostream>

using namespace std;
void unos(int niz[][3]);
void kopiraj(int niz1[][3], int niz2[][5]);
int suma(int[], int);
void main()
{
	int niz[2][3], niz2[2][5],odabir,red;
	unos(niz);
	kopiraj(niz, niz2);

	do
	{
	cout << "Odaberite matricuu za izracunavanje ", cin >> odabir;
	} while (odabir<1 || odabir>2);
	switch (odabir)
	{
	case 1:
		cout << "Odaberite red matrice: ", cin >> red;
		cout<<"Suma clanova "<<red<<" reda je: "<<suma(niz[red-1], 3);
		break;
	case 2:
		cout << "Odaberite red matrice: ", cin >> red;
		cout << "Suma clanova " << red << " reda je: " << suma(niz2[red-1], 5);
		break;
	
	}
}

void unos(int niz[][3])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> niz[i][j];
		cout << endl;
	}
}

void kopiraj(int niz1[][3], int niz2[][5])
{

	for (int i = 0; i < 2; i++)
	{
		int indeks = 0;
		for (int j = 0; j < 5; j++)
		{
			niz2[i][j] = niz1[i][indeks]; // 00 11 22
			indeks++;
			if (indeks > 2)
				indeks = 0;
		}
	}
}

int suma(int niz[],int broj)
{
	int suma = 0;
	for (int i = 0; i < broj; i++)
	{
		suma += niz[i];
	}
	return suma;
}
