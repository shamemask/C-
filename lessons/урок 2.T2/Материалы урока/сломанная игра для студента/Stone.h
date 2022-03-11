#pragma once

#include <SFML/Graphics.hpp>//подключение sfml 

using namespace sf;//использование пространства имён sf 

class Stone {//класс камня 

private://приватный блок 

	Vector2f position;//позиция камня 

	Sprite sprite;//спрайт камня

	Texture texture;//текстура камня

	void init();//начальные значения камня 

	Stone(Vector2f position);//конструктор класса 

	void setPosition(Vector2f position);// задать позицию камня

	void setTextureRect(IntRect rect);//задать текстуру камня

	Sprite getSprite();// получить спрайт камня

};