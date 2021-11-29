#include <iostream> 
#include <string>
using namespace std;


class Animal {
private:
	int speed;
string name;

public:
	void run() {
		cout << "I run with speed " << speed << "\n";
	}
	void say() {
		cout << "My name is " << name << "\n";
	}

	void setProperties(int s, string n) {
		speed = s;
		name = n;
	}
};

class Cat : public Animal {
	int eye;
public:

	void setEye(int e) {
		eye = e;
	}

	void climbOnTree() {
		cout << "I climb on tree\n";
	}

	void meow() {
		cout << "Meow\n";
	}

	void say() {
		cout << "I say: meow\n";
	}

};

class Dog : public Animal {
public:

	void find() {
		cout << "I found\n";
	}

	void say() {
		cout << "I say: Woof\n";
	}

};

int main()
{
	Animal cat;
	cat.setProperties(3, "Barsik");
	cat.say();
	cat.run();
	Cat cat2;
	cat2.setProperties(5, "Liza");
	cat2.say();
	cat2.run();
	cat2.climbOnTree();
	cat2.meow();
	Dog dog2;
	dog2.setProperties(7, "Tyzik");
	dog2.say();
	dog2.run();
	dog2.find();
	return 0;
}