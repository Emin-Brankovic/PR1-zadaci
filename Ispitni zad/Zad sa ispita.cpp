#include <iostream>

using namespace std;
struct datum
{
	int d, m, g;

};
struct student
{
	int IB;
	char ImeiPrezime[30];
	datum rodjenja;
	float prosjecnaOcjena;

};
void unos(student* student);
void ispis(student* student);
bool validacija(int d, int m, int g);
int gen(student** matrica, int red, int kol);
int predmet(student** matrica, int red, int kol);

void main()
{
	int red, kol;
	cout << "RED: ", cin >> red;
	cout << "KOL; ", cin >> kol;
	student** matrica = new student * [red];
	for (int i = 0; i < red; i++)
		matrica[i] = new student[kol];
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			unos(&matrica[i][j]);
		}
	}

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			ispis(&matrica[i][j]);
		}
		cout << endl;
	}
	cout << "Indeks najbolje gen: " << gen(matrica, red, kol) << endl;
	cout << "Indeks najgoreg predmeta: " << predmet(matrica, red, kol) << endl;
	for (int i = 0; i < red; i++)
		delete[] matrica[i];
	delete[] matrica;
	matrica = nullptr;
	
}

void unos(student* student)
{
	student->IB = rand() % 100 + 1;
	*student->ImeiPrezime= 'emin';
	do
	{
		student->rodjenja.d= rand() % 31 + 1;;
		student->rodjenja.m = rand() % 12 + 1;
		student->rodjenja.g = 1920 + rand() % ((2023 + 1) - 1920);

	} while (validacija(student->rodjenja.d, student->rodjenja.m, student->rodjenja.g) == false);
	student->prosjecnaOcjena = (float(rand()) / float(rand()));
}
void ispis(student* student)
{
	cout << "IB: " << student->IB<<"-> ";
	cout << "Ime i prezime: " << *student->ImeiPrezime<<"-> ";
	cout << "Datum rodjenja: " << student->rodjenja.d << "." << student->rodjenja.m << "." << student->rodjenja.g << "." << "-> ";
	cout << "Prosjek: " << student->prosjecnaOcjena << endl;
}



bool validacija(int d, int m, int g)
{
	if (d < 1 || d>31)
		return false;
	if (m < 1 || m>12)
		return false;
	if (g < 1920 || g>2023)
		return false;
	if (m == 2)
	{
		if (g % 4 == 0 || g % 400 == 0 && g % 100 != 0)
			return d <= 29;
		else
			return d <= 28;
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return d <= 30;
	return true;
}

int gen(student** matrica, int red, int kol)
{
	float* prosjek = new float[red];
	for (int i = 0; i < red; i++)
	{
		float sum = 0;
		for (int j = 0; j < kol; j++)
		{
			sum += matrica[i][j].prosjecnaOcjena;
		}
		prosjek[i] = sum / kol;
	}
	
	int indeks = 0;
	for (int i = 0; i < red; i++)
	{
		if (prosjek[i] > prosjek[indeks])
			indeks = i;
	}
	delete[]prosjek;
	prosjek = nullptr;
	return indeks;
}

int predmet(student** matrica, int red, int kol)
{
	float* prosjek1 = new float [kol];
	for (int j = 0; j < kol; j++)
	{
		float sum = 0;
		for (int i = 0; i < red; i++)
		{
			sum += matrica[i][j].prosjecnaOcjena;
		}
		prosjek1[j] = sum / red;
	}
	int indeks = 0;
	for (int i = 0; i < kol; i++)
	{
		if (prosjek1[i] < prosjek1[indeks])
			indeks = i;
	}
	delete[]prosjek1;
	prosjek1 = nullptr;
	return indeks;
}
