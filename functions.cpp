#include "headfile.h"

void Color::printData()
{
	cout << colorID << ". " << name << "." << endl;
}
int ask()
{
	int user_answer;

	cout << "Укажите номер цвета, который вам нравится: " << endl;
	cin >> user_answer;
	while(0 > user_answer || user_answer > 6) //Цикл ожидания правильного ответа
	{
		cout << "Такого цвета нет!\nПопробуйте ещё: " << endl;
		cin >> user_answer;
	}
	return user_answer;
}
void answer(const char *color)
{
	cout << "Вы " << color << " слоник!" << endl;
}
int localColor()
{
	cout << endl << "Проверка работы деструктора" << endl << "Новый цвет: " << endl;
	/*Создание локальных объектов*/
	Color pink("розовый");
	Color white("белый");
	return pink.getID(); //Возврат порядкого номера локального объекта
}
