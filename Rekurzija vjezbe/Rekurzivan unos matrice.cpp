#include <iostream>

using namespace std;
void unos(int matrica[][3], int i, int j, int red, int kolona);
void ispis(int matrica[][3], int red, int kol);

void main()
{
	srand(time(0));
	const int red = 2;
	const int kol = 3;
	int matrica[red][kol];
	unos(matrica, 0, 0, red, kol);
	ispis(matrica, red, kol);
}

void unos(int matrica[][3], int i, int j, int red, int kolona)
{

	if (j == kolona)
	{
		i=i + 1;
		j = 0;
	}
	if (i == red && j==0 ) return;
	matrica[i][j] = rand() % 100;
	unos(matrica, i, j + 1, red, kolona);
}

void ispis(int matrica[][3], int red, int kol)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}
}
