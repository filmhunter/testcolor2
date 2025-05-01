#include "headfile.h"

void ConcreteColor::printData()
{
	std::cout << colorID << ". " << colorName << "." << std::endl;
}
int ask()
{
	int user_answer;

	std::cout << "Укажите номер цвета, который вам нравится: " << std::endl;
	std::cin >> user_answer;
	while(0 > user_answer || user_answer > 6) //Цикл ожидания правильного ответа
	{
		std::cout << "Такого цвета нет!\nПопробуйте ещё: " << std::endl;
		std::cin >> user_answer;
	}
	return user_answer;
}
void answer(std::string color)
{
	std::cout << "Вы " << color << " слоник!" << std::endl;
}
int localColor()
{
	std::cout << std::endl << "Проверка работы деструктора" << std::endl << "Новый цвет: " << std::endl;
	/*Создание локальных объектов*/
	ConcreteColor pink("розовый");
	ConcreteColor white("белый");
	return pink.getID(); //Возврат порядкого номера локального объекта
}
