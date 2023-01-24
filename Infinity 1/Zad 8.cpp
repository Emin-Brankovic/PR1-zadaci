/*/*Omoguciti unos dva broja X i Y iz intervala od 10 do 5000. Kreirati program koji ce pronaci i ispisati sve brojeve od X do Y
(ukljucujuci granicne vrijednosti) za koje važi da je obrnuti broj djeljiv sa njegovom sumom cifara.
Za olakšanje rješenja zadataka napraviti funkcije za obrtanje poretka cifara i za sumu cifara.*/*/

#include <iostream>

using namespace std;
int obrni(int broj);
int sum(int broj);

void main()
{
	int x, y;
	do
	{
		cout << "Unijeti broj x: ", cin >> x;
	} while (x<11 || x>5000);
	do
	{
		cout << "Unijeti broj y: ", cin >> y;
	} while (y < 11 || y>5000 && y<x);

	for (int i = x; i <= y; i++)
	{
		if (obrni(i) % sum(i) == 0)
			cout << i << endl;
	}
}

int obrni(int broj)
{
	int zadnja,novi=0;
	while (broj>0)
	{
		zadnja = broj % 10;
		novi = novi * 10 + zadnja;
		broj /= 10;
	}
	return novi;
}

int sum(int broj)
{
	int sum = 0;
	while (broj>0)
	{
		sum += broj % 10;
		broj /= 10;
	}
	return sum;
}
