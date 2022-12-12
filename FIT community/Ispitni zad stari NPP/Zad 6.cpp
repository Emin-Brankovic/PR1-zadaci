//Napišite program koji će omogućiti kreiranje matrice prirodnih brojeva 5x5. Uz pomoć funkcije:
//void unos (int [][5]); omogućite unos elemenata matrice; vodite računa da svi elementi matrice moraju biti prirodni brojevi;
//bool pozicija(int[][5], int &); pronaći prvi redak koji sadrži vrijednost 5; u slučaju da u matrici nema vrijednosti 5 funkcija treba vratiti vrijednost false, a program treba ispisati odgovarajuću poruku;
//float prosjecna(int [][5], int); izračunati prosječnu vrijednost u retku za koji ste prethodnom funkcijom utvrdili da sadrži vrijednost 5; u slučaju da ste prethodnom funkcijom ustanovili da u matrici nema broja 5 funkciju ne treba pozivati.
//Ispis prvog retka koji sadrži vrijednost 5, prosječne vrijednosti u tom retku kao i zahtijevanih poruka vršite u funkciji main.

#include <iostream>

using namespace std;
void unos(int niz[][5]);
bool pozicija(int niz[][5], int& red);
bool sadrziPet(int n);
float projekReda(int niz[][5], int red);

void main()
{
	int matrica[5][5];
	int red=2;
	unos(matrica);

	if (pozicija(matrica, red))
	{
		for (int i = 0; i < 5; i++)
			cout << matrica[red][i] << " " << endl;
		cout<<"Prosjek clanova "<<red+1<<" reda je "<<projekReda(matrica, red);
	}
	else
	{
		cout << "U matrici nema broja koji sadrzi cifru 5" << endl;
	}
	
}

void unos(int niz[][5])
{
	int broj;
	cout << "Unijeti clanove matrice" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			do
			{
				cin >> broj;
			} while (broj<1);
			niz[i][j] = broj;
		}

		cout << endl;
	}
}


bool pozicija(int niz[][5], int& red)
{
	int cifra = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cifra = niz[i][j];
			if (sadrziPet(cifra))
			{
				red = i;
				return true;

			}
		
		}
		
	}

	return false;
}

bool sadrziPet(int n)
{
	while (n > 0)
	{
		int zadnja_cifra = n% 10;
		if (zadnja_cifra == 5)
			return true;
		
		n /= 10;
	}
	return false;
}

float projekReda(int niz[][5], int red)
{
	float suma = 0;
	for (int i = 0; i < 5; i++)
	{
		suma += niz[red][i];
	}
	return suma / 5;
}
