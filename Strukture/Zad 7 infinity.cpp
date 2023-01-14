/*Kreirati dvodimenzionalni dinamički niz čiji su elementi objekti tipa figura (figura je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza, te omogućiti unos elemenata.

struct figura
{
    int ID
    char *nazivFigure;
    float *visinaFigure;
}
Potrebno je napisati funkciju koja će računati prosječnu visinu svih figura koje se nalaze na crnim poljima ispod sporedne dijagonale.

(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta vrijednost.)*/

#include <iostream>
#include <time.h>
using namespace std;

struct figura
{
    int ID;
    char* nazivFigure;
    float* visinaFigure;
	figura()
	{
		this->ID = rand() % 100 + 1;;
		this->nazivFigure = new char[10];
		this->visinaFigure = new float;
		*visinaFigure= 5 + rand() % ((15 + 1) - 5);
	}
	~figura()
	{
		delete[] nazivFigure;
		nazivFigure = nullptr;
		delete visinaFigure;
	}
};
void unos(figura** matrica, int red, int kol);
void ispis(figura** matrica, int red, int kol);
float prosjekVisina(figura** matrica, int red, int kol);
//void ispisVisina(figura** matrica, int red, int kol);
void main()
{
	srand(time(0));
	int red, kol;
	cout << "Unijeti broj redova: ", cin >> red;
	do
	{
		cout << "Unijeti broj kolona: ", cin >> kol;
	} while (kol != red);

	figura** matrica = new figura* [red];
	for (int i = 0; i < red; i++)
		*(matrica + i) = new figura[kol];

	unos(matrica, red, kol);
	ispis(matrica, red, kol);
	//ispisVisina(matrica, red, kol);
	cout << endl;
	cout << "Prosjecna visina crnih figura ispod sporedne dijagonale je: " << prosjekVisina(matrica, red, kol);

	//DEALOKACIJA
	for (int i = 0; i < red; i++)
		delete[] * (matrica + i);
	delete[] matrica;
}

void unos(figura** matrica, int red, int kol)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			/*(*(matrica + i) + j)->ID = rand() % 100 + 1;*/
			cin.ignore();
			cout << "Unijeti naziv figure: ", cin.getline((*(matrica + i) + j)->nazivFigure, 10);
			/**(*(matrica + i) + j)->visinaFigure = 5 + rand() % ((15 + 1) - 5);*/
		}
	}
}

void ispis(figura** matrica, int red, int kol)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			cout << "ID figure je: " << (*(matrica + i) + j)->ID<<"\t";
			cout << "Naziv figure je: " << (*(matrica + i) + j)->nazivFigure << "\t";
			cout << "Visina figure je: " << *(*(matrica + i) + j)->visinaFigure << endl;
		}
		cout << endl;
	}
}

float prosjekVisina(figura** matrica, int red, int kol)
{
	int brojac = 0;
	float prosjek = 0.0f;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			if((i+j>red-1) && (i+j)%2==0)
			{
				prosjek += *(*(matrica + i) + j)->visinaFigure;
				brojac++;
			}
		}
		cout << endl;
	}
	return float(prosjek / brojac);
}

//SLUZI DA VIDIS KAKAV JE ISPIS VISINA I KOJE SU ISPOD NA CRNIM MJESTIMA
//void ispisVisina(figura** matrica, int red, int kol)
//{
//	for (int i = 0; i < red; i++)
//	{
//		for (int j = 0; j < kol; j++)
//		{
//			if ((i + j > red - 1) && (i + j) % 2 == 0)
//				cout << *(*(matrica + i) + j)->visinaFigure << "\t ";
//			else
//			{
//				cout << "*" << "\t";
//			}
//		}
//		cout << endl;
//	}
//}
