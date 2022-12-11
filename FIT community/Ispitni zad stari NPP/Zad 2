Napišite program u kojem ćete deklarirati matricu 5x4. Redak u matrici je učenik, a kolona predmet. Uz pomoć funkcije:

void unos (int [] [4]); omogućite unos samo prolaznih ocjena (2-5) za sve učenike;
float prosjek(int []); izračunati prosječnu ocjenu učenika; za kojeg od učenika će se računati prosjek bira korisnik;
int prebroji (int [][4], int); prebrojati koliko učenika ima ocjenu 4 i više na predmetu po izboru korisnika.

#include <iostream>

using namespace std;
void unos(int niz[][4]);
void ispis(int niz[][4]);
float prosjekOcjena(int niz[]);
int prebroji(int[][4], int);

void main()
{
	int matrica[5][4];
	unos(matrica);
	ispis(matrica);
	int ucenik;
	int predmet;
	do
	{
		cout << "Unijeti broj ucenika za koji zelite vidjeti prosjek: ", cin >> ucenik;
	} while (ucenik<1 || ucenik>5 );

	cout << "Prosjek je: " << prosjekOcjena(matrica[ucenik-1]) << endl;

	do
	{
		cout << "Unijeti predmet za pregled ocjena: ", cin >> predmet;
	} while (predmet<1 || predmet>4);

	cout << "Broj ucenika koji imaju ocjenu izmedju 4 i 5 na predmetu" << predmet << " je: " << prebroji(matrica, predmet) << endl;
}

void unos(int niz [][4])
{
	int ocjena;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "Unijeti ocjenu za: " << j + 1 << " predmet" << endl;
			cin >> ocjena;
			if (ocjena > 1 && ocjena < 6)
				niz[i][j] = ocjena;
			else
				niz[i][j] = 1;
		}
		cout << endl;
	}
}

void ispis(int niz[][4])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << " " << niz[i][j];
		}
		cout << endl;
	}
}

float prosjekOcjena(int niz[])
{
	float prosjek=0;

	for (int i = 0; i < 4; i++)
	{
		prosjek += niz[i];
	}
	prosjek /= 4;

	return prosjek;
}

int prebroji(int niz [][4], int n)
{
	n = n - 1;
	int brojac_ucenika = 0;
	for (int i = 0; i < 5; i++)
	{
		if (niz[i][n] >= 4 && niz[i][n] < 6)
			brojac_ucenika++;
	}

	return brojac_ucenika;
}
