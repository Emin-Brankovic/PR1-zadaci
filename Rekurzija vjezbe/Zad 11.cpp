//Napišite program u kojem ćete upotrijebiti rekurzivnu funkciju čiji je zadatak računanje sume kvadrata od n do m (n i m su prirodni brojevi). 

#include <iostream>

using namespace std;
int suma(int m, int n, int sum);

void main()
{
	int n, m;
	do
	{	do
		{
			cout << "N: ", cin >> n;
		} while (n<1);
		do
		{
			cout << "M: ", cin >> m;
		} while (m<1);
	

	} while (n>m);
	cout << suma(m, n, 0);
}

int suma(int m, int n, int sum)
{
	if (n > m) return sum;
	return suma(m, n + 1, sum += pow(n, 2));
}
