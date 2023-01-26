/*Napisati program koji omogućava korisniku unos integer vrijednosti veće od 100. 
Napisati funckiju koja će provjeriti da li je uneseni broj u isto vrijeme i prost i "palindrom", odnosno da li je isti broj i kada se obrnnu sve cifre. 
Po potrebi koristiti dodatne funkcije. Npr. brojevi 383, 727, 757, 787, 797, 919, 929 su u isto vrijeme i prosti brojevi i "palindromi".*/
#include <iostream>

using namespace std;
bool isPalindrom(int broj);
bool isProst(int broj);

void main()
{
	int n;
	do
	{
		cout << "N: ", cin >> n;
	} while (n<100);
	if (isPalindrom(n) && isProst(n))
		cout << n;

}

bool isPalindrom(int broj)
{
	int temp = broj,novi=0;
	while (temp>0)
	{
		int cifra = temp % 10;
		novi = novi * 10 + cifra;
		temp /= 10;
	}
	if (novi == broj) return true;
	return false;
}

bool isProst(int broj)
{
	if (broj < 2)return false;
	for (int i = 2; i < broj / 2; i++)
		if (broj % i == 0) return false;
	return true;
}
