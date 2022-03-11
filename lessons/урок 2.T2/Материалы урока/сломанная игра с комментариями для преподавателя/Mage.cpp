#include "Mage.h"

#include "Map.h"


Mage::Mage() {

	init();

}
void Mage::init() {

	sf::Image image;// создаём изображение

	image.loadFromFile("images/mage.png");// загружаем его

	texture.loadFromImage(image);// загружаем текстуру

	sprite.setTexture(texture);// задаём спрайту текстуру  

	setTextureRect(IntRect(0, 0, width, height)); //первый спрайт из набора

	setPosition(Vector2f(300, 300));// задаём игроку позицию

}


void Mage::setPosition(Vector2f pos) {

	position = pos; 
	sprite.setPosition(position.x, position.y);
}

void Mage::setSpeed(Vector2f speed) {

	this->speed = speed;

}

void Mage::setWidth(int width) {

	this->width = width;//задать игроку новую ширину.

}

void Mage::setHeight(int height) {

	this->height = height;

}

void Mage::setTextureRect(IntRect rect) {

	sprite.setTextureRect(rect);
}

Vector2f Mage::getPosition() {

	return sprite.getPosition();

}

Vector2f Mage::getSpeed() {

	return speed;

}

Sprite Mage::getSprite() {

	return sprite;

}

int Mage::getWidth() {

	return width;

}

int Mage::getHeight() {

	return height;

}

void Mage::update() {
	sprite.move(speed.x, speed.y);
	position = sprite.getPosition();
	dontMoveBehindMap();// не давать игроку зайти за пределы карты
}
void Mage::dontMoveBehindMap() {// ограничить движение мага за пределами карты

	if (position.x > WINDOW_WIDTH - width) {// если вышел за пределы справа

		position.x = WINDOW_WIDTH - width;// задать позицию так чтобы не вышел за экран.

		setPosition(Vector2f(position.x, position.y));// фиксируем изменения.

	}
	if (position.x < 0) {// если позиция мага по x меньше 0

		position.x = 0;// задать позицию по x=0

		setPosition(Vector2f(position.x, position.y));//зафиксировать изменения

	}

	if (position.y < 0) {// если позиция по y меньше 0

		position.y = 0;// задать позицию по y = 0

		setPosition(Vector2f(position.x, position.y));// зафиксировать изменения

	}

	if (position.y > WINDOW_HEIGHT - height) {// если вышел за пределы сверху

		position.y = WINDOW_HEIGHT - height;// задать позицию так чтобы остановился и не выходил за границы

		setPosition(Vector2f(position.x, position.y));// зафиксировать изменения

	}
}