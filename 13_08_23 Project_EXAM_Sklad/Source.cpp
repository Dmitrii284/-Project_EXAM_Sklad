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
#include <string>

int main()
{
	setlocale(LC_ALL, "Rus");

	int choise{ 0 };
	int exit{ 8 };
	int id{ 0 };
	std::string nameProduct;
	float quantity;
	char letterShalf;
	int numShelf;	
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
	std::cout << "3 - Отгрузить товар по Имени ." << std::endl;	
	std::cout << "4 - Отгрузить товар по ID ." << std::endl;	
	std::cout << "5 - Поиск товара по имени." << std::endl;
	std::cout << "6 - Поиск товара по по названию." << std::endl;
	std::cout << "7 - Вывод списка товара на выбранном стеллаже." << std::endl;
	std::cout << "8 - ВЫХОД!!!." << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "Введите цифру выбранного действия -> ";
	std::cin >> choise;
	
	switch (choise)
	{
	case 1:
		cell.ShowTovars();
		break;
	case 2:
	{
		std::cout << "Введите название и вес товара товара который хотите добавить" << std::endl;
		std::cout << "Внимание! Стеллаж вмещает до 1000 кг" << std::endl;
		std::cout << "Название  товара->";
		std::cin >> nameProduct;
		std::cout << "Вес товара->";
		std::cin >> quantity;
		while (!isValide) {
			if (quantity <= 1000) {
				isValide = true;
			}
			else {
				std::cout << "Слишком большой вес товара!!!";
				return isValide;
			}
		}
		std::shared_ptr<Tovar>nameProd = std::make_shared<Tovar>(nameProduct, quantity);

		std::cout << "Выберите букву стеллаж для размещения товара" << std::endl;
		std::cout << "А - букву стеллажа" << std::endl;
		std::cout << "В - букву стеллажа" << std::endl;
		std::cout << "С - букву стеллажа" << std::endl;
		std::cout << "Введите букву стеллажа->";
		std::cin >> letterShalf;
		if (letterShalf != 'A' && letterShalf != 'a' && letterShalf != 'B' && letterShalf != 'b' &&
			letterShalf != 'C' && letterShalf != 'c') {
			std::cout << "Неверно указали букву стеллажа!!!";
			return isValide;
		}
		else
			std::cout << "Выберите цифру стеллаж для размещения товара" << std::endl;
		std::cout << "10 - номер стеллажа" << std::endl;
		std::cout << "20 - номер стеллажа" << std::endl;
		std::cout << "30 - номер стеллажа" << std::endl;
		std::cout << "Выберите номер стеллажа->";
		std::cin >> numShelf;
		if (numShelf != 10 && numShelf != 20 && numShelf != 30) {
			std::cout << "Неверно указали номер стеллажа!!!";
			return false;
		}
		Cell cell1(1000, letterShalf, numShelf);
		cell1.AddTovar(nameProd);
		std::cout << "----------------Товар добавлен!!!--------------" << std::endl;
		cell1.ShowTovars();
		std::cin.ignore();
		break;
	}
	case 3:
	{
		std::cout << "--------------------Весь товар на складе----------------" << std::endl;
		cell.ShowTovars();
		std::cout << "Введите точное название товара для его ОТГРУЗКИ ->";
		std::cin >> nameProduct;
		cell.ShipTovar(nameProduct);
		std::cout << "|||||||||||||||||     Товар отгружен   ||||||||||||||||||||||||" << std::endl;
		cell.ShowTovars();
		break;
	}
	case 4:
	{
		std::cout << "--------------------Весь товар на складе----------------" << std::endl;
		cell.ShowTovars();
		std::cout << "Введите точное номер ID товара, для его ОТГРУЗКИ ->";
		std::cin >> id;
		cell.ShipTovar(id);
		std::cout << "|||||||||||||||||     Товар отгружен   ||||||||||||||||||||||||" << std::endl;
		cell.ShowTovars();
		break;
	}
		break;
	case 5:
	{
		std::cout << "--------------------Весь товар на складе----------------" << std::endl;
		cell.ShowTovars();
		std::cout << "Введите точное название товара для его поиска->";
		std::cin >> nameProduct;
		std::shared_ptr<Tovar> searchByName = cell.SearchByName(nameProduct);
		if (searchByName != nullptr) {
			std::cout << "Товар  найден!!" << searchByName->GetName() << std::endl;
		}else {
			std::cout << "Товар не найден" << std::endl;
		}
		break;
	}
	case 6 :
	{
		std::cout << "--------------------Весь товар на складе----------------" << std::endl;
		cell.ShowTovars();
		std::cout << "Введите Номер товара ID ->";
		std::cin >> id;
		std::shared_ptr<Tovar> searchByID = cell.SearchByID(id);
		if (searchByID != nullptr) {
			std::cout << "Товар по ID найден!!" << searchByID->GetId() << std::endl;
		}
		else {
			std::cout << "Товар не найден" << std::endl;
		}
		break;
	}
	case 7:
		break;
	default:
		std::cout << "Вы ввели не верную цифру!!!" << std::endl;
		break;	
	}
	
	return 0;
}
