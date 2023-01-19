/*Napisati program koji će uzastopno učitavati cijele brojeve m i n (1 <= m <= 50, 1 <= n <= 500) i pronalaziti srednju cifru njihovog proizvoda/umnoška. 
Program treba ispisivati srednju cifru samo ako je veća od prethodno izračunate srednje cifre. Prva pronađena srednja cifra se svakako ispisuje. 
Program se forsirano prekida ako korisnik unese n = 0. Program se prirodno završava ako je pronađena srednja cifra 9.*/

#include <iostream>

using namespace std;
void unos(int& n, int& m);
float srednja(int broj);
int getCifre(int broj);

void main()
{
	int n, m;
	int srednjaCifra=0, proizvod, prethodna = 0;
	do
	{
		unos(n, m);
		proizvod = n * m;
		srednjaCifra = srednja(proizvod);
		if (n == 0)
			cout << "Forsiran prekid" << endl;
		else if (srednjaCifra > prethodna)
		{
			cout << "srednja cifra / sredina proizvoda brojeva " << n << " i " << m << " je: "<<srednjaCifra << endl;
		}
		else
		{
			cout << "srednja cifra / sredina proizvoda brojeva " << n << " i " << m << " je: " << " ne ispisuje se" << endl;
		}
		prethodna = srednjaCifra;
	} while (n!=0 && srednjaCifra!=9);
	
}

void unos(int& n, int& m)
{
	do
	{
		cout << "Unijeti m: ", cin >> m;
	} while (m<1 || m>50);
	do
	{
		cout << "Unijeti n: ", cin >> n;
	} while (n<0 || n>500);
}

float srednja(int broj)
{
	int brojCifri = getCifre(broj);
	int srednja=0;
    float sum=0;
	if (brojCifri % 2 == 0)
	{
		srednja = broj / pow(10, (brojCifri / 2) - 1);
		float temp = srednja % 10;
		sum += temp;
		srednja /= 10;
		temp = srednja % 10;
		sum += temp;
		return sum / 2.0;
	}
	else
	{
		srednja = broj / pow(10, brojCifri / 2);
		return srednja % 10;
	}
}

int getCifre(int broj)
{
	int brojac = 0;
	while (broj>0)
	{
		broj /= 10;
		brojac++;
	}
	return brojac;
}
