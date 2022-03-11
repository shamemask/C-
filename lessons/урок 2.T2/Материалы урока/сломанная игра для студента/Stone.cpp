#include "Stone.h"// подключение заголовочного файла камня 

Stone::Stone(Vector2f position) {//конструктор класса 

	init();// метод задающий начальные параметры 

	setPosition(position);//метод задающий позицию 

}

void Stone::init() {// начальные параметры камня

	Image image;//создаем объект изображения камня

	image.loadFromFile("images/stone.png");//загружаем изображение камня

	texture.loadFromImage(image);//загружаем текстуру камня из изображения

	sprite.setTexture(texture);//задаём спрайту текстуру

}

void Stone::setPosition(Vector2f position) {//задать позицию свитка 

	this->position = position;// задаём позицию свитка

	sprite.setPosition(position.x, position.y);//задать позицию спрайту

}

void Stone::setTextureRect(IntRect rect) {//задать текстуру 

	sprite.setTextureRect(rect); //задаём спрайту текстуру

}


Sprite Stone::getSprite() { //получить спрайт свитка 

	return sprite;// получаем спрайт свитка

}