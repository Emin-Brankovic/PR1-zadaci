/*Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vremenska_prognoza (prognoza je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.

struct vremenska_prognoza
{
    char *padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
    float *temperatura;
    float *vlaznost_vazduha;
};
Redovi dvodimenzionalnog niza predstavljaju različite meteorologe, a kolone različite dane. Omogućiti korisniku unos svih prognoza za sve meteorologe. Dodatno kreirati jednodimenzionalni dinamički niz čija će veličina biti uneseni broj dana u koji ćete omogućiti unos stvarnih izmjerenih vrijednosti za dane. Zatim napraviti funkciju koja će pronaći i ispisati index meteorologa čija je prognoza dnevnih temperatura bila najtačnija, odnosno koji je imao najmanju grešku u procjeni temperatura. Pomoć: suma svih razlika između prognozirane i stvarne temperature za jednog meteorologa predstavlja njegovu ukupnu grešku.

(U ovom zadatku je zabranjeno indeksirati elemente u niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)*/

#include <iostream>

using namespace std;
struct vremenska_prognoza
{
    char* padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
    float* temperatura;
    float* vlaznost_vazduha;

    vremenska_prognoza()
    {
        this->padavine = new char[15];
        this->temperatura = new float;
        this->vlaznost_vazduha = new float;
    }
    ~vremenska_prognoza()
    {
        delete[] padavine;
        padavine = nullptr;
        delete temperatura;
        delete vlaznost_vazduha;
    }
};
void unosPrognoza(vremenska_prognoza** matrica, int red, int kol);
void ispisPrognoza(vremenska_prognoza** matrica, int red, int kol);
void unosStvarnih(vremenska_prognoza* niz, int red);
void najTacniji(vremenska_prognoza** matrica, vremenska_prognoza* niz, int red, int kol);

void main()
{
    int red, kol;
    cout << "Unijeti broj meteorologa(redova): ", cin >> red;
    cout << "Unijeti broj dana(kolona): ", cin >> kol;

    vremenska_prognoza** matrica = new vremenska_prognoza * [red];
    for (int i = 0; i < red; i++)
        matrica[i] = new vremenska_prognoza[kol];
    vremenska_prognoza* nizStvarnihVel = new vremenska_prognoza[kol];

    unosPrognoza(matrica, red, kol);
    ispisPrognoza(matrica, red, kol);
    unosStvarnih(nizStvarnihVel, kol);
    najTacniji(matrica, nizStvarnihVel, red, kol);

    // DEALOKACIJA
    for (int i = 0; i < red; i++)
        delete[] matrica[i];
    delete[] matrica;
    matrica = nullptr;

    delete[] nizStvarnihVel;
}

void unosPrognoza(vremenska_prognoza** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {

            cin.ignore();
            cout << "Unijeti tip padavine (kisa ili snijeg): ", cin.getline((*(matrica + i) + j)->padavine, 15);
            cout << "Unijeti temperaturu: ", cin >> *(*(matrica + i) + j)->temperatura;
            cout << "Unijeti vlaznost zraka: ", cin >> *(*(matrica + i) + j)->vlaznost_vazduha;
            system("cls");
        }
    }
}

void ispisPrognoza(vremenska_prognoza** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol;j++)
        {
            cout << " Tip padavine je : "<<(*(matrica + i) + j)->padavine<<"\t";
            cout << " Temperaturu je: "<< *(*(matrica + i) + j)->temperatura<<"\t";
            cout << " Vlaznost zraka je: " << *(*(matrica + i) + j)->vlaznost_vazduha << endl;
        }
        cout << endl;
    }
}

void unosStvarnih(vremenska_prognoza* niz, int red)
{
    for (int i = 0; i < red; i++)
    {
        cin.ignore();
        cout << "Unijeti tip padavine (kisa ili snijeg): ", cin.getline((niz+i)->padavine, 15);
        cout << "Unijeti temperaturu: ", cin >>*(niz+i) ->temperatura;
        cout << "Unijeti vlaznost zraka: ", cin >>*(niz+i) ->vlaznost_vazduha;
        system("cls");
    }
}

void najTacniji(vremenska_prognoza** matrica, vremenska_prognoza* niz, int red, int kol)
{
    int indeks = 0;
    float* odstupanja = new float[red];
    for (int i = 0; i < red; i++)
    {
        float temp = 0;
        for (int j = 0; j < kol; j++)
        {
            temp+= abs(*(*(matrica + i) + j)->temperatura - *(niz + j)->temperatura);
        }
        *(odstupanja + i) = temp;
    }
    
    for (int i = 0; i < red; i++)
    {
        if (*(odstupanja + i) < *(odstupanja + indeks))
            indeks = i;
    }

    cout << "Meteorolog sa najmanjom greskom je na indeksu: " << indeks << endl;

    delete[]odstupanja;
    odstupanja = nullptr;
}
