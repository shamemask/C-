#pragma once

#include <SFML/Graphics.hpp>

#include<iostream>// подключаем библиотеку

#include "Map.h" 

#include "KeyPressedAction.h"

#include "Camera.h" 

using namespace sf;// чтобы не писать sf::

using namespace std; //чтобы не писать std::

class Engine {

	// наш класс игрового движка, заменяет main public:

	// чтобы использовать везде

public:

	RenderWindow window;// объект игрового окна

	Map map;

	KeyPressedAction pressedAction;

	Camera* camera;// создание указателя на объект камеры 

	Engine();// конструктор класса 

	void init();// для загрузки игровых компонентов

	void loop();// игровой цикл(по сути while (true) в main.

	void draw();

	void update();// обновление

};
