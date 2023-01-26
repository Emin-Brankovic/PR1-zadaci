/*Napisati program koji omogućava unos pozitivnog broja n te pronalazi njegove parne cifri i formira novi broj u kojem su parne cifra zamijenjena cifrom '5'. 
Dodatno program treba ispisati razliku unesenog i broja koji se dobije nakon zamjene najmanje cifre.*/
#include <iostream>

using namespace std;
int zamjena(int br);
int getCifre(int broj);

void main()
{
	int n;
	cin >> n;
	int novi= zamjena(n);
	cout << "Razlika: " << n-novi << endl;
}

int zamjena(int br)
{
	int novi=0;
	int brcifre = getCifre(br),cifre;
	for (int i = brcifre; i > 0; i--)
	{
		int broj = br;
		broj /= pow(10, i-1);
		cifre = broj % 10;
		if (cifre % 2 == 0)
			cifre = 5;
		novi = novi * 10 + cifre;
	}
	return novi;
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
