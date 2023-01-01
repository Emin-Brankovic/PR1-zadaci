#include <iostream>

using namespace std;
float proizvod(int n, int i,float sum);

void main()
{
	int n;
	do
	{
		cout << "Unesite n: " << endl;
		cin >> n;
	} while (n<1 || n>10);
	cout << proizvod(n, 1, 1);
}

float proizvod(int n, int i, float sum)
{
	if (i > n) return sum;

	return proizvod(n, i + 1, sum *= pow(i + 1, -1));
}
