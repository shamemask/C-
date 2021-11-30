#include <iostream>
#include <cmath>
using namespace std;

void print(int a, int b = 10){
    cout << a + b << endl;
}

int someFun(){
return 123;
}

int main()
{

    print(123);
    int receiver = someFun();
    print(receiver);
    return 0;
}
