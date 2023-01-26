/*Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa fudbaler (fudbaler je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza. Redovi dvodimenzionalnog niza predstavljaju razlicite timove a kolone prestavljaju igrače u tim timovima. 
Omogućiti korisniku unos svih podataka za sve igrače, te napraviti (i testirati u main funkciji) funkciju koja će pronaći tim sa najvećim prosjekom. 
Zatim napraviti (i testirati u main funkciji) funkciju koja će pronaći igrača sa najviše golova u timu sa najlošijim prosjekom golova.
U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivaca.*/

#include <iostream>
#include <time.h>
using namespace std;
struct fudbaler
{
	int* godRodjenja;
	int* brojIgraca;
	int* golovi;
	fudbaler()
	{
		this->godRodjenja = new int;
		this->brojIgraca = new int;
		this->golovi = new int;
	}
	~fudbaler()
	{
		delete godRodjenja;
		delete brojIgraca;
		delete golovi;
	}
};
void unos(fudbaler** matrica, int red, int kol);
void ispis(fudbaler** matrica, int red, int kol);
void najboljiTim(fudbaler** matrica, int red, int kol);
void najboljiIgrac(fudbaler** matrica, int red, int kol);

void main()
{
	srand(time(0));
	int kol, red;
	cout << "RED: ", cin >> red;
	cout << "KOLONA: ", cin >> kol;
	fudbaler** matrica = new fudbaler * [red];
	for (int i = 0; i < red; i++)
		*(matrica + i) = new fudbaler[kol];
	unos(matrica, red, kol);
	ispis(matrica, red, kol);
	najboljiTim(matrica, red, kol);
	cout << endl;
	najboljiIgrac(matrica, red, kol);
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
			*(*(matrica + i) + j)->brojIgraca = rand() % 30 + 1;
			*(*(matrica + i) + j)->godRodjenja = 1980 + rand() % ((2000 + 1) - 1980);
			*(*(matrica + i) + j)->golovi = rand() % 5;
		}
	}
}
void ispis(fudbaler** matrica, int red, int kol)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			cout << "Broj igraca: " << *(*(matrica + i) + j)->brojIgraca << "--> ";
			cout << "Godina rodjenja: " << *(*(matrica + i) + j)->godRodjenja << "--> ";
			cout << "Broj zabijenih golova: " << *(*(matrica + i) + j)->golovi << endl;
		}
		cout << endl;
	}
}

void najboljiTim(fudbaler** matrica, int red, int kol)
{
	float* prosjekTima = new float[red];
	for (int i = 0; i < red; i++)
	{
		float sum = 0;
		for (int j = 0; j < kol; j++)
		{
			sum += *(*(matrica + i) + j)->golovi;
		}
		*(prosjekTima + i) = sum / kol;
	}
	int indeks = 0;
	for (int i = 0; i < red; i++)
	{
		if (*(prosjekTima + i) > *(prosjekTima + indeks))
			indeks = i;
	}
	cout << "Ekipa sa najboljim prosjekom je: " << endl;

		for (int j = 0; j < kol; j++)
		{
			cout << "Broj igraca: " << *(*(matrica + indeks) + j)->brojIgraca << "--> ";
			cout << "Godina rodjenja: " << *(*(matrica + indeks) + j)->godRodjenja << "--> ";
			cout << "Broj zabijenih golova: " << *(*(matrica + indeks) + j)->golovi << endl;
		}
		delete[]prosjekTima;
		prosjekTima = nullptr;
}

void najboljiIgrac(fudbaler** matrica, int red, int kol)
{
	float* prosjekTima = new float[red]; 
	for (int i = 0; i < red; i++)
	{
		float sum = 0;
		for (int j = 0; j < kol; j++)
		{
			sum += *(*(matrica + i) + j)->golovi;
		}
		*(prosjekTima + i) = sum / kol;
	}
	int indeksTima = 0;
	for (int i = 0; i < red; i++) // trazi najgoru ekipu
	{
		if (*(prosjekTima + i) < *(prosjekTima + indeksTima))
			indeksTima = i;
	}
	// trazis najboljeg  igraca
	int indeksIgraca = 0;
	for (int j = 0; j < kol; j++)
	{
		if (*(*(matrica + indeksTima) + j)->golovi > *(*(matrica + indeksTima) + indeksIgraca)->golovi)
			indeksIgraca = j;
	}
	cout << "Najbolji igrac u najgoroj ekipi je: " << endl;
	cout << "Broj igraca: " << *(*(matrica + indeksTima) + indeksIgraca)->brojIgraca << "--> ";
	cout << "Godina rodjenja: " << *(*(matrica + indeksTima) +indeksIgraca )->godRodjenja << "--> ";
	cout << "Broj zabijenih golova: " << *(*(matrica + indeksTima) + indeksIgraca)->golovi << endl;

	delete[]prosjekTima;
	prosjekTima = nullptr;
}
