#include <iostream>

using namespace std;

// Функция, вставляющая элемент в конец динамического массива
void insertInArray(int *&pA, int *size, int element) {  
    (*size)++;
    int *newPA = new int[*size];
    for (int i = 0; i < *size - 1; i++) {
        newPA[i] = pA[i];
    }

    newPA[*size - 1] = element;
    delete[] pA;
    pA = newPA;
}

// Функция для банкомата, которому нужно выдать сумму минимальным количеством купюр
// Банкомат может выдавать только бумажные купюры от 50 до 5000 рублей
// Добавляет выбранные купюры в динамический массив result
// Возвращает количество купюр
int getBanknotes(int *&result, int *size, int summ) {
    int banknotes[7] = {50, 100, 200, 500, 1000, 2000, 5000};
    int count = 0;
    int index = 6;

    while (summ > 0) {
        if (summ >= banknotes[index]) {
            summ -= banknotes[index];
            insertInArray(result, size, banknotes[index]);
            count++;
        }
        else {
            index--;
            if (index < 0) {
                return -1;
            }
        }
    }

    return count;
}

int main() {
    int summ, size = 0;
    cout << "Вас приветствует банкомат! Какую сумму нужно выдать? ";
    cin >> summ;
    int *result = new int[1];

    int banknotesCount = getBanknotes(result, &size, summ);

    if (banknotesCount != -1) {
        cout << "Сумма выдана " << banknotesCount << " купюрами:" << endl;

        for (int i = 0; i < size; i++) {
            cout << result[i] << endl;
        }
    }
    else {
        cout << "Эту сумму выдать невозможно" << endl;
    }

    return 0;
}