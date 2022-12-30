#include <iostream>

using namespace std;
float suma(float n, float i,float sum);

void main()
{
	int n;
	do {
		cout << "Unesite n: " << endl;
		cin >> n;
	} while (n < -5 || n == 0);
	cout << suma(n, -5,0);
}

float suma(float n, float i, float sum)
{
	// Base
	if (i == n) return sum+=1;

	//Rekurzija
	sum += abs(i / n); //0+=-5/5
	return suma(n, i + 1,sum); // -5+1
}
