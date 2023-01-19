/*Napišite program u kojem ćete omogućiti unos dva prirodna broja manja od 500 koji predstavljaju granice intervala, 
te pronaći i ispisati kojom cifrom/znamenkom završava umnožak svih prostih brojeva u zadanom intervalu uključujući granične vrijednosti.*/
#include <iostream>

using namespace std;
bool isProst(int broj);
int zadnjiSume(int a, int b);

void main()
{
	int a, b;
	do
	{
		cout << "Unijeti prvi broj: ", cin >> a;
		cout << "Unijeti drugi broj koji je veci od prvog: ", cin >> b;
	} while ( a>=500 || b>=500 && b<a);

	cout << "Zadnja cifra sume prosti brojeva je: " << zadnjiSume(a, b) << endl;
}

bool isProst(int broj)
{
	if (broj < 2)return false;
	for (int i = 2; i < broj / 2; i++)
		if (broj % i == 0) return false;
	return true;
}

int zadnjiSume(int a, int b)
{
	int sum = 1;
	for (int i = a; i <= b; i++)
	{
		if (isProst(i))
			sum *= i;
	}
	return sum%10;
}
