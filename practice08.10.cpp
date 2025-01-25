#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int mass[5]{ 0 };
	int vvod;
	cout << "способ формирования массива" << endl;
	cout << "ручной ввод" << endl;
	cout << "ввод случайных чисел (случайная клавиша)" << endl;
	cout << "выберите способ ввода" << endl;
	cin >> vvod;

	cout << "ввод массива" << endl;
	if (vvod = 1) {
		for (int i = 0; i < 5; i++) {
			cout << "mass[ " << i << " ]=";
			cin >> mass[i];

		}
	}
	else {
		cout << "вывод массива" << endl;
		cout << "исходный массив" << endl;
		for (int i = 0; i < 5; i++) {
			cout << mass[i]; // needs <iomanip>
		}
	}

	// ввод случайных чисел в массив 
	//int randDigits[3] = {};
	//srand(time(NULL));

	//for (int i = 0; i < 5; i++) {
	//	randDigits[i] = rand();
	//	cout << randDigits[i] << endl;
	//}
	//srand (time(null))
	// сдвиг вправо ------------ но щас влево
	int massx[5] = { 0 };
	//massx[0] = mass[4];
	for (int i = 1; i < 5; i++) {
		massx[i-1] = mass[i];

	}
	cout << "массив со сдвигом" << endl;
	for (int i = 0; i < 5; i++) {
		cout << massx[i] << " ";

	}
	//сортировка пузырьком
	int dop;
	for (int i = 0; i < 5; i++) { // цикл переходов
		for (int j = 0; j < 5-1; j++) {//цикл перестановок
			if (mass[j] > mass[j + 1]) {
				dop = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = dop;
			}
		}
	}





}
