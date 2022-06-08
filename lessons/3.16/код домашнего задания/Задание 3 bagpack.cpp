#include <iostream>

using namespace std;

// Структура для вещей
struct thing
{
    string name;
    int importance;
    float weight;
};

// Функция, вставляющая элемент в конец динамического массива
void insertInArray(thing *&pA, int *size, thing element) {  
    (*size)++;
    thing *newPA = new thing[*size];
    for (int i = 0; i < *size - 1; i++) {
        newPA[i] = pA[i];
    }

    newPA[*size - 1] = element;
    delete[] pA;
    pA = newPA;
}

// Функция, сортирующая массив вещей по необходимости
void sortThings(thing *array, int length) {
    for (int i = 0; i < length; i++) {
        int maxIndex = i;

        for (int j = i + i; j < length; j++) {
            if (array[j].importance > array[i].importance) {
                maxIndex = j;
            }
        }

        thing temp = array[i];
        array[i] = array[maxIndex];
        array[maxIndex] = temp;
    }
}

// Функция для отбора самых необходимых вещей
void getMostImportantThings(thing *&mostImportantThings, int *size) {
    int thingsCount;
    float maxWeight;

    cout << "Какой максимальный вес рюкзака (в килограммах)? ";
    cin >> maxWeight;

    cout << "Сколько всего вещей? ";
    cin >> thingsCount;

    thing things[thingsCount];

    // Получаем список вещей
    for (int i = 0; i < thingsCount; i++) {
        thing currentThing;
        cout << "Введите название вещи: ";
        cin >> currentThing.name;

        cout << "Введите необходимость вещи (от 1 до 100): ";
        cin >> currentThing.importance;

        cout << "Введите вес (в килограммах): ";
        cin >> currentThing.weight;

        things[i] = currentThing;
    }

    // Сортируем вещи по уменьшению необходимости (сортировка выбором)
    sortThings(things, thingsCount);

    // Выбираем самые необходимые вещи
    for (int i = 0; i < thingsCount; i++) {
        thing current = things[i];
        if (current.weight <= maxWeight) {
            insertInArray(mostImportantThings, size, current);
            maxWeight -= current.weight;
        }
    }
}

int main() {
    int size = 0; // начальный размер массива
    float weight = 0;
    thing *mostImportantThings = new thing[1]; // массив для самых нужных вещей

    getMostImportantThings(mostImportantThings, &size);

    if (size != 0) {
        cout << "\nВыбраны следующие вещи: " << endl;
        for (int i = 0; i < size; i++) {
            cout << mostImportantThings[i].name << ", весит " << mostImportantThings[i].weight << endl;
            weight += mostImportantThings[i].weight;
        }
        cout << "Вес рюкзака: " << weight << endl;
    }
    else {
        cout << "\nНичего не выбрано" << endl;
    }

    return 0;
}