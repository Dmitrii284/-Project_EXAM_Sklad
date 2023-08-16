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
	std::map<uint32_t, std::shared_ptr<Tovar>> m_Tovars;
	uint32_t m_MaxWeight;
	uint32_t m_CurrentWeight{ 0 };
	char m_UniqueLetter;
	uint16_t m_UniqueNumber;
public:
	Cell(uint32_t maxWeight, char uniqueLetter, uint16_t uniqueNumber) :
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

	std::shared_ptr<Tovar>& Search(uint32_t id)
	{
		return m_Tovars.find(id)->second;
	}

	/*main
	{
		Serch(10)->ShowTovar();
	}*/

	void ShowTovars()
	{
		for (const auto& tovar : m_Tovars)
		{
			std::cout << "Tovar's id " << tovar.first << ':' << std::endl;
			tovar.second->ShowTovar();
		}
	}

	std::shared_ptr<Tovar>SearchByID(uint32_t id)
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

	void ShipTovar(uint32_t id)// Функция огрузки товара по id
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

