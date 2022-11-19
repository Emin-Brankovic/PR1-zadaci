#include <iostream>
#include <cmath>

using namespace std;
bool isBinarni(int x);
int getDigits(int x);
int getAnd(int x, int y);


void main()
{
	int b1, b2;
	do
	{
		do
		{
			cout << "Unesite binarni broj: ", cin >> b1;
		} while (!isBinarni(b1));
		do
		{
			cout << "Unesite binarni broj: ", cin >> b2;
		} while (!isBinarni(b2));
		
	} while (getDigits(b1) != getDigits(b2));

	cout << "Rezultat je: " << getAnd(b1, b2) << endl;
}


bool isBinarni(int x)
{
		x=abs(x);
	while (x > 0)
	{
		int temp;
		temp = x % 10;
		if (temp > 1)
			return false;
		x /= 10;
	
		
	}
	return true;
}

int getDigits(int x)
{
	int brojac = 0;
	x = abs(x);
	while (x > 0)
	{
		x /= 10;
		brojac++;
		if (x == 0)
			brojac++;
	}
	return brojac;
}

int getAnd(int x, int y)
{
	
	int rez = 0;
	int brojcifara = getDigits(x);
	
	for (int i = 0; i < brojcifara; i++)
	{
		rez += ((x % 10) * (y % 10)) * int(pow(10, i));
		x /= 10;
		y /= 10;
	}
	return rez;
}
