#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



class Order	{
private:
    char order;
	int id;
    char side;
	string instrument;
	int qty;
	float price;
public:

    Order(char o, int i, char s, string inst, int q, float p);
	void print();
	int getTime();
	float getPrice();
	void setTime( int time );

};

Order::Order(char o, int i, char s, string inst, int q, float p) {
	
    order = o;
	id = i;
    side = s;
	instrument = inst;
	qty = q;
	price = p;
    
    // name = names[getRandom(0, namesCount - 1 )]; //название
	// price = getRandom(10000, 30000); // цена
	// timeWork = getRandom(3, 10); //время выполнения
}

void Order::print() {

}

class Trade	{
public:

    void print() ;
    bool doOrder( Order *currentOrder);
	bool paySalary();
    float getMoney();

};

int main()
{
	system("chcp 1251>nul");
	
	return 0;
}