#include <iostream>
#include <cmath>

using namespace std;
int main() 
{
	setlocale(LC_ALL, "rus");
	double x;
	do {
		cout << "введите х в диапазоне (0;4]" << endl;
		cin >> x;
		if (x <= 0 || x > 4) {
			cout << "введен х, не входящий в заданный диапазон (0;4]" << endl;
		}

	} while (x <= 0 || x > 4);
	double sum = 0;
	double n = 0;
	double u;
	cout << "введите число первых членов ряда" << endl;
	cin >> n;
	cout.width(3);
	cout << "n";
	cout.width(15);
	cout << "общий член";
	cout.width(16);
	cout << "сумма ряда" << endl;
	for (int i = 1; i <= n; ++i) {
		u = pow(x, i);
		sum = sum + u;
		cout.width(4);
		cout << i;
		cout.width(10);
		cout << u;
		cout.width(12);
		cout << sum << endl;
	}
}