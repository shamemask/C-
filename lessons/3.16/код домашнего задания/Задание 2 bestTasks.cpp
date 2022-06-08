#include <iostream>

using namespace std;

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

// Функция которая должен отбирает самые выгодные предложения
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

// Функция, сортирующая массив задач по времени
void sortTasksByTime(task *array, int length) {
    for (int i = 0; i < length; i++) {
        int minIndex = i;

        for (int j = i + i; j < length; j++) {
            if (array[j].time < array[i].time) {
                minIndex = j;
            }
        }

        task temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

// Функция, которая отбирает задачи по времени
void getBestTasksByTime(task *&bestTasks, int *size) {
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

    // Сортируем задачи по увеличению времени на выполнение (сортировка выбором)
    sortTasksByTime(tasks, taskCount);

    // Выбираем самые быстрые задания
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
    task emptyTask; // В начале в массиве bestTasks хранится пустая задача (на тот случай, если алгоритм не найдет подходящих задач)
    emptyTask.name = "Подходящих задач нет!";
    emptyTask.cost = 0;
    emptyTask.time = 0;

    // данные для подбора задач по стоимости
    int size = 0; // начальный размер массива
    task *bestTasks = new task[1]; // массив для самых выгодных задач
    bestTasks[0] = emptyTask;

    cout << "Набор задач №1:" << endl;
    getBestTasks(bestTasks, &size);
    cout << endl;

    // данные для подбора задач по времени
    int size2 = 0; // начальный размер массива
    task *bestTimeTasks = new task[1]; // массив для самых быстрых задач
    bestTimeTasks[0] = emptyTask;

    cout << "Набор задач №2:" << endl;
    getBestTasksByTime(bestTimeTasks, &size2);
    cout << endl;

    int cost = 0, cost2 = 0;

    cout << "Отбор по стоимости:" << endl;

    for (int i = 0; i < size; i++) {
        cout << "Выбрана задача: " << bestTasks[i].name << ". Она займет " << bestTasks[i].time << " часов и за нее заплатят " << bestTasks[i].cost << endl;
        cost += bestTasks[i].cost;
    }

    cout << "Общая стоимость: " << cost << endl << endl;

    cout << "Отбор по времени:" << endl;

    for (int i = 0; i < size2; i++) {
        cout << "Выбрана задача: " << bestTimeTasks[i].name << ". Она займет " << bestTimeTasks[i].time << " часов и за нее заплатят " << bestTimeTasks[i].cost << endl;
        cost2 += bestTimeTasks[i].cost;
    }

    cout << "Общая стоимость: " << cost2 << endl;

    return 0;
}