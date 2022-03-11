#pragma once// защита от повторного подключения 

#include <SFML/Graphics.hpp>//подключение sfml 

using namespace sf;//использование пространства имён sf 

class Scroll {//класс свитка 
private://приватный блок 

	Vector2f position;//позиция свитка 
	Sprite sprite;//спрайт свитка
	Texture texture;//текстура свитка

	void init();//начальные значения свитка 

	int width = 25;//ширина свитка 
	int height = 25;//высота свитка
public://публичный блок 

	Scroll(Vector2f position);//конструктор класса 

	void setPosition(Vector2f position);// задать позицию свитка
	void setTextureRect(IntRect rect);//задать текстуру свитка 
	void setWidth(int width);// задать ширину свитка 
	void setHeight(int height);// задать высоту свитка

	Sprite getSprite();// получить спрайт свитка
	int getWidth();// получить ширину свитка
	int getHeight();// получить высотку свитка
};