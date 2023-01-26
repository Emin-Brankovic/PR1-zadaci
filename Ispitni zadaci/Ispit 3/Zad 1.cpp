/*Poštujući sve faze programiranja napisati program koji omogućava unos prirodnog broja n preko tastature te izračunava sumu:
1/(2n+1)^2*/
#include <iostream>

using namespace std;

void main()
{
	float sum = 0;
	int n;
	do
	{
		cout << "N: ", cin >> n;
	} while (n<=0);
	for (int i = 1; i <= n; i++)
		sum += 1 / pow((2 * i) + 1, 2);
	cout << sum;
}
