#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Windows.h"
using namespace std;

const int namesCount = 5;
const string names[namesCount] = {
	"Выполнить верстку сайта ",
	"Написать телеграмм-бот  ",
	"Создать интернет-магазин", 	
	"Разработать 3д-игру     ",
	"Нарисовать логотип      "
};

int getRandom(int min, int max) {
	return rand() % (max - min + 1) + min;
}

class Order {
private:
	string name; //название
	float price; // цена
	int timeWork; //время выполнения
public:
	Order();
	void print();
	int getTime();
	float getPrice();
	void setTime( int time );
};

Order::Order() {
	name = names[getRandom(0, namesCount - 1 )]; //название
	price = getRandom(10000, 30000); // цена
	timeWork = getRandom(3, 10); //время выполнения
}
void Order::print() {
	cout << "---------------------------------" << endl;
	cout << "Заказ: " << name << "  |  ";
	cout << "Цена: " << price << "  |  ";
	cout << "Время выполнения: " << timeWork << "  |  " << endl;
}

void Order::setTime( int time ) {
	timeWork = time;
}

int Order::getTime() {
	return timeWork ;
} 

float Order::getPrice() {
	return price;
}

class Company {
private:
	string name; //название
	float money; //баланс денег
	int employees; //количество работников
	int orders; //количество выполненных заказов
	float salary; //зарплата 1 работника
public:
	Company();
	void print();
	bool doOrder( Order *currentOrder);
	bool paySalary();
	void hireEmploees();
	float getMoney();
};

Company::Company() {
	cout << "Название компании: ";
	cin >> name; //имя введено с клавиатуры
	money = 0;     //пока на счету нет ни рубля
	employees = 1;//хотя бы 1 работник есть, он же - директор
	orders = 0;//заказов еще не выполняли
	cout << "Зарплата: ";
	cin >> salary; //зарплата 1 работника
}

void Company::print() {
	cout << "Компания: " << name << endl;
	cout << "Баланс: " << money << endl;
	cout << "Количество работников: " << employees << endl;
	cout << "Выполнено заказов: " << orders << endl;
	cout << "Зарплата: " << salary << endl;
}

bool Company::doOrder( Order* currentOrder )
{
	cout << "Выполняю заказ: " << endl;
	currentOrder->print();
	
	currentOrder->setTime(currentOrder->getTime() - 1 * employees);
	bool result = false;

	if (currentOrder->getTime() > 0)
	{
		cout << "До окончания выполнения заказа осталось: " << currentOrder->getTime() << " дн." << endl;
		result = false;
	}
	else
	{
		cout << "Заказ выполнен"<<endl;
		money += currentOrder->getPrice();
		orders++;
		result = true;
	}
	Sleep(1500);
	return result;
}

bool Company::paySalary()
{
	float summa = salary * employees;
	money -= summa;
	cout << "!!!Выплачена зарплата!!! "<< summa<<endl;
	if (money >= 0)
		return true;
	else
		return false;
}

void Company::hireEmploees()
{
	int count;
	cout << "Сколько нанять новых работников? ";
	cin >> count;

	employees += count;
	if (count > 0)
		cout << "!!!Наняли работников!!!" << endl;
}
float Company::getMoney() {
	return money;
}

int main()
{
	system("chcp 1251>nul");
	srand(time(0));
	cout << "Привет! Сегодня у тебя есть шанс создать и развить собственную IT-компанию." << endl;
	Company myCompany;
	
	int day = 1;
	int currentOrderNumber = -1;

	int orderCount = getRandom(3, 10);
	Order* orderList = new Order[orderCount];

	int gameState = 0;
	while ( gameState == 0 )
	{
		system("cls");
		cout << "День " << day << endl << endl;

		if (day % 15 == 0)
		{
			if(!myCompany.paySalary())
				gameState = -1;
		}

		if (myCompany.getMoney() >= 1000000)
		{
			gameState = 1;
		}

		
		if (gameState == 0)
		{
			myCompany.print();

			if (day % 10 == 0)
				myCompany.hireEmploees();

			if (currentOrderNumber == -1)
			{
				cout << "Список заказов: " << endl;

				for (int i = 0; i < orderCount; i++)
				{
					orderList[i].print();
					cout << "Номер заказа: " << i << endl;
				}

				cout << "Выберите заказ из списка: " << endl;
				cin >> currentOrderNumber;
			}

			if (myCompany.doOrder(&orderList[currentOrderNumber]))
			{
				currentOrderNumber = -1;
				delete[] orderList;
				orderCount = getRandom(3, 10);
				orderList = new Order[orderCount];
			}

			day++;
		}
	}

	if (gameState == 1)
		cout << "Поздравляем! Вы миллионер!" << endl;
	else
		cout << "Вы банкрот! Попробуйте еще раз..." << endl;

	delete[] orderList;
	
	
	return 0;
}
