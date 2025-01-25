#include <iostream>
#include <string.h> // Для isalpha и isalnum
#pragma warning(disable : 4996)

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    char in_text[200];
    char *temp_text[200]; // переменная для текста
    //temp_text[0] = '\0'; // инициализация пустой строки
    int choice;
    bool isIdentifier1 = true;
    int word_count = 0, sum_n = 0, count_p = 0;

    do {
        // Меню
        cout << "Составить новую строку из слов в строке, состоящих только из цифр. Перед цифрами слова может стоять знак + или - . Найти сумму чисел (цифровых слов), имеющих знак '-' и количество положительных чисел" << endl;
        cout << "Меню:\n";
        cout << "1. Ввод данных\n";
        cout << "2. Вывод данных\n";
        cout << "3. Найти сумму чисел (цифровых слов), имеющих знак '-'\n";
        cout << "4. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Введите текст (не более 200 символов): ";
            cin.ignore();
            cin.getline(in_text, 200); // читаем строку
            /*cin >> text;*/ // либо так, но без пробелов
            break;
        }
        case 2: {
            cout << "Введенный текст: " << in_text << endl;
            break;
        }
        case 3: {
            word_count = 0;
            sum_n = 0;
            count_p = 0;

            char* pch = strtok(in_text, " ");
            while (pch != NULL)// пока есть слова
            {
                temp_text[word_count++] = pch;
                pch = strtok(NULL, " ");
            }

            for (int i = 0; i < word_count; i++) {
                char* text = temp_text[i];
                bool is_number = true;

                // проверка на чиисло
                int j = 0;
                if (text[0] == '+' || text[0] == '-') {
                    j++;
                }
                for (; text[j] != '\0'; j++) {
                    if (text[j] < '0' || text[j] > '9') { // проверка на цифру
                        is_number = false;
                        break;
                    }
                }

                if (is_number) {
                    cout << text << " ";

                    // преобразование слова в число
                    int num = 0;
                    int sign = 1;

                    if (text[0] == '-') {
                        sign = -1;
                        j = 1; // пропуск
                    }
                    else if (text[0] == '+') {
                        j = 1; // пропуск
                    }
                    else {
                        j = 0; // начало
                    }

                    for (; text[j] != '\0'; j++) {
                        num = num * 10 + (text[j] - '0'); // преобразование символа в число
                    }
                    num *= sign; // применяем знак

                    if (num < 0) {
                        sum_n += num;
                    }
                    else if (num > 0) {
                        count_p++;
                    }
                }
            }
            cout << endl;

            cout << "Сумма чисел со знаком '-': " << sum_n << endl;
            cout << "Количество положительных чисел: " << count_p << endl;
            break;
        }
        case 4: {
            cout << "Выход из программы.\n";
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
        }
    } while (choice != 4);

    return 0;
}




/*int main() {
    char input[MAX_LENGTH];
    char *words[100]; // Массив указателей на слова
    int word_count = 0;

    cout << "Введите строку (до 200 символов):" << endl;
    cin.getline(input, MAX_LENGTH);

    // Разделение строки на слова
    char *token = strtok(input, " ");
    while (token != nullptr) {
        words[word_count++] = token;
        token = strtok(nullptr, " ");
    }

    int sum_negative = 0;
    int count_positive = 0;

    cout << "Цифровые слова:" << endl;

    for (int i = 0; i < word_count; i++) {
        char *word = words[i];
        bool is_number = true;

        // Проверка, является ли слово числом
        int j = 0;
        if (word[0] == '+' || word[0] == '-') {
            j++;
        }
        for (; word[j] != '\0'; j++) {
            if (word[j] < '0' || word[j] > '9') { // Проверка, является ли символ цифрой
                is_number = false;
                break;
            }
        }

        if (is_number) {
            cout << word << " ";

            // Преобразование слова в число вручную
            int num = 0;
            int sign = 1;

            if (word[0] == '-') {
                sign = -1;
                j = 1; // Пропустить знак
            } else if (word[0] == '+') {
                j = 1; // Пропустить знак
            } else {
                j = 0; // Начало числа
            }

            for (; word[j] != '\0'; j++) {
                num = num * 10 + (word[j] - '0'); // Преобразование символа в число
            }
            num *= sign; // Применить знак

            if (num < 0) {
                sum_negative += num;
            } else if (num > 0) {
                count_positive++;
            }
        }
    }
    cout << endl;

    cout << "Сумма чисел со знаком '-': " << sum_negative << endl;
    cout << "Количество положительных чисел: " << count_positive << endl;

    return 0;
}*/