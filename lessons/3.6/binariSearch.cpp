#include <iostream>

using namespace std;

int main()

{
    system("chcp 1251>nul");
    int left, right, len, current;
    char s;
    cout << "Минимальное число: ";
    cin >> left;
    cout << "Максимальное число: ";
    cin >> right;
    cout << "Загадай число от " << left << " до " << right << ", а я отгадаю его менее чем за 10 шагов" << endl;
    int attempts = 0;
    while (true) {
        attempts++;
        cout << "Сейчас " << attempts << " попытка" << endl;
        len = right - left;
        current = len / 2 + left;
        cout << "Ваше число - "<< current<< "? (=, >, <)";
        cin >> s;
        if (s == '>') {
            left = current + 1;
            cout << "Левая граница - " << left << ", правая граница - " << right << endl;
        }
        else if (s == '<') {
            right = current - 1;
            cout << "Левая граница - " << left << ", правая граница - " << right << endl;
        }
        else {
            cout << "Я угадал, ура!" << endl;
            break;
        }
    }
    return 0;
}
