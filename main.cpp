// вариант 13

#include "headfile.h"

/*Инициализация статических полей класса Color*/
int Color::colorID_gen = 0; //Счётчик объектов класса
ConcreteColor **Color::ptr_c = new(ConcreteColor*); //Указатель на динамический массив указателей объектов класса

int main()
{
	std::cout << "Мы пронумеровали цвета:" << std::endl;
	/*Создание объектов класса Color*/
	ConcreteColor* red = new ConcreteColor("красный");
	ConcreteColor* orange = new ConcreteColor("оранжевый");
	ConcreteColor* yellow = new ConcreteColor("жёлтый");
	ConcreteColor* green = new ConcreteColor("зелёный");
	ConcreteColor* blue = new ConcreteColor("голубой");
	ConcreteColor* darkblue = new ConcreteColor("синий");
	ConcreteColor* purple = new ConcreteColor("фиолетовый");
	
	answer(ConcreteColor::getPtr(ask())->getName());
	
	/* Функция ask() возвращает введённое в консоль число типа int
	 * 
	 * Метод ConcreteColor::getPtr(int i) возвращает указатель на объект с порядковым номером i из динамического массива
	 * 
	 * Метод getName() возвращает название цвета
	 * 
	 * Функция answer(std::string color) выводит ответ в консоль
	 */
	
	//Проверка работы деструктора
	/*int pinkID = localColor(); //Создание объектов в локальной обсласти (порядковый номер одного из них возвращается)
	ConcreteColor* black = new ConcreteColor("чёрный");
	if (ConcreteColor::getPtr(pinkID) != NULL) std::cout << ConcreteColor::getPtr(pinkID)->getName() << std::endl;
	else std::cout << "Такого цвета больше нет" << std::endl;*/
	
	return 0;
}
	
