Napišite program u kojem ćete omogućiti unos prirodnog broja. Provjerite je li broj trivijalan (prost) uz pomoć funkcije: bool trivijalan (int);.
U slučaju da broj nije trivijalan (prost) odredite i ispište sve njegove djelitelje uz pomoć funkcije: void djelitelji(int);

#include <iostream>

using namespace std;
bool isProst(int n);
void Djeljitelji(int n);

void main()
{
	int broj;
	do
	{
		cout << "Unije ti pozitivan broj za provjeru: ", cin >> broj;
	} while (broj<1);

	if (isProst(broj))
		cout << "Uneseni broj je prost" << endl;
	else
	{
		Djeljitelji(broj);
	}

}

bool isProst(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i < n/ 2; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

void Djeljitelji(int n)
{
	cout << "Djeljitelji broja " << n<<" su: ";
	for (int i = 1; i <= n/2; i++)
	{
		if (n % i == 0)
			cout << i << " ";
	}
	cout << n << endl;
}
