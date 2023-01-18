#include <iostream>

using namespace std;
int zamjena(int n);


void main()
{
	int n;
	do
	{
		cout << "Unijeti broj n: ", cin >> n;
	} while (n<=0);
	cout << zamjena(n);
}



int zamjena(int n)
{
	int zadnja = 0;
	int novi = 0, brojac = 0;
	while (n>0)
	{
		zadnja = n % 10;
		if (zadnja % 2 == 0)
		{
			zadnja = 5;
			novi = novi + zadnja * pow(10, brojac);
			n /= 10;
		}
		else
		{
			novi = novi + zadnja * pow(10, brojac);
			n /= 10;
		}
		brojac++;
	}
	return novi;
}
