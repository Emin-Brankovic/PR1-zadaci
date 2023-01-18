
#include <iostream>
#include <time.h>
using namespace std;
int racun(char slovo, int x, int m);

void main()
{
	int x, m;
	char slovo;
	cout << "Unijeti broj x: ", cin >> x;
	cout << "Unijeti broj m: ", cin >> m;
	cout << "Unijeti slovo za odabir funckije 's' (sin), 'c' (cos), 'q' (sqrt), 'p' (pow): ", cin >> slovo;
		while (slovo != 'p' && slovo != 'q' && slovo != 's' && slovo != 's')
		{
			cout << "Pogresan unos, pokusajte ponovo: ", cin >> slovo;
		}
	cout << "Suma funkcije je: " << racun(slovo, x, m) << endl;
}

int racun(char slovo,int x,int m)
{
	int sum = 0;
	switch (slovo)
	{
	case 's':
		for (int i = 1; i <= m; i++)
			sum += sin(x) + i;
		break;
	case 'c':
		for (int i = 1; i <= m; i++)
			sum += cos(x) + i;		
		break;
	case 'q':	
		for (int i = 1; i <= m; i++)
			sum += sqrt(x) + i;
		break;
	case 'p':		
		for (int i = 1; i <= m; i++)
			sum += pow(x, 3) + i;
		break;
	default:
		break;
	}
	return sum;
}
