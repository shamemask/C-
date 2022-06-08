#include <string>

#include <iostream>

using namespace std;

int main()

{

	system("chcp 1251>nul");

	int numbers[5] = {1, 6, 7, 3, 2};

	int n = 5; 

	int counter = 0;

	for(int i = 0; i < n; i++) {

		//Исходно считаем наименьшим первый элемент

		int min_i = i;

		//Этот цикл перебирает несортированные элементы

		for(int j = i + 1; j < n; j++)

		{

			counter++;

			if (numbers[j] < numbers[min_i])

			min_i = j;

		}

	int buf = numbers[i];

	numbers[i] = numbers[min_i];

	numbers[min_i] = buf;

	for(int i = 0; i < n; i++)

	cout<< numbers[i]<<"; ";

	cout << endl;

	}

cout<<"Массив отсортирован за "<< counter << " шагов.\n"; 

return 0;

} 
//сортировка слов в алфавитном порядке
/*
	int main()

	{	
		int n = 8;

		system("chcp 1251>nul");

		string list[8] = { "Пушкин", "Лермонтов", "Гоголь", "Чехов", "Лесков", "Некрасов", "Тургенев", "Грибоедов" };


		string alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзйиклмнопрстуфхцчшщъыьэюя";

		cout << alphabet.find("А") << "\n";
		cout << alphabet.find("з") << "\n";
		cout << alphabet.find("я") << "\n";


		for (int i = 0; i < n; i++)

		{

			//Исходно считаем наименьшим первый элемент

			int min_i = i;

			//Этот цикл перебирает несортированные элементы

			for (int j = i + 1; j < n; j++)

			{

				int len = list[j].length() < list[min_i].length() ? list[j].length() : list[min_i].length();

				for (int l = 0; l < len; l++)

				{

					if (alphabet.find(list[j][l]) < alphabet.find(list[min_i][l]))

					{

						min_i = j;

						break;

					}

					if (alphabet.find(list[j][l]) > alphabet.find(list[min_i][l]))

					{

						break;

					}

				}

			}

			string buf = list[i];

			list[i] = list[min_i];

			list[min_i] = buf;

			cout << list[i] << "; ";

		}

		return 0;

	}

*/