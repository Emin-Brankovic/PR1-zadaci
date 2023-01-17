/*Napisati program koji će generisati Fibonacci niz i smjestiti ga u jednodimenzionalni niz od 20 elemenata.
(Fibonaccijev niz je niz brojeva koji počinje brojevima 0 i 1, a svaki sljedeći broj u nizu dobije se zbrajanjem prethodna dva:
F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)). Zatim napraviti funkciju koja će sortirati niz uzlazno po srednjoj cifri. 
(Za brojeve sa parnim brojem koristiti aritmeticku sredinu srednje dvije cifre).
(Voditi računa o tipu podatka prilikom računanja srednje cifre.)*/

#include <iostream>

using namespace std;
void unos(int niz[], int size, int i);
void ispis(int* niz, int size, int i);
int getCifre(int broj, int brojac);
int getSrednja(int broj);
void sort(int niz[]);

void main()
{
	int niz[20];
	unos(niz, 20, 0);
	ispis(niz, 20, 0);
	sort(niz);
	cout << endl;
	ispis(niz, 20, 0);

}

int fib(int broj)
{
	if (broj == 0) return 0;
	if (broj == 1) return 1;

	return fib(broj - 1) + fib(broj - 2);
}

void unos(int niz[], int size, int i)
{
	if (i > size - 1) return;
	*(niz + i) = fib(i);
	unos(niz, size, i + 1);
}

void ispis(int* niz, int size, int i)
{
	if (i > size - 1) return;

	cout << *(niz + i) << " ";
	ispis(niz, size, i + 1);
}

int getCifre(int broj,int brojac)
{
	if (broj == 0) return brojac;
	
	return getCifre(broj /= 10, brojac + 1);
}

int getSrednja(int broj)
{
	int brojCifar = getCifre(broj, 0);
	if (brojCifar % 2 != 0)
	{
		brojCifar /= 2;
		broj /= pow(10, brojCifar);

		return broj%10;
	}
	else
	{
		broj = broj / pow(10.0, ((brojCifar / 2) - 1)); // 1234=1234/pow(10,((4/2)-1)=1234=1234/pow(10,1)
		int temp = broj % 10; // uzima zadnju cifru
		broj /= 10; // sklanja zadnju cifru
		temp += broj % 10; // sabira zadnju novu cifru sa prethodnom
		return temp / 2; // vraca srednju vrijednost
	}
}

void sort(int niz[])
{
	int temp = 0, prolazi = 20 - 1;
	bool nijeSortiran;
	do
	{
		nijeSortiran = false;
		for (int i = 0; i < prolazi; i++)
		{
			
			if (getSrednja(niz[i]) > getSrednja(niz[i + 1]))
			{
				temp = niz[i];
				niz[i] = niz[i + 1];
				niz[i+1] = temp;

				nijeSortiran = true;
			}
		}
		prolazi--;
	} while (nijeSortiran);
}
