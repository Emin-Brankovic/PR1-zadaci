/*Napisati program koji će omogućiti unos prirodnog broja A (A > 100000), te kreirati i ispisati broj B koji će se sastojati od cifara broja A u obrnutom redoslijedu gdje je svaka parna cifra uklonjena.

Npr. ako se unese 45362792, funkcija treba vratiti 9735Ispisati razliku brojava A i B

(Obavezno koristiti bar jednu korisnički definisanu funkciju)*/

#include <iostream>

using namespace std;
int obrnuti(int broj);

void main()
{
	int a;
	do
	{
		cout << "Unijeti broj A: ", cin >> a;
	} while (a<= 100000);
	int b= obrnuti(a);
	cout << b << endl;
	cout << "Razlika brojeva a i b je: " << a - b << endl;
}

int obrnuti(int broj)
{
	int zadnja,novi=0,br=0;
	while (broj>0)
	{
		zadnja = broj % 10;
	/*	if (zadnja == 0 && br != 0) // ovo je neki edge case 
		{
			novi *= 10;
			broj /= 10;
		}*/
		if (zadnja % 2 != 0)
		{
			novi = (novi * 10) + zadnja;
			broj /= 10;
		}
		else
			broj /= 10;
		/*br++;*/
	}
	return novi;
}
