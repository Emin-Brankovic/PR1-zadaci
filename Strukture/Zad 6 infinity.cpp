/*Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa košarkaš (košarkaš je struktura čija su obilježja data u nastavku). 
Omogućiti korisniku da unese dimenzije niza.

struct kosarkas
{
    char *ID;
    char *imePrezime;
    int *postignutiKosevi;
};
Redovi dvodimenzionalnog niza predstavljaju različite košarkaše a kolone različite klubove. 
Omogućiti korisniku unos svih podataka za sve košarkaše, te napraviti funkciju koja će pronaći najuspješniji klub (klub u kojem je postignut najveći broj koševa).
Također je potrebno pronači najuspješnijeg košarkaša u tom timu (ne mora biti najuspješniji u ligi) i najlošijeg košarkaša u kompletnoj ligi 
te izračunati razliku u broju postignutih koševa ta dva košarkaša (OVO NISI URADIO).
(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta razlika.)*/

#include <iostream>
#include <time.h>
using namespace std;

struct kosarkas
{
    char* imePrezime;
    int* postignutiKosevi;

    kosarkas()
    {
        this->imePrezime = new char[40];
        this->postignutiKosevi = new int;
        *postignutiKosevi = rand() % 30 + 1;
    }
};
void unos(kosarkas** matrica, int red, int kol);
void ispis(kosarkas** matrica, int red, int kol);
int* ukupnoKoseva(kosarkas** matrica, int red, int kol);
void najBoljiTim(kosarkas** matrica, int red, int kol);
void najgoriIgrac(kosarkas** matrica, int red, int kol);

void main()
{
    srand(time(0));
    int red, kol;
    cout << "Unijeti red: ", cin >> red;
    cout << "Unijet kolonu: ", cin >> kol;

    kosarkas** matrica = new kosarkas* [red];
    for (int i = 0; i < red; i++)
        *(matrica + i) = new kosarkas[kol];
    unos(matrica, red, kol);
    ispis(matrica, red, kol);
    najBoljiTim(matrica, red, kol);
    najgoriIgrac(matrica, red, kol);

    //DEALOKACIJA
    for (int i = 0; i < red; i++)
        delete[] * (matrica + i);
    delete[] matrica;
    matrica = nullptr;
}

void unos(kosarkas** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cin.ignore();
            cout << "Unijeti ime i prezime kosarkasa: ", cin.getline((*(matrica + i) + j)->imePrezime, 40);
            // broj koseva se sam generise
        }
    }
}

void ispis(kosarkas** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
           
            cout << "Ime i prezime kosarkasa: "<<(*(matrica + i) + j)->imePrezime<<" --- ";
            cout << "Broj postignuti koseva: " << *(*(matrica + i) + j)->postignutiKosevi << endl;;
            // broj koseva se sam generise 
        }
        cout << endl;
    }
    cout << endl;
}

void najBoljiTim(kosarkas** matrica, int red, int kol)
{
    int indeksTim = 0;
    int indeksIgraca = 0;
    int* niz = ukupnoKoseva(matrica, red, kol);

    for (int i = 0; i < red; i++)
    {
        if (*(niz + i) > *(niz + indeksTim))
            indeksTim = i;
    }
    cout << "Ekipa sa najvise koseva je: ";
    for (int j = 0; j < kol; j++)
    {
        cout << "Ime i prezime kosarkasa: " << (*(matrica + indeksTim) + j)->imePrezime << " --- ";
        cout << "Broj postignuti koseva: " << *(*(matrica + indeksTim) + j)->postignutiKosevi << endl;
        if (*(*(matrica + indeksTim) + j)->postignutiKosevi > *(*(matrica + indeksTim) + indeksIgraca)->postignutiKosevi)
            indeksIgraca = j;
    }
    cout << endl;
    cout << "Igrac sa najvise poena u najboljoj ekipi je: " << (*(matrica + indeksTim) + indeksIgraca)->imePrezime << endl;

}

int* ukupnoKoseva(kosarkas** matrica, int red, int kol)
{
    int indeksTim = 0;
    int* nizKoseva = new int[red];
    for (int i = 0; i < red; i++)
    {
        int ukupnoKoseva = 0;
        for (int j = 0; j < kol; j++)
        {
            ukupnoKoseva += *(*(matrica + i) + j)->postignutiKosevi;
        }
        *(nizKoseva + i) = ukupnoKoseva;
    }

    return nizKoseva;
}

void najgoriIgrac(kosarkas** matrica, int red, int kol)
{
    int indeksNajgori = 0;
    int indeks = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            if (*(*(matrica + i) + j)->postignutiKosevi < *(*(matrica + indeks) + indeksNajgori)->postignutiKosevi)
            {
                indeksNajgori = j;
                indeks = i;
            }
        }
    }

    cout << "Najgori igrac u ligi je: " << (*(matrica + indeks) + indeksNajgori)->imePrezime;
    cout << " sa brojem poena: " << *(*(matrica + indeks) + indeksNajgori)->postignutiKosevi << endl;
}
