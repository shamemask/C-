#pragma once
#include <SFML/Graphics.hpp>
#include "Mage.h" 
const int LEFT_BORDER = 400;// граница камеры слева 
const int RIGHT_BORDER = 860;// граница камеры справа 
const int UP_BORDER = 250;// граница камеры сверху 
const int DOWN_BORDER = 470;//граница камеры снизу 

class Camera {// класс игровой камеры 
private:

	View view;//объект View из sfml для работы с камерой 

	Mage* mage;// создание указателя на мага 

	void setCenter();// концентрация внимания камеры на игроке 

	void init();//начальные настройки камеры 

public:
	Camera(Mage* mage);//конструктор камеры, принимающий указатель на объект мага 

	void update();// обновление камеры

	View getView();// получить объект класса View из sfml. 
};