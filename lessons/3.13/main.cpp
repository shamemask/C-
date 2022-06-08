#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
using namespace sf;

const int WINDOW_WIDTH = 1260;

const int WINDOW_HEIGHT = 720;

void drawArray(RenderWindow& window, int* array, int size)
{
	
	/*RectangleShape rectangle(Vector2f(100, 200));

	rectangle.setPosition(200, 300);

	rectangle.setFillColor(Color(255, 69, 0));

	window.draw(rectangle);	 */
	//ширина прямоугольника
	int width = WINDOW_WIDTH / size;
	for (int i = 0; i < size; i++)
	{
		//создаем прямоугольник стандартной ширины и высоты равной значению элемента массива
		RectangleShape rectangle(Vector2f(width, array[i]));
		//задаем положение прямоугольнику х = ширина*индекс, у = высота окна - высота прямоугольника
		rectangle.setPosition(width * i, WINDOW_HEIGHT - array[i]);
		rectangle.setFillColor(Color(255, 69, 0));
		window.draw(rectangle);
	}
	
}

void drawSortName(RenderWindow& window, string name)
{
	Font font;
	font.loadFromFile("20016.TTF");
	Text text("", font, 30);
	text.setFillColor(Color::White);
	text.setString(name);

	text.setPosition(10, 10);

	window.draw(text);
}

void draw(RenderWindow& window, string name, int* nums, int n )
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	window.clear();

	drawSortName(window, name);
	drawArray(window, nums, n);
	window.display();
}

void bubble_sort(RenderWindow& window, int* nums, int mas_size) {
	for (int i = 0; i < mas_size; i++) {
		for (int j = 0; j < mas_size - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int a = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = a;
				draw(window, "Bubble sort", nums, mas_size);
			}
		}
	}
}

void selectionSort(RenderWindow& window, int* numbers, int n)
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
		draw(window, "Selection sort", numbers, n);
	}
}

void insertionSort(RenderWindow& window, int* array, int length) {

	for (int i = 1; i < length; i++) {

		int current = array[i];

		int prevIndex = i - 1;

		while (prevIndex >= 0 && current < array[prevIndex]) {

			array[prevIndex + 1] = array[prevIndex];

			array[prevIndex] = current;

			prevIndex--;

			draw(window, "Insertion sort", array, length);

		}

	}

}

void shellSort(RenderWindow& window, int* num, int size)

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
				draw(window, "Shell sort", num, size);
			}
			num[j] = current; // на выявленное место помещаем сохраненный элемент 
		}

	}

}

int main()
{
	const int size = WINDOW_WIDTH / 5;
	int sortArray[size];
	srand(time(0));
	for (int i = 0; i < size; i++) {
		sortArray[i] = rand() % WINDOW_HEIGHT;
		cout << setw(3) << sortArray[i] << " ";

	}

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorts!");


	while (window.isOpen())
	{
		//bubble_sort(window, sortArray, size);
		//selectionSort(window, sortArray, size);
		//insertionSort(window, sortArray, size);
		shellSort(window, sortArray, size);
	}
	return 0;
}
