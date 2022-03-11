#include "KeyPressedAction.h"

KeyPressedAction::KeyPressedAction() {

}

void KeyPressedAction::setPlayer(Mage* mage) {

	//передаём указатель на мага

	this->mage = mage; //задаём поле класса KeyPressedAction

}

void KeyPressedAction::action() {

	if (Keyboard::isKeyPressed(Keyboard::Right)){ 
		//если стрелка вправо нажата 

		mage->setSpeed(Vector2f(0.1, 0));//зададим скорость мага направо

	mage->setTextureRect(IntRect(int(mage->currentFrame) * mage->getWidth(), 2 * mage->getHeight(), mage->getWidth(), mage->getHeight()));

	// зададим игроку текстуру из третьей строки, чтобы увидеть что он повернулся направо 

	}
	else if (Keyboard::isKeyPressed(Keyboard::Left)) { 
		//если стрелка влево нажата

		mage->setSpeed(Vector2f(-0.1, 0));//зададим скорость мага налево

		mage->setTextureRect(IntRect(int(mage->currentFrame) * mage->getWidth(), 1 * mage->getHeight(), mage->getWidth(), mage->getHeight()));

		// зададим игроку текстуру из второй строки, чтобы увидеть что он повернулся налево

	}
	else if (Keyboard::isKeyPressed(Keyboard::Up)) {

		//если стрелка вверх нажата

		mage->setSpeed(Vector2f(0, -0.1));

		mage->setTextureRect(IntRect(int(mage->currentFrame) * mage->getWidth(), 3 * mage->getHeight(), mage->getWidth(), mage->getHeight()));

		// зададим игроку текстуру из первой строки, чтобы увидеть что он повернулся наверх

	}

	else if (Keyboard::isKeyPressed(Keyboard::Down)) {

		//если стрелка вниз нажата

		mage->setSpeed(Vector2f(0, 0.1));

		//зададим скорость мага вниз

		mage->setTextureRect(IntRect(int(mage->currentFrame) * mage->getWidth(), 0 * mage->getHeight(), mage->getWidth(), mage->getHeight()));

		// зададим игроку текстуру из нулевой строки, чтобы увидеть что он повернулся вниз

	}

	else {

		mage->setSpeed(Vector2f(0, 0));//обнуляем скорость мага

	}

	mage->currentFrame = mage->currentFrame + 0.005;

	if (mage->currentFrame > 4) {// если currentFrame больше двух то обнулим его

		mage->currentFrame = 0;//обнуляем currentFrame

	}
}