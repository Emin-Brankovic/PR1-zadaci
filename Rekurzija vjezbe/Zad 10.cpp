//Napišite program u kojem ćete upotrijebiti rekurzivnu funkciju čiji je zadatak računanje sume
//kvadrata od 1 do n (n je prirodan broj).

#include <iostream>

using namespace std;
int suma(int sum, int n, int i);

void main()
{
	int n;
	do
	{
		cout << "N: ", cin >> n;
	} while (n<1);
	cout << suma(0, n, 1);
}

int suma(int sum, int n,int i)
{
	if (i > n) return sum;
	return suma(sum += pow(i, 2),n,i+1);
}
