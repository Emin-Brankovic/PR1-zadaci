#include <iostream>

using namespace std;
struct vozilo
{
    char* markaVozila;
    char* brojSasije;
    char* tipVozila; //dozvoliti unos samo vrijednosti "A", "B", ili "C"
    int* kubnihCM;

    vozilo()
    {
        this->markaVozila = new char[15];
        this->brojSasije = new char[10];
        this->tipVozila = new char;
        this->kubnihCM = new int;
    }
    ~vozilo()
    {
        delete[] markaVozila;
        markaVozila = nullptr;
        delete[]brojSasije;
        brojSasije = nullptr;
        delete tipVozila;
        tipVozila = nullptr;
        delete kubnihCM;
        kubnihCM = nullptr;
    }


};
void unos(vozilo** matrica, int red, int kol);
void ispis(vozilo** matrica, int red, int kol);
void firmaMaxCM(vozilo** matrica, int red, int kol);
void prosjekCMtipova(vozilo** matrica, int red, int kol);

void main()
{
    int red, kol;
    cout << "Unijeti broj redova: ", cin >> red;
    cout << "Unijeti broj kolona: ", cin >> kol;
    vozilo** matrica = new vozilo * [red];
    for (int i = 0; i < red; i++)
        matrica[i] = new vozilo[kol];
    unos(matrica, red, kol);
    ispis(matrica, red, kol);
    firmaMaxCM(matrica, red, kol);
    cout << endl;
    prosjekCMtipova(matrica, red, kol);

    //DEALOKACIJA MATRICE
    for (int i = 0; i < red; i++)
        delete[] matrica[i];
    delete[] matrica;
    matrica = nullptr;
}

void unos(vozilo** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cin.ignore();
            cout << "Unijeti marku vozila: ", cin.getline((*(matrica + i) + j)->markaVozila, 15);
            cout << "Unijeti broj sasije: ", cin.getline((*(matrica + i) + j)->brojSasije, 10);
            cout << "Unijeti tip vozila: ";
            do
            {
                cin >> *(*(matrica + i) + j)->tipVozila;
            } while (*(*(matrica + i) + j)->tipVozila != 'A' && *(*(matrica + i) + j)->tipVozila != 'B' && *(*(matrica + i) + j)->tipVozila != 'C');
            cout << "Unijeti kubne CM : ", cin >> *(*(matrica + i) + j)->kubnihCM;
        }
        cout << endl;
    }
}

void ispis(vozilo** matrica, int red, int kol) 
{

    cout << "Unijeli ste " << red * kol << " elemenata, a oni su: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cout << "Marka vozila je: " << (*(matrica + i) + j)->markaVozila << "\t";
            cout << "Broj sasije vozila je: " << (*(matrica + i) + j)->brojSasije << "\t";
            cout << "Tip vozila je: " << *(*(matrica + i) + j)->tipVozila << "\t";;
            cout << "Kubna potrosnja vozila je: " << *(*(matrica + i) + j)->kubnihCM << endl;
        }
        cout << endl;
    }
}
void firmaMaxCM(vozilo** matrica, int red, int kol)
{
    int indeks = 0;
    float* maxCM = new float[red];
    float temp = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            temp += *(*(matrica + i) + j)->kubnihCM;
        }
        *(maxCM + i) = float(temp / kol);
    }

    for (int i = 0; i < red; i++)
    {
        if (*(maxCM + i) > (*(maxCM + indeks)))
            indeks = i;
    }
    cout << "Firma sa najvecom kubikazom je: " << endl;
    for (int j = 0; j < kol; j++)
    {
        cout << "Marka auta je: " << (*(matrica + indeks) + j)->markaVozila << "\t";
        cout << "Broj sasije je: " << (*(matrica + indeks) + j)->brojSasije << "\t ";
        cout << "Tip vozila: " << *(*(matrica + indeks) + j)->tipVozila << "\t ";
        cout << "Broj kubnim CM: " << *(*(matrica + indeks) + j)->kubnihCM << endl;
    }
    delete[]maxCM;
    maxCM = nullptr;
}

void prosjekCMtipova(vozilo** matrica, int red, int kol)
{
    float prosjekA = 0.0f;
    float prosjekB = 0.0f;
    float brojacA = 0.0f;
    float brojacB = 0.0f;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            if (*(*(matrica + i) + j)->tipVozila == 'A') {
                prosjekA += *(*(matrica + i) + j)->kubnihCM;
                brojacA++;
            }
            else if (*(*(matrica + i) + j)->tipVozila == 'B') {
                prosjekB += *(*(matrica + i) + j)->kubnihCM;
                brojacB++;
            }
        }
    }
    cout << "Projsek kubikaze svih vozila tip A je: " << float(prosjekA / brojacA) << endl;
    cout << "Projsek kubikaze svih vozila tip B je: " << float(prosjekB / brojacB) << endl;
}
