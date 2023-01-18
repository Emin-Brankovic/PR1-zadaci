/*Napisati program kojim će se izračunati 20 uzastopnih vrijednosti brzine i pređenog puta objekta u slobodnom padu u razmaku od po 3 sec. 
Prilikom računanja potrebno je i ispisati na ekran uzastopno brzinu i pređeni put zajedno za svaki period od 3sec. Obratiti pažnju da se koriste ispravni tipovi podataka.
Formula za brzinu slobodnog pada je: v = g * t; g=9.81 Formula za pređeni put pri slobodnom padu je: s=(g/2)*pow(t,2)*/

#include <iostream>

using namespace std;

void main()
{
	int time = 3;
	const float g = 9.81;
	for (int i = 0; i < 20; i++)
	{
		cout << "Situacija u " << time << " sekundi: " << endl;
		cout << "Brzina: " << double(g * time) << endl;
		cout << "Predjeni put je: " << double((g / 2) * pow(time, 2)) << endl;
		cout << "-----------------------------------------------" << endl;
		time += 3;
	}

}
