#pragma once

#include <SFML/Graphics.hpp>//подключение sfml 

using namespace sf;//использование пространства имён sf 

class Stone {//класс камня 

private://приватный блок 

	Vector2f position;//позиция камня
//1. добавить скорость падения камня
	float speedY; //скорость падения камня 

	Sprite sprite;//спрайт камня

	Texture texture;//текстура камня

	void init();//начальные значения камня 

// 11. указать модификатор public, чтобы сделать методы доступными
public://публичный блок 
	Stone(Vector2f position);//конструктор класса 

// 3. объявить метод обновления камня
	void update();

	void setPosition(Vector2f position);// задать позицию камня
//2. добавить сеттер скорости
	void setSpeedY(float speed);// задать скорость падения

	void setTextureRect(IntRect rect);//задать текстуру камня

	Sprite getSprite();// получить спрайт камня

};