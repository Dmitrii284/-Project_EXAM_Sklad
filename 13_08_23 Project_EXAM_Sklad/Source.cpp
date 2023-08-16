/*******************************************************************
 5. Создание программы сопровождения товаров на складе.
1) Вводом данных занимается кладовщик.
2) Данные о товаре должны включать в себя :
▪ Уникальный номер предмета(генерируется автоматически)
▪ Название товара
▪ Местоположение товара
▪ время прибытия на склад(генерируется автоматически).
3) Реализовать поиск товара по названию или номеру.
4) Реализовать вывод списка товаров хранящихся на одном месте
склада(стеллаже, полке)
 * \author Дмитрий
 * \date   August 2023
 *********************************************************************/
#include <ctime>
#include <chrono>
#include <iostream>
#include "Cell.h"

int main()
{
	//std::shared_ptr<Tovar> morkov = std::make_shared<Tovar>("Morkov", 160);
	//std::shared_ptr<Tovar> morkov1 = std::make_shared<Tovar>("Morkov1", 60);
	//std::shared_ptr<Tovar> morkov2 = std::make_shared<Tovar>("Morkov2", 20);
	//std::shared_ptr<Tovar> morkov3 = std::make_shared<Tovar>("Morkov3", 260);
	//Cell cell(1000, 'A', 10);
	//cell.AddTovar(morkov);
	//cell.AddTovar(morkov1);
	//cell.AddTovar(morkov2);
	//cell.AddTovar(morkov3);
	//cell.ShowTovars();
	//cell.ShipTovar("Morkov1"); // Удаляем по имени товар. 
	//cell.ShipTovar(morkov2->GetId()); //Удаляем по ID товар со склада

	auto x = (uint16_t)(200 << 8 | 100);

	std::cout << x;
	

	return 0;
}
