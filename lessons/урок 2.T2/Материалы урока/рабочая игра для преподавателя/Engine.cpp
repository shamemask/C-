#include "Engine.h"// подключаем заголовочный файл


Engine::Engine() {// определяем конcтруктор

	init();

}

void Engine::draw() {

	window.clear(Color(0, 255, 0));// зелёный фон

	window.setView(camera->getView());//задаём игровому окну камеру

	map.draw(window);

	window.display(); // отображаем на окне

}

void Engine::update() {

	// маг не регирует на клавиши, нет вызова pressedAction.action();

	pressedAction.action();

	map.update();// обновляем карту

	camera->update();// обновляем камеру 

}


void Engine::init() {//функция загрузки компонентов игры

	window.create(sf::VideoMode(1260, 720), "Game");
	pressedAction.setPlayer(map.getPlayer());
	camera = new Camera(map.getPlayer());// создаём игровую камеру
}

void Engine::loop() {// функция игрового цикла

	while (window.isOpen())// игровой цикл

	{

		Event event;// события которые происходят в игре

		while (window.pollEvent(event))// проверяем события

		{

			if (event.type == Event::Closed) {

				window.close();// закрыть окно

			}

		}
		draw(); // рисуем
		update();// обновляем игру
	}

}
