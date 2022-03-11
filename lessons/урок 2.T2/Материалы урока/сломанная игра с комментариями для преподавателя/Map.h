#pragma once

#include <SFML/Graphics.hpp>

#include "Mage.h"

#include "Scroll.h"//подключаем заголовочный файл свитка 

//9. подключить заголовочный файл камня
//#include "Stone.h"

using namespace sf;

const int WINDOW_WIDTH = 1260;

const int WINDOW_HEIGHT = 720;

const int WIDTH_MAP = 21;//размер карты ширина

const int HEIGHT_MAP = 12;//размер карты высота 

class Map {
public:

	Map();

	void draw(RenderWindow& window);

	Mage* getPlayer();

	void update();

private:
	sf::String TileMap[HEIGHT_MAP] = {

		"wwwwwwwwwwwwwwwwwwwww",

		"wffffffbffffffffsfffw",

		"wfsffffsfffffffbffffw",

		"wffffbfffffffsffffffw",

		"wfsfffffffbfffffffffw",

		"wfffbfffffffffffffffw",

		"wffffffffffffffsffffw",

		"wfffffffffffffffffffw",

		"wffsfffsffffffffffffw",

		"wffffffffbffffffbfffw",

		"wfffbsfffffffsffffffw",

		"wwwwwwwwwwwwwwwwwwwww",

	};

	Mage* mage;// указатель на объект мага 

	Scroll* scroll;// указатель на объект свитка 

//8. добавить массив указателей на карту
	//Stone* stone[10];// массив указателей на объект камня 

	Image mapImage;

	Texture mapTexture;

	Sprite mapSprite;

	void init();
};