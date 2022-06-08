#include <iostream>

#include <cstdlib>

#include <ctime>

#include <iomanip>

using namespace std;



void insertionSort(int *array, int length) {

	for (int i = 1; i < length; i++) {

	int current = array[i];

	int prevIndex = i - 1;

	while (prevIndex >= 0 && current < array[prevIndex] ) {

		array[prevIndex + 1] = array[prevIndex];

		array[prevIndex] = current;

		prevIndex--;

		}

	}

}

void shellSort(int *num, int size)

{

	for (int increment = size / 2; increment > 0; increment = increment / 2)

	//цикл по приращениям

	{

		for (int i = increment; i < size; i++) // для всех элементов массива 

		{ 
			int j = i; // сохраняем индекс и элемент 
			int current = num[i]; 

			// просматриваем остальные элементы массива, отстоящие от j-ого
			// на величину приращения
			while ((j >= increment) && ( current < num[j - increment] ))
			{ // пока отстоящий элемент больше текущего
				num[j] = num[j - increment]; // перемещаем его на текущую позицию
				j = j - increment; // переходим к следующему стоящему элементу
			}
			num[j] = current; // на выявленное место помещаем сохраненный элемент 
		} 

	}

} 

int main()

{

	srand(time(0));

	int size;

	cin >> size;



	int *sortArray = new int [size];

	cout << "Создан массив случайных чисел:" << endl;

	for (int i = 0; i < size; i++) {

		sortArray[i] = rand() % 100;

		cout << setw(3) << sortArray[i] << " ";

	}

	cout << endl;



	insertionSort(sortArray, size);

	cout << "Массив отсортирован вставками:" << endl;
	
	//shellSort(sortArray, size);

	//cout << "Массив отсортирован алгоритмом Шелла:" << endl;

	for (int i = 0; i < size; i++)

		cout << setw(3) << sortArray[i] << " ";

	cout << endl;



	delete [] sortArray;

	return 0;

}