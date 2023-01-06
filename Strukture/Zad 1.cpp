#include <iostream>

using namespace std;
struct Kruznica
{
	float x, y, poluprecnik;
	Kruznica()
	{
		x = 0, y = 0, poluprecnik = 0;
	}
};
void main()
{
	Kruznica k1,k2,k3,k4;
	k1.x = 2, k1.y = 3;
	k2.x = -1, k2.y = 1;
	k3.x = -3, k3.y = -5;
	k4.x = 2, k4.y = -4;
	cout << "Unijeti poluprecnik k1: ", cin >> k1.poluprecnik;
	k2.poluprecnik = k1.poluprecnik;
	k3.poluprecnik = 2 * k2.poluprecnik;
	k4.poluprecnik = k2.poluprecnik + k3.poluprecnik;
	cout << k1.poluprecnik << " " << k2.poluprecnik << " " << k3.poluprecnik << " " << k4.poluprecnik;
} 
