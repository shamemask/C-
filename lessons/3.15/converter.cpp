#include <iostream>
#include <cmath>
using namespace std;


// Для перевода в двоичную систему
string convertFromDec(int number) {
    string result = "";
    while (number > 0) {
        int remainder = number % 2;
        result = to_string(remainder) + result; // запись остатков от деления идет справа налево
        number /= 2;
    }
    return result;
}

// Для перевода в систему с основанием  radix
string convertFromDec(int number, int radix) {
    char hexSymbols[6] = {'A', 'B', 'C', 'D', 'E', 'F'}; // Массив букв, обозначающих цифры 10-15 шестнадцатеричной системы счисления
    string result = "";
    while (number > 0) {
        int remainder = number % radix;
        if (remainder > 9) { // Проверяем, что остаток больше 9
            result = hexSymbols[remainder - 10] + result; // Чтобы получить индекс нужной буквы, нужно от остатка отнять 10
        }
        else {
            result = to_string(remainder) + result;
        }
        
        number /= radix;
    }
    return result;
}

// Проверяет, что символ содержит цифру
bool isInteger(char symbol) {
    if (symbol >= '0' && symbol <= '9') {
        return true;
    }
    return false;
}

// Преобразует символ, содержащий цифру, в целое число
int charToInt(char symbol) {
    return int(symbol) - int('0');
}

// Возвращает индекс элемента symbol в массиве array
int getIndex(char symbol, char array[], int length) {
    for (int i = 0; i < length; i++) {
        if (array[i] == symbol) {
            return i;
        }
    }
    return -1;
}

// Преобразует в десятичное число с основанием radix
int convertToDec(string number, int radix) {
    char hexSymbols[6] = {'A', 'B', 'C', 'D', 'E', 'F'}; // Массив букв, обозначающих цифры 10-15 шестнадцатеричной системы счисления
    int result = 0;
    int lastIndex = number.length() - 1; // последний индекс строки, содержащий число
    int degree = lastIndex; // степень, в которую нужно возвести основание

    for (int i = 0; i <= lastIndex; i++) {
        char currentChar = number[i]; // текущий символ строки
        int currentNumber; // переменная для символа, преобразованного в целое число
    
        if (isInteger(currentChar)) {
            currentNumber = charToInt(currentChar);
        }
        else {
            currentNumber = getIndex(currentChar, hexSymbols, 6) + 10; // Прибавляем 10 к индексу и получаем десятичное число, соответствующее шестнадцатеричной букве-цифре
        }
        result += currentNumber * pow(radix, degree);
        
        degree--; // степень уменьшается слева направо
    }
    return result;
}

int main() {
    int decimal, radix;
    cout << "Введите десятичное число: ";
    cin >> decimal;
    cout << "Введите основание системы для перевода: ";
    cin >> radix;
    cout << "Число " << decimal << " в " << radix << " системе счисления: " << convertFromDec(decimal, radix) << endl;

    
    string notDecimal;
    cout << "\nВведите основание системы счисления (до 16): ";
    cin >> radix;
    cout << "Введите число: ";
    cin >> notDecimal;
    cout << "Число " << notDecimal << " в 10 системе счисления: " << convertToDec(notDecimal, radix) << endl;
    
    return 0;
}
