//пузырьковая сортировка
void bubble_sort(int* nums, int mas_size) {
	for (int i = 0; i < mas_size; i++) {
		for (int j = 0; j < mas_size - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int a = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = a;
			}
		}
	}
}

//сортировка выбором
void selectionSort(int* numbers, int n)
{
	int counter = 0;
	for (int i = 0; i < n; i++) {
		//Исходно считаем наименьшим первый элемент
		int min_i = i;
		//Этот цикл перебирает несортированные элементы
		for (int j = i + 1; j < n; j++)
		{
			counter++;
			if (numbers[j] < numbers[min_i])
			{
				min_i = j;
			}
		}
		int buf = numbers[i];
		numbers[i] = numbers[min_i];
		numbers[min_i] = buf;
	}
}

//сортировка вставками
void insertionSort(int* array, int length) {

	for (int i = 1; i < length; i++) {

		int current = array[i];

		int prevIndex = i - 1;

		while (prevIndex >= 0 && current < array[prevIndex]) {

			array[prevIndex + 1] = array[prevIndex];

			array[prevIndex] = current;

			prevIndex--;

		}

	}

}

//сортировка Шелла
void shellSort(int* num, int size)

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
			while ((j >= increment) && (current < num[j - increment]))
			{ // пока отстоящий элемент больше текущего
				num[j] = num[j - increment]; // перемещаем его на текущую позицию
				j = j - increment; // переходим к следующему стоящему элементу
			}
			num[j] = current; // на выявленное место помещаем сохраненный элемент 
		}

	}

}