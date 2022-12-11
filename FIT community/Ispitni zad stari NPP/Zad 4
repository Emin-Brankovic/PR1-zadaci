#include <iostream>

using namespace std;
void unos(int niz1[], int niz2[]);
void incijalizacijaNiza(int niz1[], int niz2[], int niz3[]);
void ispis(int niz1[], int niz2[], int niz3[]);
int sumiraj(int niz[], int n);

void main()
{
	int odabir_niza;
	int niz1[3], niz2[4], niz3[7];
	unos(niz1, niz2);
	incijalizacijaNiza(niz1, niz2, niz3);
	ispis(niz1, niz2, niz3);
	do
	{
		cout << "Odaberite niz kojeg zelite vidjeti sumu clanova" << endl;
		cin >> odabir_niza;
	} while (odabir_niza<1 || odabir_niza>3);

	switch (odabir_niza)
	{
	case 1:
		cout << "Suma clanova prvog niza je: " << sumiraj(niz1, 3) << endl;
		break;
	case 2:
		cout << "Suma clanova drugog niza je: " << sumiraj(niz2, 4) << endl;
		break;
	case 3:
		cout << "Suma clanova treceg niza je: " << sumiraj(niz3, 7) << endl;

	default:
		break;
	}
}

void unos(int niz1[], int niz2[])
{
	cout << "Unijeti clanove prvog niza" << endl;
	system("pause>0");
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Unijeti "<<i+1<<" clan" << endl;
		cin >> niz1[i];
	}

	cout << "Unijeti clanove drugog niza" << endl;
	system("pause>0");
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "Unijeti " << i + 1 << " clan" << endl;
		cin >> niz2[i];
	}

}

void incijalizacijaNiza(int niz1[], int niz2[], int niz3[])
{
	for (int i = 0; i < 3; i++)
	{
		niz3[i] = niz1[i];
	}
	for (int i = 3 ,j=0; i < 7 && j<4; i++, j++)
	{
		niz3[i] = niz2[j];
	}
}

void ispis(int niz1[], int niz2[], int niz3[])
{
	cout << endl;
	cout << "Prvi niz: " << endl;
	
	for (int i = 0; i < 3; i++)
		cout << niz1[i] << endl;
	cout << endl;
	cout << "Drugi niz: " << endl;
	for (int i = 0; i < 4; i++)
		cout << niz2[i] << endl;
	cout << endl;
	cout << "Treci niz: " << endl;
	for (int i = 0; i < 7; i++)
		cout << niz3[i] << endl;
}

int sumiraj(int niz[], int n)
{
	int suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += niz[i];
	}
	return suma;
}
