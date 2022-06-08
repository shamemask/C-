#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
sf::View view;
void getPlayerCoordinateForView(float x, float y)

{
	if (x < 200)

		x = 200;//лева€ сторона

	if (x > 425)

		x = 425;//права€ сторона
	if (y < 150)

		y = 150;//верхн€€ сторона

	if (y > 350)

		y = 350;//нижн€€ сторона
	view.setCenter(x + 10, y + 10);

}
// функци€ перемещени€ камеры

void view_map(float time)

{

	if (Keyboard::isKeyPressed(Keyboard::D))

		view.move(0.1*time, 0);
	if (Keyboard::isKeyPressed(Keyboard::S))

		view.move(0, 0.1*time);
	if (Keyboard::isKeyPressed(Keyboard::A))

		view.move(-0.1*time, 0);
	if (Keyboard::isKeyPressed(Keyboard::W))

		view.move(0, -0.1*time);
	if (Keyboard::isKeyPressed(Keyboard::R))

		view.setRotation(90);
	if (Keyboard::isKeyPressed(Keyboard::U))

		view.zoom(1.0001f);
	if (Keyboard::isKeyPressed(Keyboard::Y))

		view.zoom(0.9999f);
	if (Keyboard::isKeyPressed(Keyboard::I))

		view.setSize(640, 480);
	if (Keyboard::isKeyPressed(Keyboard::Q))

		view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));
}