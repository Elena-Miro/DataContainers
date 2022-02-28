#include <iostream>
using namespace std;

long double factorial(int n)
{
	if (n < 0) return 0;
	if (n == 0)return 1;
	else return n * factorial(n - 1);
}
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите число:\t"; cin >> n;
	cout << "Факториал для числа " << n << " = " << factorial(n) << endl;
}