#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	float x;
	const float pi = 3.1415926535;
	do
	{
		cout << "Введите x в диапазоне от pi/4 до 3*pi/4" << endl;
		cin >> x;
	} while (x <= pi / 4 || x >= 3 * pi / 4);
	float sum = 0;
	float k = 0;
	float u;
	cout << "Введите число первых членов ряда" << endl;
	cin >> k;
	cout.width(4);
	cout << "k";
	cout.width(10);
	cout << "Общ. член";
	cout.width(12);
	cout << "Сумма ряда" << endl;
	for (int i = 1; i <= k; ++i)
	{
		u = sin(i * x) / i;
		sum = sum + u;
		cout.width(4);
		cout << i;
		cout.width(10);
		cout << u;
		cout.width(12);
		cout << sum << endl;
	}
	float eps;
	cout << "Введите погрешность" << endl;
	cin >> eps;
	sum = 0;
	int i = 1; // кол-во членов ряда
	u = sin(i * x) / i;
	while (fabs(u) > eps)
	{
		sum = sum + u;
		i = i + 1;
	}

}