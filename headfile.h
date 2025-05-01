#ifndef COLORSHEAD
#define COLORSHEAD
#include <iostream>

class ConcreteColor;

class Color
{
protected:
	/*Объявление полей класса*/
	static int colorID_gen; //Счётчик объектов класса
	static ConcreteColor **ptr_c; //Указатель на динамический массив указателей объектов класса
public:
	/*Конструктор класса*/
	Color() { colorID_gen++; } //Инкрементация счетчика объектов
	/*Деструктор класса*/
	~Color() { colorID_gen--; } //Декрементация счетчика объектов
	/*Геттер*/
	static ConcreteColor *getPtr(int i){return ptr_c[i];} 
};

class ConcreteColor: public Color
{
	int colorID; //Номер объекта
	std::string colorName; //Название цвета
public:
	/*Конструктор класса*/
	ConcreteColor(std::string name)
	{
		colorID = colorID_gen - 1; //Присвоение номера объекту
		colorName = name; //Присвоение названия цвета
		ptr_c[colorID] = this; //Сохранение указателя на объект в динамическом массиве
		ptr_c = (ConcreteColor**)realloc(ptr_c, sizeof(ConcreteColor*) * (colorID_gen + 1)); //Расширение динамического массива
		printData(); //Вывод порядкового номера и названия цвета
	}
	/*Деструктор класса*/
	~ConcreteColor()
	{
		/*Переопределение указателей объектов в динамическом массиве*/
		for (int i = colorID; i < colorID_gen - 1; i++)
		{
			ptr_c[i] = ptr_c[i + 1];
			ptr_c[i]->colorID = i;
		}
		ptr_c[colorID_gen - 1] = nullptr;
		ptr_c = (ConcreteColor**)realloc(ptr_c, sizeof(ConcreteColor*) * (colorID_gen)); //Уменьшение размера динамического массива
	}
	/*Методы класса*/	
	void printData();
	int getID()const{return colorID;}
	std::string& getName(){return colorName;}
};
/*Объявление функций*/
int ask();
void answer(std::string color);
int localColor(); //проверка работы деструктора
#endif
