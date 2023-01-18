/*Napisati program koji će omogućiti korisniku unos dva minimalno trocifrena prirodna broja m i n (n > m, m > 100, n < 500). 
Zatim napraviti funkciju koja će vratiti aritmetičku sredinu svih srednjih cifara svih brojeva u rangu od m do n.
Također ta funkcija treba ispisati najveću srednju cifru navedenog ranga.*/

#include <iostream>

using namespace std;

int getSrednja(int broj);
void aritmeticka(int m, int n);

void main()
{
	int m, n;
	do
	{
		cout << "Unijeti broj m: ", cin >> m;
	} while (m<=100);

	do
	{
		cout << "Unijeti broj n: ", cin >> n;
	} while (n<=m || n>=500);
	aritmeticka(m, n);
}


int getSrednja(int broj)
{
	int srednja = broj / 10;
	return srednja % 10;
}

void aritmeticka(int m, int n)
{
	int sum = 0;
	int najveca = INT_MIN;
	for (int i = m; i < n; i++)
	{
		int broj= getSrednja(i);
		sum +=broj;
		if (broj > najveca)
			najveca = broj;
	}
	cout << "Suma: " << sum << endl;
	cout << "Najveca: " << najveca << endl;
}
