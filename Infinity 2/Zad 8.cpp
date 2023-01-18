#include <iostream>
#include <time.h>
using namespace std;
bool isPrime(int& broj);
int faktorijel(int broj);
//int fakorijelSum();

void main()
{
	int prvi = 1, drugi = 0, fibBroj, temp, zbir = 0;
	for (int i = 0; i < 100; i++)
	{
		fibBroj = prvi + drugi;
		if (isPrime(fibBroj))
		{
			zbir += faktorijel(fibBroj);
		}

		temp = prvi; 
		prvi = fibBroj;
		drugi = temp;
	}
	cout << zbir << endl;
}

bool isPrime(int& broj)
{
	if (broj < 2) return false;
	for (int i = 2; i < broj / 2; i++)
		if (broj % i == 0) return false;
	return true;
}



int faktorijel(int broj)
{
	int faktorijel = 1;
	for (int i = 1; i <= broj; i++)
	{
		faktorijel *= i;
	}
	return faktorijel;
}
