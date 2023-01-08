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
		cout << "-----------------" << endl;
		
	}
	void izostanak()
	{
		int izostanci;
		izostanci = opravdani + neopravdani;
		cout << "-----------------------" << endl;
		cout << "Ukupan broj izostanaka ucenika " << ime << " " << prezime << " je: " << izostanci << endl;
		cout << "-----------------------" << endl;
	}
	static void najNeopravdani(Ucenik ucenici[])
	{
		int najmanje=INT_MAX;
		string ime, prezime;
		for (int i = 0; i < 3; i++)
		{
			if (ucenici[i].neopravdani < najmanje)
			{
				najmanje = ucenici[i].neopravdani;
				ime = ucenici[i].ime;
				prezime = ucenici[i].prezime;
			}
		}
		cout << "Ucenik sa najmanje neopravdanih je " << ime << " " << prezime << endl;
	}
	static void najOpravdani(Ucenik ucenici[])
	{
		int najvise = INT_MIN;
		string ime, prezime;
		for (int i = 0; i < 3; i++)
		{
			if (ucenici[i].neopravdani > najvise)
			{
				najvise = ucenici[i].neopravdani;
				ime = ucenici[i].ime;
				prezime = ucenici[i].prezime;
			}
		}
		cout << "Ucenik sa najvise opravdanih je " << ime << " " << prezime << endl;
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
	for (int i = 0; i < size; i++)
		ucenici[i].izostanak();
	Ucenik::najNeopravdani(ucenici);
	Ucenik::najOpravdani(ucenici);
}
