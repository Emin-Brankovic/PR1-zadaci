#include <iostream>

using namespace std;

struct Datum
{
	int dan, mjesec, godina;

	Datum()
	{
		this->dan = 0;
		this->mjesec = 0;
		this->godina= 0;
	}
	void unosDatum()
	{
		cin >> dan >> mjesec >> godina;
	}
	void ispiDatum()
	{
		cout << dan << "." << mjesec << "." << godina << "." << endl;
	}
	bool validacijaDatuma()
	{
		int min = 1, max = 31;
		if (godina < 1 || godina>2023)
			return false;
		if (mjesec < 1 || mjesec>12)
			return false;
		if ((mjesec == 2) && (godina % 4 == 0 || godina % 400 == 0 && godina % 100 != 0))
			max = 29;
		else
			max = 28;
		if (dan < min && dan > max)
			return false;
		return true;
	}
};

struct Student
{
	int IB;
	char Ime[30];
	char Prezime[30];
	Datum rodjenja;
	

	void unosStudent()
	{
		cout << "Unijeti broj indeksa ", cin >> IB;
		cin.ignore();
		cout << "Unijeti ime: ";
		cin.getline(Ime, 30);
		cout << "Unijeti prezime: ";
		cin.getline(Prezime, 30);
		cout << "Unijeti datum rodjenja: ";
		rodjenja.unosDatum();
		cin.ignore();
		cout << endl;
	}
	void ispisStudent()
	{
		cout << "Broj indeksa IB" << IB << endl;
		cout << "Ime i prezime: " << Ime << " " << Prezime << endl;
		cout << "Datum rodenja: ";
		rodjenja.ispiDatum();
		cout << endl;
	}
	int brojPogresnihDatuma(Student* niz)
	{
		int brojac = 0;
		for (int i = 0; i < 2; i++)
		{
			if (niz[i].rodjenja.validacijaDatuma() == false)
				brojac++;
		}
		return brojac;
	}
	 Student* prviNetacan(Student* niz)
	{
		Student* netacan = niz;
		for (int i = 0; i < 2; i++)
		{
			if (rodjenja.validacijaDatuma() == false)
			{
				netacan = niz + i;
			}
			break;
		}
		return netacan;
	}
};
int main()
{
	Student studenti[2];
	for (int i = 0; i < 2; i++)
		studenti[i].unosStudent();
	for (int i = 0; i < 2; i++)
		studenti[i].ispisStudent();
	cout << "Broj studenata sa netacnim datumom: " << studenti->brojPogresnihDatuma(studenti) << endl;
	cout << "Student prvi u nizu sa netacnim datumom ";
	studenti->prviNetacan(studenti)->ispisStudent();
	

	return 0;
}
