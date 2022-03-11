#include "Scroll.h"// подключение заголовочного файла свитка 

Scroll::Scroll(Vector2f position) {//конструктор класса 

	init();// метод задающий начальные параметры 

	setPosition(position);//метод задающий позицию 

}

void Scroll::init() {// начальные параметры свитка. 

	Image image;//создаем объект изображения свитка

	image.loadFromFile("images/scroll.png");//загружаем изображение свитка

	texture.loadFromImage(image);//загружаем текстуру свитка из изображения

	sprite.setTexture(texture);//задаём спрайту текстуру

}

void Scroll::setPosition(Vector2f position) {//задать позицию свитка 

	this->position = position;// задаём позицию свитка

	sprite.setPosition(position.x, position.y);//задать позицию спрайту

}

void Scroll::setTextureRect(IntRect rect) {//задать текстуру 

	sprite.setTextureRect(rect); //задаём спрайту текстуру

}

void Scroll::setWidth(int width) {//задать ширину 

	this->width = width;//задаём ширину свитка

}

void Scroll::setHeight(int height) {// задать высоту свитка 

	this->height = height;// задаём высоту свитка

}

int Scroll::getWidth() {// получить ширину свитка 

	return width;//получаем ширину свитка 

}


int Scroll::getHeight() {//получить высоту свитка 

	return height;// получаем высоту свитка 

}

Sprite Scroll::getSprite() { //получить спрайт свитка 

	return sprite;// получаем спрайт свитка

}