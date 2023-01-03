//Napišite program u kojem ćete upotrijebiti rekurzivnu funkciju čiji je zadatak  računanje n-tog člana Fibonacci-jevog niza. 

#include <iostream>

using namespace std;
int fibniz(int n);

void main()
{
	int n;
	do
	{
		cout << "N: ", cin >> n;
	} while (n<2);
	cout << "N clan fib niza je: " << fibniz(n) << endl;
}

int fibniz(int n)
{
	if (n == 1) return 1;
	if (n == 0) return 0;

	return fibniz(n - 1) + fibniz(n - 2);
}
