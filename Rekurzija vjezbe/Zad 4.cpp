#include <iostream>

using namespace std;
float suma1(int n, int i, int sum);
float suma2(int sum, int n);

void main()
{
	float rez = (suma1(10, -10, 0) - suma2(0, 5) )*1/sqrt(5);
	cout << rez;
}
float suma1(int n,int i, int sum)
{
	if (i > n) return sum;

	return suma1(n, i + 1, float(sum += pow(i, 2)));
}

float suma2(int sum, int n)
{
	if (n < -5) return sum;

	return suma2(float(sum += n),n-1);
}

// ILI OVAKO (URADIO CHATGPT)


float recursiveSum(float S, int start, int end, int power);

void main() {
    float S = 0.0f;
    S = recursiveSum(S, -10, 10, 2);
    S = recursiveSum(S, -5, 5, 1);
    S *= 1 / sqrt(5);
    cout << "Suma (S) je: " << S << endl;
}

float recursiveSum(float S, int start, int end, int power) {
    if (start > end) {
        return S;
    }
    S += pow(start, power);
    return recursiveSum(S, start + 1, end, power);
}
