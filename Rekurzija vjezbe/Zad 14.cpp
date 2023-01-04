/*Napišite program koji će omogućiti kreiranje matrice 3x3 cijelih brojeva, te uz pomoć rekurzivnih funkcija omogućiti: 
·        unos elemenata, ·         ispis elemenata, ·         izračunati sumu svih elemenata matrice, ·        
sumu pozitivnih elemenata matrice, ·         sumu elemenata matrice s parnim indeksima.*/

#include <iostream>

using namespace std;
void unos(int matrica[][3], int size, int i, int j);
void ispis(int matrica[][3], int size, int i, int j);
int suma(int matrica[][3], int size, int i, int j, int sum);
int SumaPozEle(int matrica[][3], int size, int i, int j, int sum);
int SumaPozIndeks(int matrica[][3], int size, int i, int j, int sum);

void main()
{
	const int size = 3;
	int matrica[size][size];
	unos(matrica, size, 0, 0);
	cout << endl;
	ispis(matrica, size, 0, 0);
	cout << "Zbri clanova matrice je: " << suma(matrica, size, 0, 0, 0) << endl;
	cout << "Zbir svih pozitivnih clanova je: " << SumaPozEle(matrica, size, 0, 0, 0) << endl;
	cout << "Zbit svih elemenata sa parnim indeksom: " << SumaPozIndeks(matrica, size, 0, 0, 0) << endl;
}

void unos(int matrica[][3], int size, int i, int j)
{
	if (j == size)
	{
		j = 0;
		i += 1;
	}
	if (i == size) return;
	cin >> matrica[i][j];
	unos(matrica, size, i, j + 1);
}

void ispis(int matrica[][3], int size, int i, int j)
{
	if (j == size)
	{
		j = 0;
		i += 1;
		cout << endl;
	}
	if (i == size) return;
	cout << matrica[i][j] << " ";
	ispis(matrica, size, i, j + 1);
}

int suma(int matrica[][3], int size, int i, int j, int sum)
{
	if (j == size)
	{
		j = 0;
		i += 1;
	}
	if (i == size) return sum;
	return suma(matrica, size, i, j + 1, sum += matrica[i][j]);
}

int SumaPozEle(int matrica[][3], int size, int i, int j, int sum)
{
	if (j == size)
	{
		j = 0;
		i += 1;
	}
	if (i == size) return sum;
	if (matrica[i][j] > 0) return SumaPozEle(matrica, size, i, j + 1, sum += matrica[i][j]);
	else return SumaPozEle(matrica, size, i, j + 1, sum);
}

int SumaPozIndeks(int matrica[][3], int size, int i, int j, int sum)
{
	if (j == size)
	{
		j = 0;
		i += 1;
	}
	if (i == size) return sum;
	if(i%2==0) SumaPozEle(matrica, size, i, j + 1, sum += matrica[i][j]);
	else  return SumaPozEle(matrica, size, i, j + 1, sum);
}
