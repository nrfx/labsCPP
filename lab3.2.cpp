#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Для матрицы R(m,n), 1<(m, n)<10, найти количество строк, где имеется хотя бы один нуль.\nПереставить строки по возрастанию значений максимальных элементов строк. " << endl;

	int sw;
	int des;
	int randDig, 
	int max;
	bool run = true;

	while (run) {
		cout << "1. Ввести значения\n2. Вывести значения\n3. Найти количество нулей в новом массиве С\n4. Выполнить сдвиг массива C влево на одну позицию\n5. Выход" << endl;
		cout << " " << endl;
		cout << "Ваш выбор: ";

		cin >> sw;
		switch (sw)
		{
		case 1:
			cout << "Выберите способ заполнения данных (рандом - 1; вручную - любая цифра)" << endl;
			cin >> des;
			if (des == 1) {
				for (int i = 0; i < 10; i++) {
					randDig[i] = rand();
					cout << setw(6) << randDig[i];
					}
				}
			}
			cout << "Введите значения для матрицы R" << endl;

		default:
			cout << "ошибка, выход.";
			run = false;
			break;
		}
	}
}