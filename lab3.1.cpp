#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int sw;
	int massive[9] = {};
	int mass[9] = {};
	int C[9] = {};
	int C_rt[9] = {};
	int C2[9] = {};
	int m = 0;
	int n = 0;
	int zr_cnt = 0;
	int A, B;
	bool valuesEntered = false;
	int dop;

	cout << "Задан вектор М(n), n<=9. Сформировать вектор С из элементовM[i], значения которых не равны A и В." "\n"
		"Найти количество нулей в новом массиве.\nВыполнить сдвиг полученного массива влево на одну позицию\n" << endl;

	bool run = true;
	bool case3 = false;
	while (run) {

		cout << "1. Ввести значения" << endl;
		cout << "2. Вывести значения" << endl;
		cout << "3. Найти количество нулей в новом массиве С" << endl;
		cout << "4. Выполнить сдвиг массива C влево на одну позицию" << endl;
		cout << "5. Выполнить сортировку массива по убыванию" << endl;
		cout << "6. Выход" << endl;
		cout << " " << endl;
		cout << "Ваш выбор: ";

		cin >> sw;
		switch (sw)
		{
		case 1:
			cout << "введите длину массива massive: "; cin >> n;
			cout << "введите значения вектора massive" << endl;
			for (int i = 0; i < n; i++) {
				cout << "massive[" << i << "] = ";
				cin >> massive[i];
				mass[i] = massive[i];
			}
			cout << "введите значения А и B через пробел: ";
			cin >> A >> B;
			valuesEntered = true;
			break;
		case 2:
			if (!valuesEntered) {
				cout << "Сначала введите значение вектора massive в меню" << endl;
			}
			else {
				cout << "Значения вектора massive: ";
				for (int val : massive) {
					cout << val << " ";
				}
				cout << endl;
			}
			break;
		case 3:
			if (!valuesEntered) {
				cout << "Сначала введите значение вектора massive в меню" << endl;
			}
			else {
				fill(begin(C), end(C), 0);
				m = 0;
				zr_cnt = 0;

				for (int i = 0; i < n; i++) {
					if (massive[i] != A && massive[i] != B) {
						C[m] = massive[i];
						m++;
					}
				}

				for (int i = 0; i < n; i++) {
					if (C[i] == 0) {
						zr_cnt++;
					}
				}
				cout << "Кол-во нулей в новом массиве C: " << zr_cnt << endl;
			}
			case3 = true;
			break;

		case 4:
			if (m > 0) {
				for (int i = 0; i < m - 1; i++) {
					C2[i] = C[i + 1];
				}
				C2[m - 1] = 0;

				cout << "Массив C, сдвинутый влево на 1 элемент: ";
				for (int i = 0; i < m; i++) {
					cout << C2[i] << " ";
				}
				cout << endl;
				for (int i = 0; i < m; i++) {
					C_rt[i] = C2[i];
				}
				case3 = true;
			}
			else {
				cout << "Массив C пустой. сделайте третий пункт!" << endl;
			}
			break;

		case 5:
			cout << "сортировка по убыванию" << endl;
			if (!case3) {
				for (int i = 0; i < n; i++) { // цикл переходов
					for (int j = 0; j < n - 1; j++) {//цикл перестановок
						if (mass[j] < mass[j + 1]) {
							dop = mass[j];
							mass[j] = mass[j + 1];
							mass[j + 1] = dop;
						}
					}
				}
				for (int i = 0; i < n; i++) {
					cout << mass[i] << " ";
				}
				cout << endl;
			}
			else {
				for (int i = 0; i < m; i++) { // цикл переходов
					for (int j = 0; j < m - 1; j++) {//цикл перестановок
						if (C_rt[j] < C_rt[j + 1]) {
							dop = C_rt[j];
							C_rt[j] = C_rt[j + 1];
							C_rt[j + 1] = dop;
						}
					}
				}
				for (int i = 0; i < m; i++) {
					cout << C_rt[i] << " ";
				}
				cout << endl;
			}
			break;
		case 6:
			cout << "Выход из программы" << endl;
			run = false;
			break;

		default:
			cout << "Введено неверное значение, выполнен выход из программы" << endl;
			run = false;
			break;
		}
	}
	return 0;
}