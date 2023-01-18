/*Napisati program koji omogućava korisniku unos prirodnog broja N (50 < N < 5000000).
Zatim uneseni broj proslijediti funkciji kao parametar po referenci. 
U funkciji je od unesenog broja potrebno kreirati novi broj teko što će se poredak cifri unesenog broja obrnuti. Prilikom obrtanja potrebno je odbaciti neparne cifre.
Npr. Za uneseni broj 1234567 obrnuti broj bez neparnih cifara je 642.*/

#include <iostream>

using namespace std;
int obrnuti(int& broj);


void main()
{
	int n;
	do
	{
		cout << "Unijeti n: ", cin >> n;
	} while (n<=5 || n>= 5000000);
	cout << obrnuti(n) << endl;
	//cout << n << endl; // ispis n da vidis jesi li dobro poslo broj n
}

int obrnuti(int& broj)
{
	int zadnja;
	int novi = 0;
	while (broj>0)
	{
		zadnja = broj % 10;
		if (zadnja % 2 == 0)
		{
			novi = novi * 10 + zadnja;
			broj /= 10;
		}
		else
			broj /= 10;
	}
	broj = novi;

	return broj;
}
