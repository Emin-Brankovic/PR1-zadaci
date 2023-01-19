/* Napišite program, u kojem ćete omogućiti unos dva prirodna broja manja od 500 koji predstavljaju granice intervala, 
te pronaći i ispisati kojom znamenkom završava najveći prosti broj u zadanom intervalu ne uključujući granične vrijednosti.*/
#include <iostream>

using namespace std;
bool isProst(int broj);
int zadnjNajveci(int a, int b);

void main()
{
	int a, b;
	do
	{
		cout << "Unijeti prvi broj: ", cin >> a;
		cout << "Unijeti drugi broj koji mora biti veci od prvog: ", cin >> b;
	} while (a>=500 || b>=500 || b<a);
	cout << "Zadnja cifra najveceg prostog broj od a do b je: " << zadnjNajveci(a, b) << endl;
}

bool isProst(int broj)
{
	if (broj < 2) return false;
	for (int i = 2; i < broj / 2; i++)
		if (broj % i == 0) return false;
	return true;
}

int zadnjNajveci(int a, int b)
{
	int max = INT_MIN;
	for (int i = a; i < b; i++)
	{
		if (i > max)
			max = i;
	}
	return max % 10;
}
