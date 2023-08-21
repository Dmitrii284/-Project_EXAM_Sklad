#ifndef _CELL_H_
#define _CELL_H_

#ifndef _TOVAR_H_
#include "Tovar.h"
#endif

#include<map>
#include<memory>

class Cell // Ячейка
{
private:
	std::map<int, std::shared_ptr<Tovar>> m_Tovars;
	int m_MaxWeight;
	int m_CurrentWeight{ 0 };
	char m_UniqueLetter;
	int m_UniqueNumber;
public:
	Cell(int maxWeight, char uniqueLetter, int uniqueNumber) :
		m_MaxWeight{ maxWeight }, m_UniqueLetter{ uniqueLetter }, m_UniqueNumber{ uniqueNumber }{ }

	bool AddTovar( std::shared_ptr<Tovar>& tovar)
	{
		int check_weight = m_CurrentWeight + tovar->GetWeight();

		if (check_weight > m_MaxWeight)
			return false;
		m_Tovars.insert(std::make_pair(tovar->GetId(), tovar));
		tovar->SetCell(m_UniqueLetter + std::to_string(m_UniqueNumber));
		return true;	
	}

	void ShowId()
	{
		std::cout << m_UniqueLetter + std::to_string(m_UniqueNumber) << std::endl;
	}

	std::shared_ptr<Tovar>& Search(int id)
	{
		return m_Tovars.find(id)->second;
	}

	void ShowTovars()
	{
		for (const auto& tovar : m_Tovars)
		{
			std::cout << "Tovar's id " << tovar.first << ':' << std::endl;
			tovar.second->ShowTovar();
		}
	}

	std::shared_ptr<Tovar>SearchByID(int id)
	{
		auto it = m_Tovars.find(id);
		if (it == m_Tovars.end())
			return nullptr;
		return it->second;
	}

	std::shared_ptr<Tovar>SearchByName(const std::string& name)
	{
		for (const auto& it : m_Tovars)
		{
			if (it.second->GetName() == name)			
				return it.second;
		}		
		return nullptr;
	}

	void ShipTovar(int id)// Функция огрузки товара по id
	{
		auto tovar = SearchByID(id);
		tovar->SetExitTime();
		m_Tovars.erase(tovar->GetId());
	}
	void ShipTovar(const std::string& name)// Функция огрузки товара по name
	{
		auto tovar = SearchByName(name);
		tovar->SetExitTime();
		m_Tovars.erase(tovar->GetId());//Плучаем по GetId() id товара  и удаляем его.
	}
};

#endif // !_CELL_H_

