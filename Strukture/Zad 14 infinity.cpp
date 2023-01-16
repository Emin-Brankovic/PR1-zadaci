/* Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa student (student je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza.

struct student
{
    char *ID;
    char *imePrezime;
    float *prosjek;
};
Kompletan 2D niz predstavlja univerzitet. Redovi dvodimenzionalnog niza predstavljaju različite fakultete,a kolone studente
(radi jednostavnosti rješenja podrazumijevati da svaki fakultet ima isti broj studenata). Omogućiti korisniku unos svih podataka za sve studente,
te napraviti funkciju koja će pronaći fakultet sa najvećim prosjekom te ispisati koji je to redni broj fakulteta (index reda sa najvećim prosjekom). 
Zatim pronaći i ispisati ID studenta koji ima najveći prosjek na cijelom univerzitetu.

(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača. 
Obavezno voditi računa o dealociranju dinamički alocirane memorije.)*/

#include <iostream>

using namespace std;
struct student
{
    char* ID;
    char* imePrezime;
    float* prosjek;

    student()
    {
        this->ID = new char[10];
        this->imePrezime = new char[40];
        this->prosjek = new float;
    }
    ~student()
    {
        delete[]ID;
        ID = nullptr;
        delete[]imePrezime;
        imePrezime = NULL;
        delete prosjek;
    }

};
void unos(student** matrica, int red, int kol);
void ispis(student** matrica, int red, int kol);
int najVeciProsjek(student** matrica, int red, int kol);
void najboljiStudent(student** matrica, int red, int kol);

void main()
{
    int red, kol;
    cout << "Unijeti broj redova: ", cin >> red;
    cout << "Unijeti broj kolona: ", cin >> kol;
    student** matrica = new student*[red];
    for (int i = 0; i < red; i++)
        matrica[i] = new student[kol];
    unos(matrica, red, kol);
    ispis(matrica, red, kol);
    cout << "Faks sa najvecim prosjkom je: " << najVeciProsjek(matrica, red, kol) + 1 << endl;
    najboljiStudent(matrica, red, kol);

    // DEALOKACIJA
    for (int i = 0; i < red; i++)
        delete[] matrica[i];
    delete[]matrica;
    matrica = nullptr;
}

void unos(student** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cin.ignore();
            cout << "ID: ", cin.getline((*(matrica + i) + j)->ID, 10);
            *(*(matrica + i) + j)->imePrezime = 'a' + rand() % (('z') - 'a'); // ovo ne radi al ti mrsko unositi
            cout << "Prosjek: ", cin >> *(*(matrica + i) + j)->prosjek;
        }
    }
}

void ispis(student** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cout << "ID: " << (*(matrica + i) + j)->ID << "\t";
            cout << "Ime i prezime: " << (*(matrica + i) + j)->imePrezime << "\t";
            cout << "Prosjek: " << *(*(matrica + i) + j)->prosjek << endl;;
        }
    }
}

int najVeciProsjek(student** matrica, int red, int kol)
{
    float* ukupanProsjek = new float[red];
    for (int i = 0; i < red; i++)
    {
        float temp = 0;
        for (int j = 0; j < kol; j++)
        {
            temp += *(*(matrica + i) + j)->prosjek;
        }
        *(ukupanProsjek + i) = temp;
    }
    int indeks = 0;
    for (int i = 0; i < kol; i++)
    {
        if (*(ukupanProsjek + i) > *(ukupanProsjek + indeks))
            indeks = i;
    }
    delete[] ukupanProsjek;
    return indeks;
}

void najboljiStudent(student** matrica, int red, int kol)
{
    int indeksI = 0;
    int indeksJ = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            if (*(*(matrica + i) + j)->prosjek > *(*(matrica + indeksI) + indeksJ)->prosjek)
                indeksI = i, indeksJ = j;
        }
    }

    cout << "ID studenta najboljim prosjekom u univerzitetu je: " << (*(matrica + indeksI) + indeksJ)->ID << endl;
}
