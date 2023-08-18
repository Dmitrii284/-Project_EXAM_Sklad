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
	setlocale(LC_ALL, "Rus");
	int choise{ 0 }, quantity{ 0 }, numShelf{ 0 };
	double weight{ 0 };
	char letterShalf{ 0 };
	std::string nameProduct{ 0 };
	bool isValide = false;


	std::shared_ptr<Tovar> morkov = std::make_shared<Tovar>("Morkov", 160);
	std::shared_ptr<Tovar> morkov1 = std::make_shared<Tovar>("Morkov1", 60);
	std::shared_ptr<Tovar> morkov2 = std::make_shared<Tovar>("Morkov2", 20);
	std::shared_ptr<Tovar> morkov3 = std::make_shared<Tovar>("Morkov3", 260);
	Cell cell(1000, 'A', 10);
	cell.AddTovar(morkov);
	cell.AddTovar(morkov1);
	cell.AddTovar(morkov2);
	cell.AddTovar(morkov3);

	std::cout << "СКЛАД" << std::endl;
	std::cout << "Выберите действие нажав нужную цифру." << std::endl;
	std::cout << "1 - Посмотреть весь товара." << std::endl;
	std::cout << "2 - Добавить товар." << std::endl;
	std::cout << "3 - Удалить товар." << std::endl;
	std::cout << "4 - Поиск товара по имени." << std::endl;
	std::cout << "5 - Поиск товара по по названию." << std::endl;
	std::cout << "6 - Вывод списка товара на выбранном стеллаже." << std::endl;
	std::cout << "7 - ВЫХОД!!!." << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "Введите цифру -> " << std::endl;
	std::cin >> choise;

	switch (choise)
	{
	case 1 :
		cell.ShowTovars();
		break;
	case 2 :
		std::cout << "Введите параметры товара который хотите добавить и стеллаж->" << std::endl;
		std::cout << "Внимание! Стеллаж вмещает до 1000 кг" << std::endl;
		std::cout << "Название  товара->";
		std::cin >> nameProduct;
		std::cout << "Количество  товара->";
		std::cin >> quantity;
		
		std::cout << "Вес товара->";
		std::cin >> weight;
		while (!isValide) {
			if (weight <= 1000) {
				isValide = true;
			}
			else {
				std::cout << "Слишком большой вес товара!!!";
				continue;
			}
		}
		std::cout << "Выберите букву стеллаж для размещения товара->" << std::endl;
		std::cout << "А - букву стеллажа" << std::endl;
		std::cout << "В - букву стеллажа" << std::endl;
		std::cout << "С - букву стеллажа" << std::endl;
		std::cout << "Введите букву стеллажа->" << std::endl;		
		std::cin >> letterShalf;
		if (letterShalf != 'а' || letterShalf != 'А' || letterShalf != 'в' || letterShalf != 'В' || letterShalf != 'с' || letterShalf != 'С') {
			std::cout << "Неверно указали букву стеллажа!!!";
			return false;
		}else
		std::cout << "Выберите номер стеллажа->" << std::endl;
		std::cout << "10 - номер стеллажа" << std::endl;
		std::cout << "20 - номер стеллажа" << std::endl;
		std::cout << "30 - номер стеллажа" << std::endl;
		std::cin >> numShelf;
		if (numShelf != 10 || numShelf != 20 || numShelf != 30) {
			std::cout << "Неверно указали номер стеллажа!!!";
			return false;
		}else
	
		break;
	case 3 :
		break;
	case 4 :
		break;		
	case 5 :
		break;
	case 6 :
		break;
	case 7 :
		break;

	default:
		std::cout << "Вы введи не верную цифру!!!" << std::endl;
		break;
	}
	
	
	
	//cell.ShowTovars();
	//cell.ShipTovar("Morkov1"); // Удаляем по имени товар. 
	//cell.ShipTovar(morkov2->GetId()); //Удаляем по ID товар со склада

	/*auto x = (uint16_t)(200 << 8 | 100);

	std::cout << x;
	*/

	/*
	#include <iostream>

int main() {
    int number;
    bool isValid = false;

    while (!isValid) {
        std::cout << "Введите номер: ";
        std::cin >> number;

        if (number == 1 || number == 2 || number == 3 || number == 4 || number == 5) {
            isValid = true;
        } else {
            std::cout << "Неверный номер, повторите ввод: ";
            continue;
        }
    }

    std::cout << "Вы ввели правильный номер: " << number << std::endl;

    return 0;
}
	*/

	return 0;
}
