#include <iostream>

using namespace std;

// Функция для банкомата, которому нужно выдать сумму минимальным количеством купюр
// Банкомат может выдавать только бумажные купюры от 50 до 5000 рублей
// Возвращает минимальное количество купюр, если сумму нельзя выдать - возвращает -1
int getBanknotes(int summ) {
    int banknotes[7] = {50, 100, 200, 500, 1000, 2000, 5000};
    int count = 0;
    int index = 6;

    while (summ > 0) {
        if (summ >= banknotes[index]) {
            summ -= banknotes[index];
            cout << "Выдана купюра номиналом "  << banknotes[index] << " осталось выдать " << summ << endl;
            count++;
        }
        else {
            index--;
            if (index < 0) {
                return -1;
            }
        }
    }

    return count;
}



// Структура для заданий
struct task
{
    string name;
    int cost;
    float time;
};

// Функция, вставляющая элемент в конец динамического массива
void insertTaskInArray(task *&pA, int *size, task element) {  
    (*size)++;
    task *newPA = new task[*size];
    for (int i = 0; i < *size - 1; i++) {
        newPA[i] = pA[i];
    }

    newPA[*size - 1] = element;
    delete[] pA;
    pA = newPA;
}

// Функция, сортирующая массив задач
void sortTasks(task *array, int length) {
    for (int i = 0; i < length; i++) {
        int maxIndex = i;

        for (int j = i + i; j < length; j++) {
            if (array[j].cost > array[i].cost) {
                maxIndex = j;
            }
        }

        task temp = array[i];
        array[i] = array[maxIndex];
        array[maxIndex] = temp;
    }
}

// Функция для бота, который должен отбирать самые выгодные предложения
// Известно, что человек, использующий робота, может работать h часов в день.
// При этом ему поступают разные задания, для каждого задания известна стоимость и время выполнения
// Задача бота - подобрать самые выгодные задания, которые можно выполнить за h часов и заработать максимальное количество денег
// (тут можно какую-нибудь вариацию про миссии в игре, которые занимают определенное время и вознаграждаются определенным количеством виртуальных монет)
// Функция спрашивает количество часов и задач
// Функция записывает лучшие задания в динамический массив bestTasks
void getBestTasks(task *&bestTasks, int *size) {
    int taskCount;
    float hours;

    cout << "Сколько часов вы будете работать? ";
    cin >> hours;

    cout << "Сколько сегодня задач? ";
    cin >> taskCount;

    task tasks[taskCount];

    // Получаем задачи
    for (int i = 0; i < taskCount; i++) {
        task newTask;
        cout << "Введите название задачи: ";
        cin >> newTask.name;

        cout << "Введите стоимость задачи: ";
        cin >> newTask.cost;

        cout << "Введите время, которое нужно потратить на задачу (в часах): ";
        cin >> newTask.time;

        tasks[i] = newTask;
    }

    // Сортируем задачи по уменьшению стоимости (сортировка выбором)
    sortTasks(tasks, taskCount);

    // Выбираем самые дорогие задания
    for (int i = 0; i < taskCount; i++) {
        task current = tasks[i];
        if (current.time <= hours) {
            insertTaskInArray(bestTasks, size, current);
            hours -= current.time;
        }
    }

    // если ни одной задачи не выбрано, нужно указать, что массив не пустой (в нем хранится "пустая" задача)
    if (*size == 0) {
        *size = 1;
    }
}

int main() {
    // данные для банкомата
    int summ;
    cout << "Вас приветствует банкомат! Какую сумму нужно выдать? ";
    cin >> summ;
    int banknotesCount = getBanknotes(summ);

    if (banknotesCount != -1) {
        cout << "Сумма выдана " << banknotesCount << " купюрами" << endl;
    }
    else {
        cout << "Эту сумму выдать невозможно" << endl;
    }

    cout << endl;

    // данные для подбора задач
    int size = 0; // начальный размер массива
    task emptyTask; // В начале в массиве bestTasks хранится пустая задача (на тот случай, если алгоритм не найдет подходящих задач)
    emptyTask.name = "Подходящих задач нет!";
    emptyTask.cost = 0;
    emptyTask.time = 0;

    task *bestTasks = new task[1]; // массив для самых выгодных задач
    bestTasks[0] = emptyTask;

    getBestTasks(bestTasks, &size);

    for (int i = 0; i < size; i++) {
        cout << "Выбрана задача: " << bestTasks[i].name << ". Она займет " << bestTasks[i].time << " часов и за нее заплатят " << bestTasks[i].cost << endl;
    }
    return 0;
}