#include <iostream>
using namespace std;
int PostCharge(int num, int base)
{
	if (num == 0)
		return 0;
	return num % base + 10 * PostCharge(num / base, base);
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