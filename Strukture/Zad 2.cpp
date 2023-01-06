#include <iostream>

using namespace std;
struct Ucenik
{
	Ucenik()
	{
		rbr = 0;
		ime;
		prezime;
		opravdani=0;
		neopravdani = 0;
	}
	void unos()
	{
		cout << "Unijeti redni broj: ", cin >> rbr;
		cout << "Unijeti ime: ", cin >> ime;
		cout << "Unije prezime: ", cin >> prezime;
		cout << "Unijeti opravdane: ", cin >> opravdani;
		cout << "Unijeti neopravdane: ", cin >> neopravdani;
	}
	void ispis(int indeks)
	{
		cout << "Redni broj ucenika: " << rbr << endl;
		cout << "Ime: " << ime << endl;
		cout << "Prezime: " << prezime << endl;
		cout << "Opravdani: " << opravdani << endl;
		cout << "Neopravdani: " << neopravdani << endl;
		if (indeks < 2)
			cout << "-----------------";
	}

	int rbr, opravdani, neopravdani;
	string ime, prezime;
};
void main()
{
	const int size = 3;
	Ucenik ucenici[size];
	for (int i = 0; i < size; i++)
	{
		ucenici[i].unos();
		system("cls");
	}
	for (int i = 0; i < size; i++)
		ucenici[i].ispis(i);
}
