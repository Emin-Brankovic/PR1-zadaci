/*Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa uposlenik (uposlenik je struktura čija su obilježja data). 
Omogućiti korisniku da unese dimenzije niza.

struct uposlenik
{
    char *ID;
    char *imePrezime;
    float *plata;
}
Redovi dvodimenzionalnog niza predstavljaju različite odjele firme u kojima rade različiti radnici (
radi jednostavnosti rješenja podrazumijevati da svaki odjel ima isti broj radnika).
Omogućiti korisniku unos svih podataka za sve radnike, 
te napraviti funkciju koja će naći najveći prosjek plate po odjelima firme te ispisati koji je to redni broj odjela (indeks reda sa najvećim prosjekom) 
i koji je najveći prosjek plate.*/

#include <iostream>
#include<time.h>

using namespace std;

struct uposlenik
{
 /*   char* ID;*/
    char* imePrezime;
    float* plata;
    uposlenik()
    {
        this->imePrezime = new char[40];
        this->plata = new float;
        *plata = 1000 + rand() % ((2500 + 1) - 1000);
    }
    ~uposlenik()
    {
        delete[]imePrezime;
        imePrezime = nullptr;
        delete plata;
    }
};
void unos(uposlenik** matrica, int red, int kol);
void ispis(uposlenik** matrica, int red, int kol);
void najboljaPlata(uposlenik** matrica, int red, int kol);

void main()
{
    srand(time(0));
    int red, kol;
    cout << "Unijeti redove: ", cin >> red;
    cout << "Unijeti kolone: ", cin >> kol;
    uposlenik** matrica = new uposlenik * [red];
    for (int i = 0; i < red; i++)
        matrica[i] = new uposlenik[kol];
    unos(matrica, red, kol);
    ispis(matrica, red, kol);
    najboljaPlata(matrica, red, kol);

    //DEALOKACIJA
    for (int i = 0; i < red; i++)
        delete[] matrica[i];
    delete[] matrica;
    matrica = nullptr;
}

void unos(uposlenik** matrica, int red, int kol)
{
     cin.ignore();
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cout << "Unijeti ime i prezime: ", cin.getline(matrica[i][j].imePrezime, 40);
            /*cout << "Unijeti platu uposlenika: ", cin >> *matrica[i][j].plata;*/
        }
    }
}
void ispis(uposlenik** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cout << "Ime i prezime: " << matrica[i][j].imePrezime<<"  ";
            cout << "Plata uposlenika: " << *matrica[i][j].plata << endl;;
        }
    }
}

void najboljaPlata(uposlenik** matrica, int red, int kol)
{
    float* prosjekPlata = new float[red];
    for (int i = 0; i < red; i++)
    {
        float temp = 0;
        for (int j = 0; j < kol; j++)
        {
            temp+=*matrica[i][j].plata;
        }
        prosjekPlata[i] = float(temp / kol);
    }
    int indeks = 0;
    for (int i = 0; i < red; i++)
    {
        if (prosjekPlata[i] > prosjekPlata[indeks])
            indeks = i;
    }

    cout << "Najveci prosjek plate odjela se nalazi na indeksu: " << indeks << endl;
    cout << "Prosjek iznosi: " << prosjekPlata[indeks] << endl;

    delete[] prosjekPlata;
    prosjekPlata = nullptr;
}
