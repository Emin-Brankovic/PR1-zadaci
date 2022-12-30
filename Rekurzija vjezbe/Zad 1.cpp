//Suma faktorijela od 1 do 5

#include <iostream>

using namespace std;
int faktorijel(int n/*int*/);

void main()
{
	int suma = 0;
	for (int i = 0; i <= 5; i++)
		suma += faktorijel(i);
	cout << suma;
}

int faktorijel(int n/*int sum*/)
{
	//Base
	if (n == 0 || n == 1) return 1;

	//Rekurzija
	return n * faktorijel(n - 1); 
}
