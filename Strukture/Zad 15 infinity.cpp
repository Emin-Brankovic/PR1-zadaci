/*Kreirati dvodimenzionalni dinamički niz čiji su elementi objekti tipa fudbaler ( fudbaler je struktura čija su obilježja data u nastavku).

struct fudbaler{
int ID;
char*ime_i_Prezime;
char* pozicija;//prihvati samo slova N, O i V (napad, vezni i odbrana);
int *broj_golova;
};
Omogućiti korisniku da unese dimenzije niza te omogućiti unos elemenata. Redovi 2D niza predstavljaju različite klubove, a kolone različite fudbalere (igrače). Radi jednostavnosti rješenja, predpostaviti da svaki klub ima isti broj fudbalera.Ovisno o unesenoj poziciji (N,O ili V) identificira se da li je dati fudbaler napadač,odbrambeni ili vezni igrač. U različitim klubovima mogu igrati različiti brojevi napadača, veznih igrača ili odbrambenih igrača.

(Npr. klub 1 može imati 10 veznih, 3 napadača i 5 odbrambenih igrača, dok klub 2 može imati 12 veznih, 2 napadača i 6 odbrambenih igrača i sl.)

Izračunati i ispisati prosječan broj golova po poziciji igrača za sve klubove. Zatim omogućiti korisniku izbor jednog tipa fudbalera (N,O ili V) i prema korisničkom izboru pronaći klub koji ima najbolji prosjek postignutih zgoditaka tog tipa igraca (npr. ako se unese slovo V za klub 1 računa se prosjek za 10 veznih igrača dok se za klub 2 računa prosjek 12 veznih igrača i ti prosjeci se porede).

(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača. Obavezno voditi računa o dealociranju dinamički alocirane memorije.)*/


#include <iostream>

using namespace std;
struct fudbaler {
	int ID;
	//char* ime_i_Prezime;
	char* pozicija;//prihvati samo slova N, O i V (napad, vezni i odbrana);
	int* broj_golova;

	fudbaler()
	{
		this->ID = 0;
		this->pozicija = new char;
		this->broj_golova = new int;
		
	}
	~fudbaler()
	{
		delete pozicija;
		delete broj_golova;
	}
};
void unos(fudbaler** matrica, int red, int kol);
void ispis(fudbaler** matrica, int red, int kol);
void prosjekGolovaPoz(fudbaler** matrica, int red, int kol);
int getNajboljaPozKluba(fudbaler** matrica, int red, int kol, char slovo);

void main()
{
	int red, kol;
	char slovo;
	cout << "Unijeti redove: ", cin >> red;
	cout << "Unijeti kolone: ", cin >> kol;
	fudbaler** matrica = new fudbaler * [red];
	for (int i = 0; i < red; i++)
		*(matrica + i) = new fudbaler[kol];

	unos(matrica, red, kol);
	ispis(matrica, red, kol);
	prosjekGolovaPoz(matrica, red, kol);
	cout << "Unijeti poziciju(n,v,o) za pretragu: ", cin >> slovo;
	cout << "Najbolji ekipa po poziciji " << slovo << " je: " << getNajboljaPozKluba(matrica, red, kol, slovo);
	// DEALOKACIJA
	for (int i = 0; i < red; i++)
		delete[] * (matrica + i);
	delete[] matrica;
	matrica = nullptr;
}

void unos(fudbaler** matrica,int red,int kol)
{
	
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			(*(matrica+i)+j)->ID = 1 + rand() % ((100 + 1) - 1);
			do
			{
			cout << "Unesite poziciju n, o i v (napad, vezni i odbrana)" << endl;
			cin >> *(*(matrica+i)+j)->pozicija;

			} while (*matrica[i][j].pozicija != 'v' && *matrica[i][j].pozicija != 'o' && * matrica[i][j].pozicija != 'n');
			*(*(matrica+i)+j)->broj_golova= 0 + rand() % ((15 + 1) - 1);

		}
	}
}

void ispis(fudbaler** matrica, int red, int kol)
{

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			cout << "ID: " << (*(matrica + i) + j)->ID << "--- ";
			cout <<"Pozicija: " << *(*(matrica + i) + j)->pozicija << "---";
			cout <<"Broj golova:  " << *(*(matrica + i) + j)->broj_golova << endl;

		}
		cout << endl;
	}
}

void prosjekGolovaPoz(fudbaler** matrica, int red, int kol)
{
	int sumN = 0, sumO = 0, sumV = 0;
	int br1=0, br2=0, br3 = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			if (*(*(matrica + i) + j)->pozicija == 'n')
			{
				sumN += *(*(matrica + i) + j)->broj_golova;
				br1++;
			}
			else if (*(*(matrica + i) + j)->pozicija == 'v')
			{
				sumV += *(*(matrica + i) + j)->broj_golova;
				br2++;
			}
			else if (*(*(matrica + i) + j)->pozicija == 'o')
			{
				sumO += *(*(matrica + i) + j)->broj_golova;
				br3++;
			}
		}
	}
	cout << "Prosjek golova napadaca: " << float(sumN / br1) << endl;
	cout << "Prosjek golova veznih: " << float(sumV / br2) << endl;
	cout << "Prosjek golova odbranbenih: " << float(sumO / br3) << endl;
}

int getNajboljaPozKluba(fudbaler** matrica, int red, int kol,char slovo)
{
	float* prosjek = new float[red];
	int indeks = 0;
	for (int i = 0; i < red; i++)
	{
		float sum = 0;
		float br = 0;	
		for (int j = 0; j < kol; j++)
		{
			if (*(*(matrica + i) + j)->pozicija == slovo)
			{
				sum += *(*(matrica + i) + j)->broj_golova;
				br++;
			}
		}
		prosjek[i] = sum/br;
	}
	for (int i = 0; i < kol; i++)
	{
		if (*(prosjek + i) > *(prosjek + indeks))
		{
			indeks = i;
		}
		
	}
	delete[] prosjek;
	prosjek = nullptr;
	return indeks;
}
