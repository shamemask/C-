#pragma once
#include <SFML/Audio.hpp>
#include "map.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Player

{
private:

	float x, y; //координаты игрока х и у
public:
	String file_name; //имя файла 
	Image image;//объект изображения 
	Texture texture;//объект текстуры
	Sprite sprite;//объект спрайта 
	float width, height;//ширина, высота 
	int direction; //направление движения игрока
	float speed;//скорость
	float dx, dy;//ускорение (по х и по у)
	int playerScore; //счет 
	Player(String F, float X, float Y, float W, float H)

	{

		file_name = F;

		x = X;
		y = Y;

		width = W;
		height = H;

		dx = 0; dy = 0;

		speed = 0;
		direction = 0;
		playerScore = 0;

		image.loadFromFile(file_name);//загрузили файл в изображение 
		//image.createMaskFromColor(Color(158, 129, 117));
		texture.loadFromImage(image);//загружаем изображение в текстуру 

		sprite.setTexture(texture);//устанавливаем текстуру спрайту 

		sprite.setTextureRect(IntRect(0, 0, width, height)); //вырезаем первый костюм 

		sprite.setPosition(x, y);

	}
	void update(float time)

	{

		switch (direction)

		{

		case 0:

			dx = speed;

			dy = 0;

			break;


		case 1:

			dx = -speed;

			dy = 0;

			break;
		case 2:

			dx = 0;

			dy = speed;

			break;
		case 3:

			dx = 0;

			dy = -speed;

			break;
		}
		x += dx * time;

		y += dy * time;
		speed = 0;
		interactionWithMap();
		sprite.setPosition(x, y);
	}
	float getPlayerX()

	{

		return x;

	}

	float getPlayerY()

	{

		return y;

	}
	void interactionWithMap()

	{
		for (int i = y / HEIGHT_MAP_TILE; i < (y + height) / HEIGHT_MAP_TILE; i++)

			for (int j = x / WIDTH_MAP_TILE; j < (x + width) / WIDTH_MAP_TILE; j++)

			{
				if (TileMap[i][j] == 's')

				{
					if (dy > 0)
						y = i * HEIGHT_MAP_TILE - height;
					if (dy < 0)

						y = i * HEIGHT_MAP_TILE + height;
					if (dx > 0)

						x = j * WIDTH_MAP_TILE - width;
					if (dx < 0)

						x = j * WIDTH_MAP_TILE + width;
					

				}

				if (TileMap[i][j] == 'h')

				{

					TileMap[i][j] = 'g';
					int randomX = 1 + rand() % (WIDTH_MAP - 2);

					int randomY = 1 + rand() % (HEIGHT_MAP - 2);

					TileMap[randomY][randomX] = 'h';

					playerScore++;

				}

				if (TileMap[i][j] == 'l')

				{

				}

			}
	}
};