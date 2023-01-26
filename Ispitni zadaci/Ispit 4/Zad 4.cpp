/*Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza.Redovi matrice predstavljaju firme, kolone automobile. Izračunati u kojoj je firmi najveća potrošnja goriva po km. 
Naći i ispisati prosjek potrošnje goriva po km u vozilima tipa C u cijeloj matrici. U zadataku koristiti artimetiku pokazivaca.*/
#include <iostream>

using namespace std;
struct vozilo
{
   /* char* markaVozila;
    char* nazivVozila;*/
    char* tipVozila; // omogućiti unos samo 'A', 'B','C'
    float* potrosnja_goriva_po_km;
    vozilo()
    {
        this->tipVozila = new char;
        this->potrosnja_goriva_po_km = new float;
    }
    ~vozilo()
    {
        delete tipVozila;
        delete potrosnja_goriva_po_km;
    }
};
void unos(vozilo** matrica, int red, int kol);
void ispis(vozilo** matrica, int red, int kol);
int najvecaPotrosnja(vozilo** matrica, int red, int kol);
float potrosnjaPoC(vozilo** matrica, int red, int kol);


void main()
{
    int red, kol;
    cout << "Red: ", cin >> red;
    cout << "Kol: ", cin >> kol;
    vozilo** matrica = new vozilo * [red];
    for (int i = 0; i < red; i++)
        *(matrica + i) = new vozilo[kol];
    unos(matrica, red, kol);
    ispis(matrica, red, kol);
    cout << "Firma sa najvecom potrosnjom se nalazi na indeksu: " << najvecaPotrosnja(matrica, red, kol) << endl;
    cout << "Prosjek potrosnje vozila tipa C je: " << potrosnjaPoC(matrica, red, kol) << endl;
    for (int i = 0; i < red; i++)
        delete[] * (matrica + i);
    delete[] matrica;
    matrica = nullptr;

}

void unos(vozilo** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            do
            {
                cout << "Tip vozila: ", cin >> *(*(matrica + i) + j)->tipVozila;
            } while (*(*(matrica + i) + j)->tipVozila !='A' && *(*(matrica + i) + j)->tipVozila != 'B' && *(*(matrica + i) + j)->tipVozila != 'C');
            *(*(matrica + i) + j)->potrosnja_goriva_po_km = rand() % 10 + 1;
        }

    }
}

void ispis(vozilo** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            
           cout << "Tip vozila: "<<*(*(matrica + i) + j)->tipVozila<<"--> ";
       
           cout << "Potrosnja: " << *(*(matrica + i) + j)->potrosnja_goriva_po_km << endl;
        }
        cout << endl;
    }
}
int najvecaPotrosnja(vozilo** matrica, int red, int kol)
{
    int* ukupnaPotrosnja = new int[red];
    for (int i = 0; i < red; i++)
    {
        int sum = 0;
        for (int j = 0; j < kol; j++)
        {
            sum += *(*(matrica + i) + j)->potrosnja_goriva_po_km;
        }
        *(ukupnaPotrosnja + i) = sum;
    }
    int indeks = 0;
    for (int i = 0; i < red; i++)
        if (*(ukupnaPotrosnja + i) > *(ukupnaPotrosnja + indeks))
            indeks = i;

    delete[]ukupnaPotrosnja;
    ukupnaPotrosnja = nullptr;

    return indeks;
}

float potrosnjaPoC(vozilo** matrica, int red, int kol)
{
    float ukupno = 0,brojac=0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            if (*(*(matrica + i) + j)->tipVozila == 'C')
            {
                ukupno += *(*(matrica + i) + j)->potrosnja_goriva_po_km;
                brojac++;
            }
        }
        cout << endl;
    }
    return ukupno / brojac;
}
