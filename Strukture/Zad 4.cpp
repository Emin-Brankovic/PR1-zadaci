#include <iostream>

using namespace std;

struct Ucenik
{
	char ime[50],prezime[50];
	int rbr;
	float prosjecna;
	Ucenik()
	{
		ime;
		prezime;
		rbr = 0;
		prosjecna = 0.0f;
	}
	void unos(Ucenik ucenici)
	{
		cout << "Unijeti ime i prezime: ", cin >> ime >> prezime;
		cout << "Unijeti redni broj: ", cin >> rbr;
		cout << "Unijeti prosjecnu ocjenu: ", cin >> prosjecna;
		cout << endl;
	}
	static::Ucenik* najgori(Ucenik* uc1, Ucenik* uc2, Ucenik* uc3)
	{
		if (uc1->prosjecna < uc2->prosjecna && uc1->prosjecna < uc3->prosjecna)
			return uc1;
		else if (uc2->prosjecna < uc1->prosjecna && uc2->prosjecna < uc3->prosjecna)
			return uc2;
		else
			return uc3;
	}
}ucenik1,ucenik2,ucenik3;
void main()
{
	Ucenik* pokNaUcenik;
	ucenik1.unos(ucenik1);
	ucenik2.unos(ucenik2);
	ucenik3.unos(ucenik3);

	
}
