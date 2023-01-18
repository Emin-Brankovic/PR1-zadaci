/*Napisati program koji simulira bacanje 3 kockice (jedna kockica ima 6 strana i na tim stranama su brojevi 1 - 6). 
Simuliranje bacanja svake kockice ostvariti funkcijom rand() % 6 + 1. 
Simulirati konstantno bacanje sve tri kockice dok se u dva uzastopna bacanja ne desi da se dobiju isti brojevi na sve tri kockice 
(npr. u šestom bacanju se dobiju brojevi 2, 2, 2, a u sedmom 4, 4, 4 na sve tri kockice).
Ispisati koliko je ukupno bilo bacanja dok se nije ispunio navedeni uslov.
Nije potrebno tražiti bilo kakav unos od korisnika.*/

#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	srand(time(0));
	int brojac = 0, bacanja = 0;
	int k1, k2, k3;
	do
	{
		k1 = rand() % 6 + 1;
		k2 = rand() % 6 + 1;
		k3 = rand() % 6 + 1;
		if (k1 == k2 && k2 == k3)
			brojac++;
		else
			brojac = 0;

		
		bacanja++;
	} while (brojac < 2);

	cout << "Ukupan broj bacanja: " << bacanja << endl;
}
