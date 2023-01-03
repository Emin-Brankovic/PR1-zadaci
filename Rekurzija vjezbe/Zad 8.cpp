#include <iostream>

using namespace std;
int racun(int i, int j, int p, int sum);

void main()
{
	cout << racun(1, -5, 1, 0);
}

int racun(int i, int j, int p, int sum)
{
	if (i > 10) return p;
	if (j > 5) return racun(i + 1, j = -5, p *= sum, sum);

	return racun(i, j + 1, p, sum += (i - 1) * (1 - j));
}
