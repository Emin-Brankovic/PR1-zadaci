#include <iostream>

using namespace std;
int suma(int n, int i, int sum);

void main()
{
	int n;
	do {
		cout << "Unesite n: " << endl;
		cin >> n;
	} while (n < 0);

	cout << suma(n, n, 0) << endl;
}

int suma(int n, int i,int sum)
{
	// Base
	if (i > 2 * n) return sum;

	// Rekurzija
	return suma(n, i + 1, sum += pow(2, abs(i - 2)));
}
