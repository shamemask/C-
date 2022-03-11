#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

#include "Mage.h" 

class KeyPressedAction {

private:

	Mage* mage;//указатель на объект класса Mage 

public:

	KeyPressedAction();
	void setPlayer(Mage* mage);
	void action();//функция отвечающая за движение 
};