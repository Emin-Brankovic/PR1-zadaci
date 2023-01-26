/*Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo). Napisati program koji će najprije učitati dva prirodna broja n1 i n2.
Ako je n1 > n2 zamijeniti n1 sa n2. Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja.
U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja obavlja zadani posao.*/
#include <iostream>

using namespace std;
bool isProst(int broj);

void main()
{
	int n1, n2,temp;
	cout << "N1: ", cin >> n1;
	cout << "N2: ", cin >> n2;
	if (n1 > n2)
	{
		temp = n1;
		n1 = n2;
		n2 = temp;
	}
	for (int i = n1; i <= n2; i+=2)
	{
		if (i % 2 != 0) i++;
		for (int j = i / 2, k = i / 2; j < i; j++, k--)
		{
			if (isProst(j) && isProst(k))
			{
				cout << j << "+" << k << "=" << i << endl;
				break;
			}

		}
	}
}

bool isProst(int broj)
{
	if (broj < 2) return false;
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0) return false;
	}
	return true;
}
