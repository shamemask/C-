#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>

using namespace std;

int main()
{
    string cont;
    do{
        cout << "Welcome to Daily Planer!" << endl;
        cout << "You can:" << endl;
        cout << "1. open existing dairy" << endl;
        cout << "2. create new" << endl;
        cout << "input 1 or 2: ";

        int input;
        cin >> input;

        if (input == 1) {
            cout << "Enter name of file: ";
            string fileName;
            getchar();
            getline(cin, fileName);
            fileName = "D:\\whatever\\" + fileName + ".txt";
            cout << fileName << endl;
            ifstream file(fileName);
            while (!file.is_open()) {
                cout << "Can`t open this file!!!" << endl << "Try to reenter a name of file or enter \"exit\" to leave: ";
                getline(cin, fileName);

                if (fileName == "exit")
                    break;

                fileName = "D:\\whatever\\" + fileName + ".txt";
                cout << fileName << endl;
                file.open(fileName);
            }
            if (file.is_open()) {
                char buffer[255];
                while (!file.eof()) {
                    file.getline(buffer, sizeof(buffer));
                    cout << buffer << "\n";
                }
                file.close();

                cout << "\nYou can:\n1. add something to the end of file\n2. close the application\ninput 1 or 2: ";
                cin >> input;
                if (input == 1) {
                    ofstream file(fileName, ios::app);
                    cout << "What do you want to write into this daily planer?" << endl << "Enter \"EXIT\" for leave" << endl;
                    cout << "Text:\n";
                    string s;
                    while (s != "EXIT")
                    {
                        getline(cin, s);
                        if (s != "EXIT")
                            file << s << "\n";
                    }
                    file.close();
                }
            }
        }
        else if (input == 2) {
            cout << "What name do you want for this diary?" << endl;
            string fileName;
            getchar();
            getline(cin, fileName);

            fileName = "D:\\whatever\\" + fileName + ".txt";
            cout << "Current PATH is " << fileName << endl;
            ofstream file(fileName);

            cout << "What do you want to write into this daily planer?" << endl << "Enter \"EXIT\" for leave" << endl;
            cout << "Text:\n";
            string s;
            while (s != "EXIT")
            {
                getline(cin, s);
                if (s != "EXIT")
                    file << s << "\n";
            }
            file.close();
        }
        cout << "If you want to do something else then enter YES, else enter NO: ";
        getline(cin, cont);
    } while (cont == "YES");

    return 0;
}
