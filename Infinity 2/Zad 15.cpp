/*Napisati program koji na osnovu unesenog cijelog broja N pronalazi i ispisuje srednju cifru ako broj N ima neparan broj cifara, 
odnosno aritmeticku sredinu (tip float) srednje dvije cifre ako broj N ima parni broj cifara, 
a zatim pronaci najmanji broj tipa int sa kojim se srednja cifra ili aritmeticka sredina srednjih cifri treba pomnoziti da bi se dobio broj koji je veci
od inicijalnog zadanog broja.*/

#include <iostream>

using namespace std;
int getCifre(int broj);
float getSrednja(int broj);
float najveci(int n);

void main()
{
	int n;
	do
	{
		cout << "Unijeti broj n: ", cin >> n;
	} while (n<0);
	cout << "Najveci: " << najveci(n) << endl;
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

float getSrednja(int broj)
{
	int brojCifri = getCifre(broj);
	int srednja;
	float sum = 0.0f;
	if (brojCifri % 2 != 0)
	{
		srednja = broj / pow(10, brojCifri / 2);
		return srednja%10;
	}
	else
	{
		srednja = broj / pow(10, (brojCifri / 2) - 1);
		sum += srednja % 10;
		srednja /= 10;
		sum += srednja % 10;
		return float(sum / 2.0);
	}
}

float najveci(int n)
{
	float srednja = getSrednja(n);
	float veci;
	for (int i = 281245; i < n ; i++)
	{
		veci = float(i * srednja);
		if (veci > n)
			return veci;
	}
}
