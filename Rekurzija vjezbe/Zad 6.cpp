#include <iostream>

using namespace std;
float suma(int n, int i, int j, float sum);
float suma1(int n, int i, int j, float sum);

void main()
{
	int n;
	do {
		cout << "Unesite n: " << endl;
		cin >> n;
	} while (n < 1 || n >= 16);
	cout << suma(n, 1, 5, 0) << endl;
	cout << suma1(n, 1, 5, 0) << endl;
}

float suma(int n, int i, int j, float sum)
{
	if (j > 10)
	{
		j = 5;
		sum += float(pow(i, 2));
		i = i + 1;
	}
	if (i > n) return sum;
	
	return suma(n, i, j + 1, sum += float(pow(i - j, 2) / pow(j, 2)));
}

// DRUGI NACIN 

float suma1(int n, int i, int j, float sum)
{
	if (i > n) return sum;
	if (j > 10) return suma(n, i + 1, j = 5, sum += pow(i, 2));

	return suma(n, i, j + 1, sum += float(pow(i - j, 2) / pow(j, 2)));
}
