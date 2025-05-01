// вариант 13

#include "headfile.h"

/*Инициализация статических полей класса Color*/
int Color::colorID_gen = 0; //Счётчик объектов класса
Color **Color::ptr_c = (Color**)malloc(sizeof(Color*)); //Указатель на динамический массив указателей объектов класса

int main()
{
	cout << "Мы пронумеровали цвета:" << endl;
	/*Создание объектов класса Color*/
	Color red("красный");
	Color orange("оранжевый");
	Color yellow("жёлтый");
	Color green("зелёный");
	Color blue("голубой");
	Color darkblue("синий");
	Color purple("фиолетовый");
	
	answer(Color::getPtr(ask())->getName());
	
	/* Функция ask() возвращает введённое в консоль число типа int
	 * 
	 * Метод Color::getPtr(int i) возвращает указатель на объект с порядковым номером i из динамического массива
	 * 
	 * Метод getName() возвращает указатель на строку (название цвета) 
	 * 
	 * Функция answer(const char *color) выводит ответ в консоль
	 */
	
	/*//Проверка работы деструктора
	int pinkID = localColor(); //Создание объектов в локальной обсласти (порядковый номер одного из них возвращается)
	//Color black("чёрный"); 
	if (Color::getPtr(pinkID) != NULL) cout << Color::getPtr(pinkID)->getName() << endl; //Если раскомментировать предыдущую строку, в консоль выведет "чёрный"
	else cout << "Такого цвета больше нет" << endl;*/
	
	return 0;
}
	
