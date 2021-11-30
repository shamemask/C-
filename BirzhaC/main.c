#include <string.h>
//#include <iostream.h>
//#include <fstream>
#include <direct.h>
#include <stdio.h>
#include <limits.h>

using namespace std;
int idTrade = 1;


string GetCurDir() {                                                                                            //Получение текущей директории
    char current_work_dir[FILENAME_MAX];
    _getcwd(current_work_dir, sizeof(current_work_dir));
    return current_work_dir;
}

const string inputFile = GetCurDir() + "\\input.txt";
const string outputFile = GetCurDir() + "\\output.txt";

const vector<string> explode(const string& s, const char& c)                                                    // разделитель строки на эл. массива
{
    string buff{ "" };
    vector<string> v;

    for (auto n : s)
    {
        if (n != c) buff += n; else
            if (n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if (buff != "") v.push_back(buff);
    return v;
}

string replaceDot(string v) {                                                                                   //Замена . на , в стринге, для перевода во float
    int x_ind = 0;
    for (char& ch : v) {
        if (ch == '.') {
            ch = ',';
            ++x_ind;
        }
    }
    return v;
}

class Order {                                                                                                   // Класс заявки
private:
    char order{ NULL };
    int id{ NULL };
    char side{ NULL };
    string instrument;
    int qty;
    float price;
public:
    Order() : order('\0'), id(NULL), side('\0'), instrument("\0"), qty(NULL), price(0) {};                      //Конструктор класса
    Order(const Order& order) :
        order(order.order), id(order.id), side(order.side), instrument(order.instrument), qty(order.qty),
        price(order.price) {};                                                                                  //Конструктор копирования класса
    void DoubleOrderList(Order*& pastOrd, Order*& copyOrd, int n1, int n2);                                     //Дублирование листа заявок
    int CoutOtherSide(Order* lstOrd, char* s, float* price, vector<string>* posArr, int* currCount);            // Подчет подходящих заявок
    void DoOrder(Order* lstOrd, char s, int* currCount);                                                        // Выполнение заявки
    string* GetData(Order*& lstOrd, int* ordCnt);                                                               // Загрузка данных из файла
    void OrderTraffic(Order*& lstOrd, int* ordCnt, string* buff);                                               //Обработчик данных
    bool DeleteOrder(Order* lstOrd, int* id, int* ordCnt);                                                      // Удаление заявки
    void Cancel(Order* lstOrd, int* id, int* ordCnt);                                                           //Закрытие заявки
    void Trade(Order* lstOrd, Order* OB, Order* OS, char s, int* ordCnt);                                       //Операция Покупки/Продажи
    void PrintTrade(char* s, int* OID1, int* ID2, int* q, float* p);                                            //Вывод результата Покупки/продажи файл
    void printAll(Order* lstOrd, int* ordCnt);                                                                  // Вывод операций в консоль
    ~Order() {};                                                                                                //Деструктор класса
};

void Order::DoubleOrderList(Order*& pastOrd, Order*& copyOrd, int n1CreateArr, int n2DoubleArr) {               //Дублирование листа заявок
    pastOrd = new Order[n1CreateArr + 1];
    int i = -1;
    do{
        ++i;
        pastOrd[i] = Order(copyOrd[i]);
        //CopyOrder(pastOrd, i, copyOrd, i, n);
    } while (i < n2DoubleArr);
    delete[] copyOrd;
}

int Order::CoutOtherSide(Order* lstOrd, char* s, float* price, vector<string>* posArr, int* currCount)          // Подчет подходящих заявок
{
    int count= 0;
    string posStr{};
    for (int i = 0; i < *currCount; ++i)
    {
        if (lstOrd[*currCount].side != lstOrd[i].side){
            if ((lstOrd[i].side == 'S' && lstOrd[i].price <= lstOrd[*currCount].price)
                || lstOrd[i].side == 'B' && lstOrd[i].price >= lstOrd[*currCount].price)
            {
                ++count;
                posStr += to_string(i) + ',';
            }
        }
    }
    *posArr={ explode(posStr, ',') };
    return count;
}

void Order::DoOrder(Order* lstOrd, char s, int *currCount) {                                                    // Выполнение заявки
    float minPrice = numeric_limits<float>::max();
    float maxPrice = numeric_limits<float>::min();
    int pos{-1};
    int circlePos = 0;
    int circleCount = 0;
    vector<string> posArr;
    int i{};
    while (circleCount=CoutOtherSide(lstOrd, &s, &lstOrd[*currCount].price, &posArr, currCount))
    {

            for (i = circleCount-1; i >= 0; i--)
            {
                circlePos = stoi(posArr[i]);
                if (lstOrd[circlePos].price <= minPrice && s == 'B')
                {
                    pos = circlePos;
                    minPrice = lstOrd[circlePos].price;
                }
                if (lstOrd[circlePos].price >= maxPrice && s == 'S')
                {
                    pos = circlePos;
                    maxPrice = lstOrd[circlePos].price;
                }
            }
            if(pos != -1)
                Trade(lstOrd, &lstOrd[*currCount], &lstOrd[pos], lstOrd[pos].side, currCount);

            minPrice = numeric_limits<float>::max();
            maxPrice = numeric_limits<float>::min();
            circleCount = 0;
            pos = -1;
    }
}

string* Order::GetData(Order*& lstOrd, int* ordCnt) {                                                           // Загрузка данных из файла

    string* arrBuff{};
    ofstream outFile(outputFile);
    ifstream file(inputFile, ios::in);
    if (file.is_open()) {
        string str;
        while(getline(file,str))
            ++*(ordCnt);

        file.clear();
        file.seekg(0);
        int i = 0;
        arrBuff = new string[*ordCnt+1];
        while (getline(file, arrBuff[i]))
            ++i;

        file.close();
    }

    return arrBuff;
}

void Order::OrderTraffic(Order*& lstOrd, int* ordCnt, string* buff) {                                           //Обработчик данных
    int id = 0;
    int i{0};
    lstOrd = new Order[1];
    Order* secLstOrd = nullptr;
    for (int y = 0; y < *ordCnt; ++y) {
        vector<string> v{ explode(buff[y], ',') };

        if (v[0][0] == 'O') {
            lstOrd[i].order = v[0][0];
            lstOrd[i].id = stoi(v[1]);
            lstOrd[i].side = v[2][0];
            lstOrd[i].instrument = "Яблоки";
            lstOrd[i].qty = stoi(v[3]);
            lstOrd[i].price = stod(replaceDot(v[4]));
            DoOrder(lstOrd, lstOrd[i].side, &i);
        }
        else if(v[0][0] == 'C')
        {
            id = stoi(v[1]);
            Cancel(lstOrd, &id, &i);
        }
        DoubleOrderList(secLstOrd, lstOrd, i, i);
        //printAll(secLstOrd, &i); // выводит операции в консоль
        ++i;
        DoubleOrderList(lstOrd, secLstOrd, i, i - 1);
    }
}

bool Order::DeleteOrder(Order* lstOrd, int* id, int* ordCnt) {                                                  //Удаление заявки
    for (int y = 0; y < *(ordCnt)+1; ++y) {

        if (lstOrd[y].id == *id)
        {
            for (int i = y; i < *(ordCnt); ++i) {
                lstOrd[i] = Order(lstOrd[i + 1]);
            }
            --*ordCnt;
            return true;
        }
    }
    return false;
}

void Order::Cancel(Order* lstOrd, int* id, int* ordCnt) {                                                        //Закрытие заявки
    if (DeleteOrder(lstOrd, id, ordCnt)) {
        ofstream file(outputFile, ios::app);
        file << "X," << *id << "\n";

    }
    --* ordCnt;
}

void Order::Trade(Order* lstOrd, Order* OB, Order* OS, char s, int* ordCnt) {                                   //Операция Покупки/Продажи
    int q, OID1, OID2;
    float p;
    OID1 = OS->id;
    OID2 = OB->id;
    p = OS->price;
    if (OB->qty > OS->qty) {
        OB->qty = OB->qty - OS->qty;
        q = OS->qty;
        DeleteOrder(lstOrd, &OS->id, ordCnt);

    }
    else if (OB->qty < OS->qty) {
        OS->qty = OS->qty - OB->qty;
        q = OB->qty;
        DeleteOrder(lstOrd, &OB->id, ordCnt);
    }
    else {
        q = OS->qty;
        DeleteOrder(lstOrd, &OB->id, ordCnt);
        DeleteOrder(lstOrd, &OS->id, ordCnt);
    }

    PrintTrade(&s, &OID1, &OID2, &q, &p);
}

void Order::PrintTrade(char* s, int* OID1, int* OID2, int* q, float* p) {                                       //Вывод результата Покупки/продажи файл
    ofstream file(outputFile, ios::app);
    int zero = *p;
    file << "T" << "," << idTrade++ << "," << *s << "," << *OID1 << ",";
    file << *OID2 << "," << *q << "," << *p;
    if (*p - zero == 0)
        file << ".0";
    file << "\n";
}

void Order::printAll(Order* lstOrd, int* ordCnt) {                                                             // Вывод операций в консоль
    system("cls");
    int i = -1;
    do {
        ++i;
        cout << lstOrd[i].order << "," << lstOrd[i].id << "," << lstOrd[i].side;
        cout << "," << lstOrd[i].instrument << ",";
        cout << lstOrd[i].qty << "," << lstOrd[i].price << endl;
    }while (i < *ordCnt);
    system("pause");
}

int main()
{
    setlocale(LC_ALL, "RUS");
    system("chcp 1251>nul");

    Order* orderList = nullptr;
    int* countOrder = new int;
    *countOrder = 0;
    string* DataBuff;
    cout << "Считывание данных из input.txt" << endl;
    DataBuff = orderList->GetData(orderList, countOrder);
    cout << "Загрузка данных в output.txt ..." << endl;
    orderList->OrderTraffic(orderList, countOrder, DataBuff);
    cout << "Данные загружены!"<< endl;
    delete DataBuff;
    delete countOrder;
    delete[] orderList;
    return 0;
}
