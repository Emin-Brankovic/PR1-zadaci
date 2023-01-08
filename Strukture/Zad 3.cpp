/*Kreirajte niz objekata nezaposleni od 5 elemenata sa sljedećim obilježjima: 
·ime, prezime, · spol (niz karaktera), · godina rođenja (cijeli broj) ·godine staža (realni broj). 
  Kreirajte funkciju: · za unos obilježja jednog objekta i upotrijebite ju za unos obilježja svih elemenata niza · ispis obilježja jednog objekta;  
za prebrojavanje svih nezaposlenih koji imaju više godine staža od vrijednosti koju unese korisnik; ·  za pronalaženje svih ženskih osoba među nezaposlenim; 
za ispis obilježja svakog od pronađenih objekata koristite funkciju ispis;*/

#include <iostream>

using namespace std;
struct Nezaposlen
{
	Nezaposlen()
	{
		rodjenje = 0;
		staz = 0;
		ime;
		prezime;
		spol;
	}
	void unos()
	{
		cout << "Unijeti ime i prezime: ", cin >> ime >> prezime;
		cout << "Unijeti godinu rodjenja: ", cin >> rodjenje;
		cout << "Unijeti spol(M/Z) : ", cin >> spol;
		cout << "Unijeti godine radnog staza: ", cin >> staz;
		cout << endl;
	}
	void ispis()
	{
		cout << "Ime i prezime: " << ime << " " << prezime << endl;
		cout << "Godina rodjenja: " << rodjenje << endl;
		cout << "Spol: " << spol << endl;
		cout << "Godine radnog staza: " << staz << endl;
		cout << endl;
	}
	static int godineStaza(Nezaposlen nezaposleni[],int unseneGodine)
	{
		int brojac = 0;
		for (int i = 0; i < 5; i++)
		{
			if (nezaposleni[i].staz > unseneGodine)
				brojac++;
		}
		return brojac;
	}
	static void zene(Nezaposlen nezaposleni[])
	{
		cout << "Nezaposleni koji su zenskog spola su: " << endl;
		for (int i = 0; i < 5; i++)
		{
			if (nezaposleni[i].spol == 'Z' || nezaposleni[i].spol == 'z')
			{
				nezaposleni[i].ispis();
			}
		}
	}
	char ime[50];
	char prezime[50],spol;
	int rodjenje, staz;

};
void main()
{
	int staz;
	Nezaposlen nezaposleni[5];
	for (int i = 0; i < 5; i++)
	{
		nezaposleni[i].unos();
		system("cls");
	}
	nezaposleni[3].ispis();
	cout << "Unijeti godine staza: ", cin >>staz;
	cout << "Broj osoba koje imaju vise godina staza od unesenih je: " << Nezaposlen::godineStaza(nezaposleni, staz) << endl;
	cout << "-----------------------------" << endl;
	Nezaposlen::zene(nezaposleni);
}
