#ifndef COLORSHEAD
#define COLORSHEAD
#include <iostream>

using namespace std;

class Color
{
	/*Объявление полей класса*/
	static int colorID_gen; //Счётчик объектов класса
	static Color **ptr_c; //Указатель на динамический массив указателей объектов класса
	int colorID; //Номер объекта
	const char *name; //Указатель на строку (название цвета)
public:
	/*Конструктор класса*/
	Color(const char *n)
	{
		colorID = colorID_gen++; //Присвоение номера объекту + инкрементация счетчика объектов
		name = n; //Указатель на строку (название цвета)
		ptr_c[colorID] = this; //Сохранение указателя на объект в динамическом массиве
		ptr_c = (Color**)realloc(ptr_c, sizeof(Color*) * (colorID_gen + 1)); //Расширение динамического массива
		printData(); //Вывод порядкового номера и введённой строки (названия цвета)
	}
	/*Деструктор класса*/
	~Color()
	{
		colorID_gen--; //Уменьшение счетчика объектов класса на 1
		/*Переопределение указателей объектов в динамическом массиве*/
		for (int i = colorID; i < colorID_gen; i++)
		{
			ptr_c[i] = ptr_c[i + 1];
			ptr_c[i]->colorID = i;
		}
		ptr_c[colorID_gen] = nullptr;
		ptr_c = (Color**)realloc(ptr_c, sizeof(Color*) * (colorID_gen + 1)); //Уменьшение размера динамического массива
	}
	/*Методы класса*/	
	void printData();
	static Color *getPtr(int i){return ptr_c[i];}
	int getID()const{return colorID;}
	const char *getName(){return name;}
};
/*Объявление функций*/
int ask();
void answer(const char *color);
int localColor(); //проверка работы деструктора
#endif
