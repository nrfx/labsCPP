#include <iostream>


using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int sw;
	int des;
	int max;
	bool run = true;
	bool valuesEntered = false;
	int mass[10][10] = {};
	int m, n;
	int zrCount = 0;

	while (run) {
		cout << "Для матрицы R(m,n), 1<(m, n)<10, найти количество строк, где имеется хотя бы один нуль.\nПереставить строки по возрастанию значений максимальных элементов строк. " << endl;
		cout << "1. Ввести значения\n2. Вывести значения\n3. Найти количество строк, где имеется хотя бы один нуль\n4. Переставить строки по возрастанию значений максимальных элементов строк\n5. Выход" << endl;
		cout << " " << endl;
		cout << "Ваш выбор: ";

		cin >> sw;
		switch (sw)
		{
		case 1:
			cout << "Введите количество строк m (1 < m < 10): " << endl;
			cin >> m;
			cout << "Введите количество столбцов n (1 < n < 10): " << endl;
			cin >> n;
			cout << "Выберите способ заполнения данных (рандом - 1; вручную - любая цифра)" << endl;
			cin >> des;
			if (des == 1) {
				srand(time(NULL));
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						mass[i][j] = rand() % 10;
					}
				}
				valuesEntered = true;
			}
			else {
				cout << "ручное заполнение массива" << endl;
				cout << "Введите элементы матрицы:" << endl;
				for (int i = 0; i < m; ++i) {
					for (int j = 0; j < n; ++j) {
						cout << "mass[" << i << "][" << j << "] = ";
						cin >> mass[i][j];
					}
				}
				valuesEntered = true;
			}
			break;
		case 2:
			if (!valuesEntered) {
				cout << "Сначала введите значение вектора M в меню" << endl;
			}
			else {
				cout << "Значения вектора M: " << endl;
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						cout << mass[i][j] << " ";
					}
				cout << endl;
				}
			cout << endl;
			}
			break;

		case 3:
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (mass[i][j] == 0) {
						zrCount++;
						break;
					}
				}
			}
			cout << "Количество строк, имеющих хотя бы один ноль: " << zrCount << endl;
			break;

		case 4:
			for (int i = 0; i < m - 1; i++) {
				for (int j = i + 1; j < m; j++) {
					int max_i = mass[i][0];
					int max_j = mass[j][0];
					// макс в i
					for (int k = 1; k < n; k++) {
						if (mass[i][k] > max_i) {
							max_i = mass[i][k];
						}
					}
					// макс в j
					for (int k = 1; k < n; k++) {
						if (mass[j][k] > max_j) {
							max_j = mass[j][k];
						}
					}
					if (max_i > max_j) {
						for (int k = 0; k < n; k++) {
							swap(mass[i][k], mass[j][k]);
						}
					}
				}
			}
			cout << "Строки переставлены по возрастанию значений максимальных элементов строк." << endl;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cout << mass[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			break;

		case 5:
			cout << "Выход из программы" << endl;
			run = false;
			break;

		default:
			cout << "ошибка, выход.";
			run = false;
			break;
		}
	}
}