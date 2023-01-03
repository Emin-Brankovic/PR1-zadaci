#include <iostream>

using namespace std;
void binarni(int i, int j, int k);

void main()
{
	binarni(0, 0, 0);
}

void binarni(int i, int j, int k)
{
	if (k > 1) k= 0, j=j+ 1;
	if (j > 1) i = i + 1, j = 0, k = 0;
	//Base case
	if (i > 1) return;
	// Rekurzija
	cout << i << " " << j << " " << k << " " <<" AND "<<(i && j && k)<< endl;
	binarni(i, j, k + 1);
}
