#ifndef _TOVAR_H_
#define _TOVAR_H_

#include <string>
#include <cstring>
#include <chrono>
#include<iostream>

#include <random>
#pragma warning(disable : 4996) // Блокируем ошибку по gmtime . 4996 - Просто выключили 4996 код ошибки

class Tovar
{
private:
	std::string m_Name;
	float m_Weight;
	int m_Id;
	std::string m_CellName{" "};
	std::string m_EnterTime;
	std::string m_ExitTime;

public:
	Tovar() = default;

	Tovar(std::string name, float weight) : m_Name{ std::move(name) }, m_Weight{ weight }
	{
		SetEnterTime();

		std::random_device dev;// Для рандомной генерации ID
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(0, UINT32_MAX);
		m_Id = dist6(rng);
	}

	std::string GetTimeInUTC()
	{
		time_t in_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::stringstream ss;
		ss << "UTC: " << std::put_time(std::gmtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
		return ss.str();
	}

	void SetExitTime()
	{
		m_ExitTime = GetTimeInUTC();
	}

	void SetEnterTime()
	{
		m_EnterTime = GetTimeInUTC();
	}

	void ShowTovar()
	{
		if (!m_CellName.empty())
			std::cout << "Cell: " << m_CellName << std::endl;
		std::cout << "Name: " << m_Name << std::endl;
		std::cout << "Weight: " << m_Weight << std::endl;
		std::cout << "ID: " << m_Id << std::endl << std::endl;

		std::cout << "Enter time: " << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << m_EnterTime << std::endl;
		std::cout << "------------------------------------" << std::endl << std::endl;

		std::cout << "Exit time: " << std::endl;
		std::cout << "------------------------------------" << std::endl;

		if (!m_ExitTime.empty())
			std::cout << m_ExitTime << std::endl;
		else
			std::cout << "The product has not been shipped" << std::endl;
		std::cout << "------------------------------------" << std::endl;
	}
	float GetWeight() { return m_Weight; }

	int GetId() { return m_Id; }

	std::string GetName() { return m_Name; }

	void SetCell(const std::string& cellName)
	{
		m_CellName = cellName;
	}	
};

#endif // !_TOVAR_H_