#include <iostream>
using namespace std;
int PostCharge(int num, int base, int k = 0)
{
	if (num == 0)
		return k;
	k += num % base + 10 * PostCharge(num / base, base, k);
	return k;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int a, b;
	cout << "Введите десятичное число: " << endl;
	cin >> a;
	cout << "Введите систему счисления вывода: " << endl;
	cin >> b;
	cout << "ВЫВОД:" << PostCharge(a, b);
}