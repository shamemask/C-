
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
using namespace std;


//Игра "Жизнь"
//функция для ввода начального расположения клеток во Вселенной
void createArray(int **&A, int m, int n)
{
	A = new int*[m]; // создаем массив указателей
	cout << "Вводите элементы массива:" << endl;
	for (int i = 0; i < m; i++)
	{
		A[i] = new int[n];  //выделяем память под каждую строку
		for (int j = 0; j < n; j++)
		{
			cout << "A[" << i << "][" << j << "] = ";
			cin >> A[i][j];
		}
	}
}
//функция создания рандомного начального расположения клеток во Вселенной
void createRandom(int **&A, int m, int n)
{
	srand(time(0)); // устанавливаем значение системных часов
	// в качестве стартового числа
	A = new int*[m]; // создаем массив указателей
	for (int i = 0; i < m; i++)
	{
		A[i] = new int[n];  //выделяем память под каждую строку
		for (int j = 0; j < n; j++)
			A[i][j] = rand() % 2;
	}
	return;
}

void outputArray(int **A, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (A[i][j] == 1)
				cout << "*";
			else
				cout << " ";
		cout << endl;
	}
	return;
}
//функция для расчета количества соседей у клетки
int neighborsCount(int **A, int m, int n, int x, int y)
{
	int count = 0;
	// соседи слева
	if (x > 0 && y > 0)//не левая верхняя клетка
		count += A[x - 1][y - 1];
	if (x > 0)//не верхняя строка
		count += A[x - 1][y];
	if (x > 0 && y < (n - 1))//не левая нижняя клетка
		count += A[x - 1][y + 1];
	//соседи сверху и снизу
	if (y > 0)//не левый столбец
		count += A[x][y - 1];
	if (y < (n - 1))//не правый столбец
		count += A[x][y + 1];
	//соседи справа
	if (x < (m - 1) && y > 0)//не правая верхняя клетка
		count += A[x + 1][y - 1];
	if (x < (m - 1))//не нижняя строка
		count += A[x + 1][y];
	if (x < (m - 1) && y < (n - 1))//не правая нижняя клетка
		count += A[x + 1][y + 1];
	return count;
}
//функция копирования одного массива в другой
void copyArray(int **&A, int **B, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = B[i][j];
	return;
}
//главная функция игры
int main()
{
    system("chcp 1251 > null");
	int m, n;
	int **A;
	cout << "Введите размер двумерного массива:" << endl;
	cin >> m >> n;
	cout << "Если хотите вручную ввести значения, нажмите 1." << endl;
	cout << "Если хотите создать сгенерировать случайные значения, нажмите 0." << endl;
	bool answer;
	cin >> answer;
	if (answer)
		createArray(A, m, n);
	else createRandom(A, m, n);

	int generationCout;
	cout << "Сколько поколений сгенерировать?" << endl;
	cin >> generationCout;

	//outputArray( A, m, n );
	int **B;//массив-буфер для создания следующего поколения
	createRandom(B, m, n);
	for (int k = 0; k < generationCout; k++)
	{ //очистим консоль для вывода текущего поколения
		system("cls");
		// генерируем новое поколение, записываем в B
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				int count = neighborsCount(A, m, n, i, j);
				// проверяем второе правило
				if (count == 2 || count == 3) B[i][j] = A[i][j];
				// проверяем первое правило
				if (A[i][j] == 0 && count == 3)
					B[i][j] = 1;
				else if (count < 2 || count > 3)// проверяем третье правило
					B[i][j] = 0;
			}
		//копируем в A новое поколение
		copyArray(A, B, m, n);
		//выводим поколение
		outputArray(A, m, n);
		//поставим задержку, чтобы успевать смотреть, как меняются поколения
		sleep(1);
	}
	for (int i = 0; i < m; i++)
	{
		delete[] A[i];  // удаляем каждую строку массива
		delete[] B[i];  // удаляем каждую строку массива
	}
	delete[] A; //удаляем указатели на удаленные выше строки
	delete[] B; //удаляем указатели на удаленные выше строки
	return 0;
}

