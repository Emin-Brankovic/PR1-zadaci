/*Napišite program u kojem ćete omogućiti deklaraciju kvadratne matrice 4x4 i provjeriti je li riječ o magičnom kvadratu. 
Upotrijebite barem jednu rekurzivnu funkciju. 
Magični kvadrat je kvadratna tablica(matrica) veličine nxn sa prirodnim brojevima od 1 do n2 kod koje su sume elemenata po recima, stupcima i dijagonalama jednaki. */

#include <iostream>

using namespace std;
void unos(int matrica[][4], int i, int j);
void ispis(int matrica[][4], int i, int j);
void SumaReda(int matrica[][4],int red[4]);
void SumaKolona(int matrica[][4],int kolona[4]);
int SumaGlavne(int matrica[][4], int i, int sum);
int SumaSporedne(int matrica[][4], int i, int sum);
bool Provjera(int red[4], int kolona[4],int matrica[][4]);

void main()
{
	int matrica[4][4];
	int red[4];
	int kolona[4];
	unos(matrica, 0, 0);
	ispis(matrica, 0, 0);
	SumaReda(matrica, red);
	SumaKolona(matrica, kolona);
	if (Provjera(red, kolona, matrica))
		cout << "Magicna kocka" << endl;
	else
		cout << "Nije magicna kocka" << endl;
}

void unos(int matrica[][4], int i, int j)
{
	int n=0;
	if (j == 4)
	{
		j = 0;
		i += 1;
	}
	if (i == 4) return;
	do
	{
		cout << "Unijeti clan za " << i + 1 << ". red i " << j + 1 << ". kolonu" << endl;
		cin >> n;
		system("cls");
	} while (n<1 || n>16);
	matrica[i][j] = n;
	unos(matrica, i, j + 1);
}

void ispis(int matrica[][4], int i, int j)
{
	if (j == 4)
	{
		cout << endl;
		j = 0;
		i += 1;
	}
	if (i == 4) return;
	cout << matrica[i][j] << " ";
	ispis(matrica, i, j + 1);
}

// Funckija koja sumira clanove jednog reda i stavlja ih u drugi niz
void SumaReda(int matrica[][4],int red[4])
{
	int suma = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			suma += matrica[i][j];
		red[i] = suma;
		suma = 0;
	}
}
// Funckija koja sumira clanove jedne kolone i stavlja ih u drugi niz
void SumaKolona(int matrica[][4],int kolona[4])
{
	int sum = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
			sum += matrica[i][j];
		kolona[j] = sum;
		sum = 0;
	}
}

int SumaGlavne(int matrica[][4], int i, int sum)
{
	if (i == 4) return sum;
	return SumaGlavne(matrica, i + 1, sum += matrica[i][i]);
}

int SumaSporedne(int matrica[][4], int i, int sum)
{
	if (i == 4) return sum;
	return SumaSporedne(matrica, i + 1, sum += matrica[i][4 - i - 1]);
}

//Provjerava da li je magicna kocka tako sto poredi prvo sumu svakog reda i kolone matrice pa poslije poredi sume dijegonala i sumu dijagonale jedne sa sumom jednog reda matrice
bool Provjera(int red[4], int kolona[4],int matrica[][4])
{
	int glavna = SumaGlavne(matrica, 0, 0);
	int sporedna = SumaSporedne(matrica, 0, 0);
	for (int i = 0; i < 3; i++)
	{
		if (red[i] != red[i + 1] && kolona[i] != kolona[i + 1])
			return false;
	}
	if (glavna == sporedna && glavna == red[0]) return true;
	else return false;
}
