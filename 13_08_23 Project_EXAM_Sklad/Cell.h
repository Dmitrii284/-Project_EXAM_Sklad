#ifndef _CELL_H_
#define _CELL_H_

#ifndef _TOVAR_H_
#include "Tovar.h"
#endif

#include<map>
#include<memory>

class Cell
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
			std::cout << "Tovar: " << std::endl;
			std::cout << "----------TOVAR_BEGIN----------" << std::endl;
			std::cout << "Id: " << tovar.first << ": " << std::endl;
			tovar.second->ShowTovar();
			std::cout << "----------TOVAR_END----------" << std::endl;
		}
	}
};




#endif // !_CELL_H_

