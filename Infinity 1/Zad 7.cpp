/* Napišite program, poštujući sve faze procesa programiranja, koji će ispisati sve troznamenkaste brojeve koji su jednaki sumi faktorijela svojih znamenki.
ABC = A! + B! + C!
*/
#include <iostream>

int faktorijel(int broj);
bool provjera(int broj);

using namespace std;

void main()
{
	cout << provjera(145);
}

bool provjera(int broj)
{
	int cifra,sum=0,novi;
	novi = broj;
	while (novi>0)
	{
		cifra = novi % 10;
		sum+=faktorijel(cifra);
		novi /= 10;
	}
	if (sum == broj)
		return true;
	return false;
}

int faktorijel(int broj)
{
	if (broj == 0) return 1;
	if (broj == 1) return 1;

	return broj * faktorijel(broj - 1);
}
