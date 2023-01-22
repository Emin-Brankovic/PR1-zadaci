/*Poštujući sve faze procesa programiranja, napisati program koji korisniku omogućava unos cijelog broja N, 
te izračunava vrijednost sume faktorijela neparnih brojeva u intervalu [1, N]. Suma faktorijela prikazana je sljedećom formulom: S = 1! + 3! + 5! + ... + N!*/
#include <iostream>

using namespace std;

void main()
{
	int a=5,sum=0;
	//do
	//{
	//	cout << "Unijeti broj a: ", cin >> a;
	//} while (a < 100000);
	for (int i = 1; i <= a; i++)
	{
		int faktorijel = 1;
		if (i % 2 != 0)
		{
			for (int j = 1; j <= i; j++)
				faktorijel *= j;
			sum += faktorijel;
		}
	
	}
	cout << sum;
}
