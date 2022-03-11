#include "Stone.h"// подключение заголовочного файла камня 

// 7. подключить файл карты, чтобы была возможность проверять, что камнь долетел до нижнего края окна
//#include "Map.h"


Stone::Stone(Vector2f position) {//конструктор класса 

	init();// метод задающий начальные параметры 

	setPosition(position);//метод задающий позицию 

// 5. добавить установку скорости в конструктор
	//setSpeedY(0.1);

}

void Stone::init() {// начальные параметры камня

	Image image;//создаем объект изображения камня

	image.loadFromFile("images/stone.png");//загружаем изображение камня

	texture.loadFromImage(image);//загружаем текстуру камня из изображения

	sprite.setTexture(texture);//задаём спрайту текстуру

//13. картинка большая, нужно уменьшить масштаб
	//sprite.setScale(0.05, 0.05);//уменьшаем камень

}

void Stone::setPosition(Vector2f position) {//задать позицию свитка 

	this->position = position;// задаём позицию свитка

	sprite.setPosition(position.x, position.y);//задать позицию спрайту

}

// 4. нужно реализовать сеттер скорости падения
/*void Stone::setSpeedY(float speedY) {//задать скорость падения камня

	this->speedY = speedY;
}*/

void Stone::setTextureRect(IntRect rect) {//задать текстуру 

	sprite.setTextureRect(rect); //задаём спрайту текстуру

}


Sprite Stone::getSprite() { //получить спрайт свитка 

	return sprite;// получаем спрайт свитка

}

//6. реализовать метод обновления
/*void Stone::update() {
	sprite.move( 0 , speedY );
	position = sprite.getPosition();
	if (position.y > WINDOW_HEIGHT)
	{
		position.y = 0;
		setPosition(Vector2f(position.x, position.y));
	}
}*/