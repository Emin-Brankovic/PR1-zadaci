/*Napisati program koji omogućava korisniku unos integer vrijednosti veće od 100.
Napisati funckiju koja će provjeriti da li je uneseni broj u isto vrijeme i prost i "palindrom", odnosno da li je isti broj i kada se obrnnu sve cifre. 
Po potrebi koristiti dodatne funkcije. Npr. brojevi 383, 727, 757, 787, 797, 919, 929 su u isto vrijeme i prosti brojevi i "palindromi".*/

#include <iostream>

using namespace std;
bool isProst(int broj);
bool isPalindromic(int broj);

void main()
{
	int x;
	do
	{
		cout << "Unijeti broj x: ", cin >> x;
	} while (x<=100);
	if (isProst(x) && isPalindromic(x))
		cout << "Broj je prost i palindromican" << endl;
	else
		cout << "Broj nije u isto vrijeme prost i palindromican" << endl;
}

bool isProst(int broj)
{
	if (broj < 2) return false;
	for (int i = 2; i < broj/2; i++)
	{
		if (broj % i == 0) return false;
	}
	return true;
}



bool isPalindromic(int broj)
{
	int obrnuti=0,cifra,stari=broj;
	while (stari>0)
	{
		cifra = stari % 10;
		obrnuti = obrnuti * 10 + cifra;
		stari /= 10;
	}
	if (obrnuti == broj) return true;
	else return false;
}
