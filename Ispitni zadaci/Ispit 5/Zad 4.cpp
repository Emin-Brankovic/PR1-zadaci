/*Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vremenska_prognoza (prognoza je struktura čija su obilježja data u nastavku). 
Omogućiti korisniku da unese dimenzije niza.Redovi dvodimenzionalnog niza predstavljaju različite meteorologe, a kolone različite dane.
Omogućiti korisniku unos svih prognoza za sve meteorologe. 
Dodatno kreirati jednodimenzionalni dinamički niz čija će veličina biti uneseni broj dana u koji ćete omogućiti unos stvarnih izmjerenih vrijednosti za dane.
Zatim napraviti funkciju koja će pronaći i ispisati index meteorologa čija je prognoza dnevnih temperatura bila najtačnija, odnosno koji je imao najmanju grešku u procjeni temperatura.
Pomoć: suma svih razlika između prognozirane i stvarne temperature za jednog meteorologa predstavlja njegovu ukupnu grešku.
U ovom zadatku je zabranjeno indeksirati elemente u niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.*/

#include <iostream>
#include<cmath>
using namespace std;
struct vremenska_prognoza
{
	char* padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
	float* temperatura;
	float* vlaznost_vazduha;
	vremenska_prognoza()
	{
		this->padavine = new char[10];
		this->temperatura = new float;
		this->vlaznost_vazduha = new float;
	}
	~vremenska_prognoza()
	{
		delete[] padavine;
		padavine = nullptr;
		delete temperatura;
		delete vlaznost_vazduha;
	}
};
void unos(vremenska_prognoza** matrica, int red, int kol);
void ispis(vremenska_prognoza** matrica, int red, int kol);
void unosStvarnih(vremenska_prognoza* niz, int kol);
int meteorologTacan(vremenska_prognoza** matrica, int red, int kol, vremenska_prognoza* niz);


void main()
{
	int red, kol;
	cin >> red;
	cin >> kol;
	vremenska_prognoza** matrica = new vremenska_prognoza * [red];
	vremenska_prognoza* niz = new vremenska_prognoza[kol];
	for (int i = 0; i < red; i++)
		*(matrica + i) = new vremenska_prognoza[kol];
	unos(matrica, red, kol);
	ispis(matrica, red, kol);
	unosStvarnih(niz, kol);
	cout << meteorologTacan(matrica, red, kol, niz) << endl;

	for (int i = 0; i < red; i++)
		delete[] * (matrica + i);
	delete[] matrica;
	matrica = nullptr;
	delete[] niz;
	niz = nullptr;
}


void unos(vremenska_prognoza** matrica, int red, int kol)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			cin.ignore();
			cout << "Padavine: ", cin.getline((*(matrica + i) + j)->padavine, 10);
			*(*(matrica + i) + j)->temperatura = float(rand()) / (float)(rand());
			*(*(matrica + i) + j)->vlaznost_vazduha = float(rand()) / (float)(rand());

		}
	}
}

void ispis(vremenska_prognoza** matrica, int red, int kol)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			
			cout << "Padavine: " << (*(matrica + i) + j)->padavine << "--> ";
			cout << "Temperatura: " << *(*(matrica + i) + j)->temperatura << "--> ";
			cout << "Vlaznost: " << *(*(matrica + i) + j)->vlaznost_vazduha << endl;
		}
		cout << endl;
	}
}

void unosStvarnih(vremenska_prognoza* niz, int kol)
{
	for (int i = 0; i < kol; i++)
	{
			cin.ignore();
			cout << "Padavine: ", cin.getline((niz+ i)->padavine, 10);
			*(niz+ i)->temperatura = float(rand()) / (float)(rand());
			*(niz+ i) ->vlaznost_vazduha = float(rand()) / (float)(rand());
	}
}

int meteorologTacan(vremenska_prognoza** matrica, int red, int kol, vremenska_prognoza* niz)
{
	int* razlike = new int[red];
	for (int i = 0; i < red; i++)
	{
		int sum = 0;
		for (int j = 0; j < kol; j++)
		{
			sum += abs(*(*(matrica + i) + j)->temperatura - *(niz + i)->temperatura); // pretpostavka - stvarna
		}
		*(razlike + i) = sum;
	}
	int indeks = 0;
	for (int i = 0; i < red; i++)
		if (*(razlike + i) < *(razlike + indeks))
			indeks = i;
	delete[] razlike;
	razlike = nullptr;

	return indeks;
}
