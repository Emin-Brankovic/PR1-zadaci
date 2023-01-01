#include <iostream>

using namespace std;
int suma(int n, int i, int j, int granicaJ, int sum);


void main()
{
	int n;
	do {
		cout << "Unesite n: " << endl;
		cin >> n;
	} while (n <= 5);
	cout << suma(n, 1, 5, 10, 0);
}


int suma(int n, int i, int j, int granicaJ, int sum)
{
	if (i > n) return sum;
	if (j > granicaJ) return suma(n, i + 1, j=0, granicaJ, sum);

	return suma(n, i, j + 1, granicaJ, sum += (pow(i, 2) * j - pow(j, 2) * i));
}
