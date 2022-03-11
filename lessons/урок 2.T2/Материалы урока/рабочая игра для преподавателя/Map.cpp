#include "Map.h"

void Map::init() {

	mapImage.loadFromFile("images/textures.png");//картинка карты 

	mapTexture.loadFromImage(mapImage);//загружаем текстуру 

	mapSprite.setTexture(mapTexture);//загружаем спрайт

	mage = new Mage();

	scroll = new Scroll(Vector2f(100, 100));//создаём указатель на объект свитка

//10. в цикле заполнить массив камнями, расположив их равномерно по карте
	for (int i = 0; i < 10; i++)
	{
		float x = i * (WINDOW_WIDTH - 60 )/10 + 60;//вычитаем 60, чтобы камни не попадали на стену
		float y = 0;
		stone[i] = new Stone(Vector2f(x, y));
	}

}

Map::Map() {

	init();
}

void Map::update() {

	mage->update();
//14. обновлять каждый камень из массива
	for (int i = 0; i < 10; i++)
	{
		stone[i]->update();
	}
}

Mage* Map::getPlayer() {

	return mage;

}

void Map::draw(RenderWindow& window) {

	for (int i = 0; i < HEIGHT_MAP; i++) {

		for (int j = 0; j < WIDTH_MAP; j++) {

			if (TileMap[i][j] == 'w') {

				mapSprite.setTextureRect(IntRect(0, 0, 60, 60));

			}

			if (TileMap[i][j] == 'f') {

				mapSprite.setTextureRect(IntRect(60 * 1, 0 , 60, 60));

			}

			if (TileMap[i][j] == 's') {

				mapSprite.setTextureRect(IntRect(60 * 2, 0, 60, 60));

			}

			if (TileMap[i][j] == 'b') {

				mapSprite.setTextureRect(IntRect(60 * 3, 0, 60, 60));

			}

			mapSprite.setPosition(j * 60, i * 60);

			window.draw(mapSprite);

		}

	}
	window.draw(scroll->getSprite());//отрисовка свитка

	window.draw(mage->getSprite());// отрисовка мага

// 12. отрисовывать каждый камень из массива
	for (int i = 0; i < 10; i++)//отрисовка камней
	{
		window.draw(stone[i]->getSprite());
	}
}