/*Napisati program koji će omogućiti korisniku unos broja n (uz uslov 10 <= n <= 1000).
Zatim simulirati unos n slučajnih vrijednosti. Simuliranje unosa ostvariti funkcijom rand()% 1000 + 1. 
Izračunati statitičke podatke u kojem procentu se od n generisanih slučajnih vrijednosti pojavljuje savršen broj . 
Za neki broj se kaze da je savrsen ako je jednak sumi svih svojih djelilaca (ne uključujući njega samog) .
Npr. 28 je savršen broj : njegovi djelioci su 1 , 2 , 4 , 7 i 14 , a 1 + 2 + 4 + 7 + 14 = 28 Jedini savršeni brojevi od 1 do 100 su brojevi 6 i 28*/

#include <iostream>
#include<time.h>
using namespace std;
bool isSavrsen(int broj);

void main()
{
	srand(time(0));
	int n, m;
	float brojac=0;
	do
	{
		cout << "Unijeti broj: ", cin >> m;
	} while (m < 10 || m>1000);

	for (int i = 0; i < m; i++)
	{
		n=rand()%1000+1;
		if (isSavrsen(n))
			brojac++;
	}
	cout << "Savrsen broj se pojavio : " << round((brojac / m) * 100) << "%" << " u " << m << " broju ponavljanja" << endl;
}

bool isSavrsen(int broj)
{
	int sum = 0;
	for (int i = 1; i <= broj / 2; i++) 
	{
		if (broj % i == 0)
			sum += i;
	}
	if (sum == broj) return true;
	else return false;
}
