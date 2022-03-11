#include "Camera.h" 
void Camera::init() {

	view.reset(sf::FloatRect(0, 0, 800, 500));//начальные настройки 
} 

Camera::Camera(Mage* mage) {

	this->mage = mage;//задаём мага

	init();//задаём начальные настройки камеры 

}

void Camera::setCenter() {
	int playerX = mage->getPosition().x;//получим координату мага по оси x.

	int playerY = mage->getPosition().y;//получим координату мага по оси y 

	if (playerX < LEFT_BORDER) {// настраиваем границу слева 

		playerX = LEFT_BORDER;

	}
	if (playerX > RIGHT_BORDER) {// настраиваем границу справа 

		playerX = RIGHT_BORDER;

	}

	if (playerY < UP_BORDER) {// настраиваем границу сверху

		playerY = UP_BORDER;

	}

	if (playerY > DOWN_BORDER) {// настраиваем границу снизу

		playerY = DOWN_BORDER;

	}

	view.setCenter(playerX, playerY);// задаём координату центра камеры
}

void Camera::update() {
	setCenter();
}
View Camera::getView() {
	return view;
}