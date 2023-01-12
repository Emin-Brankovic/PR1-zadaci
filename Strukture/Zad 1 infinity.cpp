/*Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa fudbaler (fudbaler je struktura čija su obilježja data u nastavku). 
Omogućiti korisniku da unese dimenzije niza.Redovi dvodimenzionalnog niza predstavljaju različite timove, a kolone predstavljaju igrače u tim timovima.

Omogućiti korisniku unos svih podataka za sve igrače, te napraviti (i testirati u main funkciji) funkciju koja će pronaći tim sa najvećim prosjekom. 
Zatim napraviti (i testirati u main funkciji) funkciju koja će pronaći igrača sa najviše golova u timu sa najlošijim prosjekom golova. 
Radi lakšeg testiranja programa obavezno u funkciji unosa podataka omogućiti da se podaci generišu kao sljedeće:

godRodjenja: 1980 + rand() % ((2000 + 1) - 1980) // Generiše brojeve u rangu 1980 - 2000
brojIgraca: rand() % 30 + 1
golovi: rand() % 5


*/




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
        godRodjenja = nullptr;
        delete brojIgraca;
        brojIgraca = nullptr;
        delete golovi;
        golovi = nullptr;
    }

};
void unos(fudbaler** matrica, int red, int kol);
void ispis(fudbaler** matrica, int red, int kol);
void timSaNajvecimProsjekom(fudbaler** matrica, int red, int kol);
void igrac_sa_najvise_Golova(fudbaler** matrica, int red, int kol);

int main()
{
    srand(time(0));
    int red, kol;
    cout << "Unesite broj redova: ", cin >> red;
    cout << "Unesite broj kolona: ", cin >> kol;
    fudbaler** matrica = new fudbaler*[red];
    for (int i = 0; i < red; i++)
        matrica[i] = new fudbaler[kol];

    
    unos(matrica, red, kol);
    ispis(matrica, red, kol);
    timSaNajvecimProsjekom(matrica, red, kol);
    cout << endl;
    igrac_sa_najvise_Golova(matrica, red, kol);

    for (int i = 0; i < red; i++)
    {
        delete[] matrica[i];
    }
    delete[] matrica;
    matrica = nullptr;

    system("pause>null");
    return 0;
}

void unos(fudbaler** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            
            *(*(matrica+i)+j)->godRodjenja= 1980 + rand() % ((2000 + 1) - 1980);
            *(*(matrica + i) + j)->brojIgraca= rand() % 30 + 1;
            *(*(matrica+i)+j)->golovi= rand() % 5;
        }
        cout << endl;
    }
}

void ispis(fudbaler** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cout << "Godina rodjenja igraca " << *(*(matrica + i) + j)->godRodjenja<< "\t";
            cout << "Broj igraca je: " << *(*(matrica + i) + j)->brojIgraca<< "\t";
            cout << "Broj golova je: " << *(*(matrica + i) + j)->golovi << endl;
        }
        cout << endl;
    }
}

void timSaNajvecimProsjekom(fudbaler** matrica, int red, int kol)
{
    int indeks = 0;
    float* prosjekTimova = new float[red];
    for (int i = 0; i < red; i++)
    {
        int temp = 0;
        for (int j = 0; j < kol; j++)
        {
            temp += *(*(matrica + i) + j)->golovi;
        }
      
        *(prosjekTimova + i) = float(temp / kol);
    }

    for (int i = 0; i < red; i++)
    {
        if (*(prosjekTimova + i) > *(prosjekTimova + indeks)) {
            indeks= i;
        }
    }

    cout << "Tim sa najboljim prosjekom je " << endl;
    for (int j = 0; j < kol; j++)
    {
        cout << "Godina rodjenja igraca " << *(*(matrica + indeks) + j)->godRodjenja<< "\t";
        cout << "Broj igraca je: " << *(*(matrica + indeks) + j)->brojIgraca<< "\t";
        cout << "Broj golova je: " << *(*(matrica + indeks) + j)->golovi<<endl;
    }
}

void igrac_sa_najvise_Golova(fudbaler** matrica, int red, int kol)
{
    // u ovom dijelu koda trazimo epiku najlosijim prosjekom

    int indeks = 0;
    float* prosjekTimova = new float[red];
    for (int i = 0; i < red; i++)
    {
        int temp = 0;
        for (int j = 0; j < kol; j++)
        {
            temp += *(*(matrica + i) + j)->golovi;
        }

        *(prosjekTimova + i) = float(temp / kol);
    }

    for (int i = 0; i < red; i++)
    {
        if (*(prosjekTimova + i) < *(prosjekTimova + indeks)) {
            indeks = i;
        }
    }

    // sad trazimo igraca sa najvise golova
    int najviseGolova = 0;
    int indeksKolone = 0;
    for (int j = 0; j < kol; j++)
    {
        if (*(*(matrica + indeks) + j)->golovi > *(*(matrica + indeks) + indeksKolone)->golovi)
          indeksKolone = j;
    }

    cout << "Igrac sa najvise golova u najgorem timu je " << endl;
    cout <<"Igrac sa brojem dresa: " << *(*(matrica + indeks) + indeksKolone)->brojIgraca << " ";
  /*  cout << *(*(matrica + indeks) + indeksKolone)->godRodjenja<<" ";*/
    cout <<" i postignutim brojem golova " << *(*(matrica + indeks) + indeksKolone)->golovi << " ";
}
