

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int secret_number = 1 + rand() % 10;
    int attempts = 3;
    int user_number;
    cout << "Компьютер загадал число от 1 до 10. Попробуйте его угадать." << endl;
    
    while (attempts > 0) { 
        cout << "Введи число: ";
    
        cin >> user_number;
        
        if (secret_number > user_number) { 
    
            cout << "Секретное число больше" << endl; 
        }
        if (secret_number < user_number) { 
    
            cout << "Секретное число меньше" << endl; 
        }
        if (secret_number == user_number) { 
    
            cout << "Ты угадал" << endl;
            break;
    
        }
        attempts = attempts - 1;
        cout << "Количество попыток: " << attempts << endl;
        if (attempts == 0) {

        cout << "Вы проиграли" << endl; 

        cout << "Секретное число: " << secret_number << endl;

}
    }
    
    return 0;
}
