#include <iostream>

using namespace std;

// Структура для точки
struct point
{
    string name;
    float time;
};

// Функция, вставляющая элемент в конец динамического массива
void insertInArray(point *&pA, int *size, point element) {  
    (*size)++;
    point *newPA = new point[*size];
    for (int i = 0; i < *size - 1; i++) {
        newPA[i] = pA[i];
    }

    newPA[*size - 1] = element;
    delete[] pA;
    pA = newPA;
}


// Функция для подбора кратчайшего пути, возвращает количество остановок или -1, если путь нельзя пройти
int getBestWay(point *&resultPoints, int *size, point *points, int pointsCount, float hours) {
    int currentI = 0;
    int nextI = 1;
    float currentHours = 0;
    int count = 1; // первую точку тоже считаем

    // Выбираем точки для остановки
    while (nextI <= pointsCount - 1) {
        currentHours += points[nextI].time;
        // если у нас хватает времени дойти до следующей точки - проверим следующую за ней
        if (currentHours <= hours) {
            // если следующая точка - последняя, то мы можем дойти до конца и ее нужно добавить в массив
            if (nextI == pointsCount - 1) {
                currentI = nextI;
                insertInArray(resultPoints, size, points[currentI]);
                count++;
            }
            nextI++;
        }
        else {
            // если точки не соседние
            if (nextI - currentI > 1) {
                currentI = nextI - 1;
                insertInArray(resultPoints, size, points[currentI]);
                currentHours = 0;
                count++;
            }
            else {
                return -1; // если точки соседние и мы не можем дойти из одной в другую, значит путь пройти нельзя
            }
        }
    }

    return count;
}

// главная функция
int main() {
    int pointsCount;
    float hours;

    cout << "Введите максимальное количество остановок от начала до конца пути (включая начальную и конечную точку): ";
    cin >> pointsCount;

    cout << "Сколько вы можете пройти за день (в часах)? ";
    cin >> hours;

    point points[pointsCount];

    // Получаем список точек
    for (int i = 0; i < pointsCount; i++) {
        point current;

        cout << "Введите название точки: ";
        cin >> current.name;

        cout << "За сколько часов до нее можно добраться из предыдущей точки: ";
        cin >> current.time;

        points[i] = current;
    }

    // массив для точек, в которых нужно сделать остановку
    point *result = new point[1];
    result[0] = points[0];
    int size = 1;

    int stopPointsCount = getBestWay(result, &size, points, pointsCount, hours);

    if (stopPointsCount == -1) {
        cout << "Слишком большое расстояние между точками, до конца дойти не получится" << endl;
    }
    else {
        cout << "Маршрут построен! Остановки необходимы в " << stopPointsCount << " точках:" << endl;
        for (int i = 0; i < size; i++) {
            cout << result[i].name << endl;
        }
    }

    return 0;
}