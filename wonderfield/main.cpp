#include <iostream>

using namespace std;

int main()
{
    system("chcp 1251>nul");
    string word="beasts";
    bool win;
    string letters;
    char letter;
    int attempts=3;
    cout<<"Добро пожаловать в Поле чудес, нужно отгадать слово по буквам!!"<<endl;
    while(attempts>0){
            win=true;
        cout<<"Введите букву: ";
        cin>>letter;
        letters+=letter;
        cout<<int(word.find(letter))<<"  "<<letters<<endl;
            for(int i=0;i<int(word.length());i++){

                if(int(letters.find(word[i]))>=0){
                    cout<<word[i];
                }
                else{
                    cout<<'*';
                    win=false;
                }

            }
            cout<<endl;
            if(int(word.find(letter))<0){
                    attempts--;
                cout<<"Такой буквы нет, осталось "<<attempts<< " попытки"<<endl;
            }
            if(attempts==0){
                cout<<"Ты проиграл, правильное слово было \'"<<word<<"\'"<<endl;
            }
            if(win==true){
                cout<<"Congraduate your win!";
                break;
            }
    }
    return 0;
}
