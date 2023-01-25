/*Napisati program koji korisniku omogućava unos realnog broja x i odabir funkcije za proračun datog izraza. 
Korisnik bira funkciju unosom jednog od sljedećih karaktera: 's' (sin), 'c' (cos).
U slučaju da korisnik unese karakter koji ne odgovara niti jednoj od predefinisanih vrijednosti ispisati odgovarajuću poruku i ponoviti odabir. 
Za određenu funkciju sin() izraz je: n / (sin(x / x) + x); */

#include <iostream>

using namespace std;

void main()
{
	char slovo;	
	float x;
	float sum = 1;
	cout << "Unesite broj: ", cin >> x;
	do
	{
		cout << "Odaberite funkciju: ", cin >> slovo;
		if (slovo == 's')
		{
			for (int i = 1; i <= x; i++)
			{
				sum += i / (sin(x / i) + x);
			}
		}
		else if (slovo == 'c')
		{
			for (int i = 1; i <= x; i++)
			{
				sum += i / (cos(x / i) + x);
			}
		}

		else
			cout << "Odabir funckije ne postoji, pokusajte ponovo" << endl;
	} while (slovo!='s' && slovo!='c');
	cout << sum;
}
