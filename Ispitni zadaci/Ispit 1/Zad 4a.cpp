/*Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa uposlenik (uposlenik je struktura čija su obilježja data).
Omogućiti korisniku da unese dimenzije niza.Redovi dvodimenzionalnog niza predstavljaju različite odjele firme u kojima rade različiti radnici 
(radi jednostavnosti rješenja podrazumijevati da svaki odjel ima isti broj radnika). 
Omogućiti korisniku unos svih podataka za sve radnike, te napraviti funkciju koja će naći najveći prosjek plate po odjelima firme te ispisati
koji je to redni broj odjela (indeks reda sa najvećim prosjekom) i koji je najveći prosjek plate.*/
#include <iostream>

using namespace std;
struct uposlenik
{
    char* ID;
    char* imePrezime;
    float* plata;
    uposlenik()
    {
        this->ID = new char[10];
        this->imePrezime = new char[40];
        this->plata = new float;
    }
    ~uposlenik()
    {
        delete[] ID;
        ID = nullptr;
        delete[] imePrezime;
        imePrezime = nullptr;
        delete plata;
    }
};
void unos(uposlenik** matrica, int red, int kol);
void ispis(uposlenik** matrica, int red, int kol);
void indeksNajboljePlate(uposlenik** matrica, int red, int kol);

void main()
{
    int red, kol;
    cout << "Unijeti redove: ", cin >> red;
    cout << "Unijeti kolone: ", cin >> kol;
    uposlenik** matrica = new uposlenik * [red];
    for (int i = 0; i < red; i++)
        matrica[i] = new uposlenik[kol];

    unos(matrica, red, kol);
    ispis(matrica, red, kol); // nije zadano u zad al imas zbog provjere rada
    indeksNajboljePlate(matrica, red, kol);

    // DEALOKACIJA
    for (int i = 0; i < red; i++)
        delete[] matrica[i];
    delete[] matrica;
    matrica = nullptr;
}

void unos(uposlenik** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cin.ignore();
            cout << "Unijeti ID: ";
            cin.getline(matrica[i][j].ID, 10);
            cout << "Unijeti ime i prezime: ";
            cin.getline(matrica[i][j].imePrezime, 40);
            *matrica[i][j].plata = 1200 + rand() % ((3000 + 1) - 1500);
           // cin >> *matrica[i][j].plata; rucni unos plata u matricu
        }
    }
}

void ispis(uposlenik** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cout << " ID: " << matrica[i][j].ID<<"--> ";
            cout << " Ime i prezime: " << matrica[i][j].imePrezime<<"--> ";
            cout << "Plata uposleniak: " << *matrica[i][j].plata << endl;
        }
        cout << endl;
    }
}

void indeksNajboljePlate(uposlenik** matrica, int red, int kol)
{
    float* niz = new float[red];
    for (int i = 0; i < red; i++)
    {
        float sum = 0.0f;
        for (int j = 0; j < kol; j++)
        {
            sum += *matrica[i][j].plata;
        }
        niz[i] = sum / kol;
    }
    int indeks = 0;
    for (int i = 0; i < red; i++)
    {
        if (niz[i] > niz[indeks])
            indeks = i;
    }
    cout << "Odjel sa najvecim prosjekom plate se nalazi na mjestu: " << indeks + 1 << endl;
    cout << "Cija ima je prosjecna plata: " << niz[indeks] << endl;

    delete[] niz;
    niz = nullptr;
}
