/* Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku). 
Omogućiti korisniku da unese dimenzije niza.

struct vozilo
{
    char *markaVozila;
    char *nazivVozila;
    char *tipVozila; // omogućiti unos samo 'A', 'B','C'
    float *potrosnja_goriva_po_km;
};
Redovi matrice predstavljaju firme, kolone automobile. Izračunati u kojoj je firmi najveća potrošnja goriva po km.

Naći i ispisati prosjek potrošnje goriva po km u vozilima tipa C u cijeloj matrici.

(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)*/

#include <iostream>

using namespace std;
struct vozilo
{
    char* markaVozila;
    char* nazivVozila;
    char* tipVozila; // omogućiti unos samo 'A', 'B','C'
    float* potrosnja_goriva_po_km;
    vozilo()
    {
        this->markaVozila = new char[15];
        this->nazivVozila = new char[15];
        this->tipVozila = new char;
        this->potrosnja_goriva_po_km = new float;
    }
    ~vozilo()
    {
        delete[] markaVozila;
        markaVozila = nullptr;
        delete[]nazivVozila;
        nazivVozila = nullptr;
        delete tipVozila;
        tipVozila = nullptr;
        delete potrosnja_goriva_po_km;
        potrosnja_goriva_po_km = nullptr;
    }
};
void unos(vozilo**,int,int);
void najvecaPotrosnja(vozilo**, int, int);
float potrosnjaC(vozilo** matrica, int red, int kol);

void main()
{
    int red, kol;
    cout << "Unijeti broj redova: ", cin >> red;
    cout << "Unijeti broj kolona: ", cin >> kol;
    vozilo** matrica = new vozilo * [red];
    for (int i = 0; i < red; i++)
        matrica[i] = new vozilo[kol];
    unos(matrica, red, kol);
    najvecaPotrosnja(matrica, red, kol);
    cout << "Prosjecna potrosnja goriva po km u vozilima tipa C je: " << potrosnjaC(matrica, red, kol) << " l/KM " << endl;

    //DEALOKACIJA
    for (int i = 0; i < red; i++)
        delete[] matrica[i];
    
    delete[] matrica;
    matrica = nullptr;
}

void unos(vozilo** matrica,int red,int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cin.ignore();
            cout << "Unijeti marku vozila: ", cin.getline((*(matrica + i) + j)->markaVozila, 15);
            cout << "Unijeti naziv vozila: ", cin.getline((*(matrica + i) + j)->nazivVozila, 15);
            cout << "Unijeti tip vozila: ";
            do
            {
                cin >> *(*(matrica + i) + j)->tipVozila;
            } while (*(*(matrica + i) + j)->tipVozila != 'A' && *(*(matrica + i) + j)->tipVozila != 'B' && *(*(matrica + i) + j)->tipVozila != 'C');
            cout << "Unijeti potrosnja goriva po km  : ", cin >> *(*(matrica + i) + j)->potrosnja_goriva_po_km;
            system("cls");
        }
    }
}

void najvecaPotrosnja(vozilo** matrica, int red, int kol)
{
    float* ukupnaPotrosnja = new float[red];
    float temp = 0;
    int indesk = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            temp += *(*(matrica + i) + j)->potrosnja_goriva_po_km;
        }
        cout << endl;
        *(ukupnaPotrosnja + i) = temp;
    }

    for (int i = 0; i < red; i++)
    {
        if (*(ukupnaPotrosnja + i) > *(ukupnaPotrosnja + indesk))
            indesk = i;
    }

    cout << "Firma sa najvecom potrosnjom: " << endl;
    for (int j = 0; j < kol; j++)
    {
        cout << "Marka vozila je: " << (*(matrica + indesk) + j)->markaVozila << "\t";
        cout << "Naziv vozila je: " << (*(matrica + indesk) + j)->nazivVozila << "\t";
        cout << "Tip vozila je: " << *(*(matrica + indesk) + j)->tipVozila << "\t";
        cout << "Potrosnja goriva po kilometrima vozila je: " << *(*(matrica + indesk) + j)->potrosnja_goriva_po_km << " l/km" << endl;
    }
    delete[] ukupnaPotrosnja;
    ukupnaPotrosnja = nullptr;
}

float potrosnjaC(vozilo** matrica, int red, int kol)
{
    float potrosnja = 0;
    float Cbrojac = 0.0f;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            if (*(*(matrica + i) + j)->tipVozila == 'C')
            {
                potrosnja += *(*(matrica + i) + j)->potrosnja_goriva_po_km;
                Cbrojac++;
            }
        }
    }
    return potrosnja / Cbrojac;
}
