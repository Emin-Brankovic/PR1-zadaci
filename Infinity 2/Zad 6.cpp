/*Napisati program koji će omogućiti korisniku unos broja n ( 10 <= n <= 1000). 
Zatim simulirati n bacanja kockice (kockica ima 6 strana i na tim stranicama su brojevi 1-6).
Simuliranje bacanja svake kockice ostvariti funkcijom rand() % 6 + 1. 
Izračunati statičke podatke u kojem procentu ukupnog bacanja se dobiva svaki od mogućih brojeva 1-6. 
Obavezno koristiti switch statement za zbrajanje rezultata bacanja kockice.
Napomena: Po želji kreirati dodatne funkcije da se olakša rješavanje zadataka.*/

#include <iostream>
#include<time.h>
using namespace std;
void bacanj(int n);

void main()
{
	srand(time(0));
	int n;
	do
	{
		cout << "Unijeti broj bacanja: ", cin >> n;
	} while (n<10 || n>1000);
	bacanj(n);

}

void bacanj(int n)
{
	int k;
	float br1 = 0, br2 = 0, br3 = 0, br4 = 0, br5 = 0, br6 = 0;

	for (int i = 0; i < n; i++)
	{
		k = rand() % 6 + 1;
		switch (k)
		{
		case 1:
			br1++;
			break;
		case 2:
			br2++;
			break;
		case 3:
			br3++;
			break;
		case 4:
			br4++;
			break;
		case 5:
			br5++;
			break;
		case 6:
			br6++;
			break;
		default:
			break;
		}
	}
	cout << "Procenat bacanja za broj 1: " << round((br1 / n) * 100) << "%" << endl;
	cout << "Procenat bacanja za broj 2: " << round((br2 / n) * 100) << "%" << endl;
	cout << "Procenat bacanja za broj 3: " << round((br3 / n) * 100) << "%" << endl;
	cout << "Procenat bacanja za broj 4: " << round((br4 / n) * 100) << "%" << endl;
	cout << "Procenat bacanja za broj 5: " << round((br5 / n) * 100) << "%" << endl;
	cout << "Procenat bacanja za broj 6: " << round((br6 / n) * 100) << "%" << endl;

}
