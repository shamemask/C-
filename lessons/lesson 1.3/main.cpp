#include <iostream>

using namespace std;

int main() {

setlocale(LC_ALL, "Russian");

int a, b, c;

cout << "Введите первое число: ";

cin >> a;

cout << "Введите второе число: ";

cin >> b;

cout << "Введите третье число: ";

cin >> c;

int maximum;

if (a > c) {

if (a > b) {

maximum = a;

}

else {

maximum = b;

}

}

else {

if (b > c) {

maximum = b;

}

else {

maximum = c;

}

}

cout << "Максимальное число: " << maximum;

return 0;

}
