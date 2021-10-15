#include <iostream> 

using namespace std; 

int main() 

{ 

system("chcp 1251>nul");

string name; //имя 

int age; //возраст 

int number_class; //номер класса

char littera; //буква класса 

int math; //оценка по математике 

int rus; //оценка по русскому

int info; //оценка по информатике 

cout << "Введите Ваше имя: "; 

cin >> name; 

cout << "Введите Ваш возраст: "; 

cin >> age; 

cout << "Введите Ваш номер класса: "; 

cin >> number_class; 

cout << "Введите Вашу букву класса: "; 

cin >> littera; 

cout << "Введите Вашу оценку по математике: "; 

cin >> math; 

cout << "Введите Вашу оценку по русскому: "; 

cin >> rus; 

cout << "Введите Вашу оценку по информатике: "; 

cin >> info; 

cout << "Привет! Меня зовут " << name << ". Мне " << age << " лет. Я учусь в " << number_class << littera << " классе. Моя средняя оценка по предметам: " << ((float)(math + rus + info))/3;

return 0; 

} 