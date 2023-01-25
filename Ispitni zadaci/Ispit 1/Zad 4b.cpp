/*Kreirati dvodimenzionalni dinamički niz čiji su elementi objekti tipa figura (figura je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza, te omogućiti unos elemenata. 
Potrebno je napisati funkciju koja će računati prosječnu visinu svih figura koje se nalaze na crnim poljima ispod sporedne dijagonale. 
Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta vrijednost.*/

#include <iostream>
#include<time.h>
using namespace std;
struct figura
{
    //int ID; bilo ti mrsko ID unositi pa je zato zakomentiran
    char* nazivFigure;
    float* visinaFigure;
    figura()
    {
        this->nazivFigure = new char[10];
        this->visinaFigure = new float;
    }
    ~figura()
    {
        delete[] nazivFigure;
        nazivFigure = nullptr;
        delete visinaFigure;
    }
};
void unos(figura** matrica, int red, int kol);
void ispis(figura** matrica, int red, int kol);
float* prosjekVisine(figura** matrica, int red, int kol);

void main()
{
    srand(time(0));
    int red, kol;
    cout << "Unijeti broj redova: ", cin >> red;
    do
    {
        cout << "Unijeti broj kolona iste kao redova: ", cin >> kol;
    } while (kol!=red);
    figura** matrica = new figura* [red];
    for (int i = 0; i < red; i++)
        matrica[i] = new figura[kol];
    unos(matrica, red, kol);
    ispis(matrica, red, kol);
    cout<<"Adresa prosjecne visine figura je: "<<*prosjekVisine(matrica, red, kol);

    //DEALOKACIJA
    for (int i = 0; i < red; i++)
        delete[] matrica[i];
    delete[] matrica;
    matrica = nullptr;
}

void unos(figura** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cin.ignore();
            cout << "Unijeti naziv figure: ";
            cin.getline(matrica[i][j].nazivFigure, 10);
            *matrica[i][j].visinaFigure = rand() % 70 + 1;
            //Rucni unos visine figure
            //cout << "Unijeti visinu figure: ", cin >> *matrica[i][j].visinaFigure;
        }
    }
}

void ispis(figura** matrica, int red, int kol)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cout << "Naziv figure: " << matrica[i][j].nazivFigure << " ---> ";
            cout << "Visina figure: " << *matrica[i][j].visinaFigure << endl;
        }
    }
}

float* prosjekVisine(figura** matrica, int red, int kol)
{
  float sum = 0,brojac=0;

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            if ((i + j) % 2 == 0 && (i+j)>=red)
            {
                sum += *matrica[i][j].visinaFigure;
                brojac++;
            }
        }
    }
    float prosjek = sum / brojac; // bila greska ovdje, djelio sa brojem kolona umjesto brojac da napravim koji broji crna polja ispod sporedne dijagonale
    return &prosjek;
}
