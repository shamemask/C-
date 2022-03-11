#pragma once// защита от повторного подключения

#include <SFML/Graphics.hpp> // подключение sfml

using namespace sf; // чтобы не писать sf::

class Mage { // создаем класс мага  
private:// делаем метод init и его поля приватными 

	Vector2f position; // позиция мага

	Vector2f speed; // скорость мага

	Sprite sprite; // спрайт мага

	Texture texture; // текстура мага

	void init(); // задаются начальные параметры мага 

	int width = 32;

	int height = 48;

	void dontMoveBehindMap();// маг не сможет проходить за карту 
public:
	float currentFrame = 0;
	Mage(); // конструктор
	void update();
	void setPosition(Vector2f pos); // задать позицию
	void setTextureRect(IntRect rect); // задать спрайт
	void setSpeed(Vector2f speed); // задать скорость
	void setWidth(int width);// задаёт ширину персонажа
	void setHeight(int height);// задаёт высоту героя
	Vector2f getPosition(); // получить позицию
	Sprite getSprite();// получить спрайт
	Vector2f getSpeed();// получить скорость
	int getWidth();//позволяет получить ширину персонажа
	int getHeight();//позволяет получить высоту главного героя
};