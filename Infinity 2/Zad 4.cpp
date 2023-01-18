/*Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo).
Napisati program koji će najprije učitati dva prirodna broja n1 i n2 (n2 > n1).
Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja.
(U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja obavlja zadani posao.)*/

#include <iostream>

using namespace std;
bool isProst(int broj);
void goldbach(int n1, int n2);

void main()
{
	int n1, n2;
	do
	{
		cout << "Unijeti broj n1: ", cin >> n1;
		cout << "Unijeti broj n2: ", cin >> n2;
	} while (n1<=0 || n2<=n1);
	goldbach(n1, n2);
}

void goldbach(int n1, int n2)
{
	for (int i = n1; i <= n2; i+=2)
	{
		if (i % 2 != 0)
			i++;

		for (int j = i / 2, k = i / 2; k > 0; j++, k--)
		{
			if (isProst(j) && isProst(k))
			{
				cout << k << "+" << j << "=" << i << endl;
				break;
			}
		}
	}
}

bool isProst(int broj)
{
	if (broj < 2) return false;
	for (int i = 2; i < broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}
