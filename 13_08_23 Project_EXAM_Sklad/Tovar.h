#ifndef _TOVAR_H_
#define _TOVAR_H_

#include <string>
#include <cstring>
#include <chrono>
#include<iostream>

#include <random>
#pragma warning(disable : 4996) // Блокируем ошибку по gmtime . 4996 - Просто выключили 4996 код ошибки

//  class Date// Время прихода и убытия товара со склада 
//		{
//		private:
//			uint16_t m_Day;
//			uint16_t m_Year;
//			uint16_t m_Month;
//			uint16_t m_Hour;
//			uint16_t m_Minutes;
//			uint16_t m_Seconds;
//			
//		public:
//			Date()
//			{
//				/*			auto get_random_number_in_range = [this](int min, int max) 
//				{
//					std::random_device dev;
//					std::mt19937 rng(dev());
//					std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max); 
//					return dist6(rng);
//				};
//
//				m_Year = get_random_number_in_range(2000, 3000);
//				m_Month = get_random_number_in_range(1, 12);
//				m_Day = get_random_number_in_range(1, 31);
//				m_Hour = get_random_number_in_range(1, 24);
//				m_Minutes = get_random_number_in_range(1,60);
//				m_Seconds = get_random_number_in_range(1,60);	*/		
//
//time_t now = time(0);
//struct tm tstruct = *localtime(&now);
//
//m_Day = tstruct.tm_mday;
//m_Year = tstruct.tm_year + 1900;
//m_Month = tstruct.tm_mon + 1;
//
//m_Hour = tstruct.tm_hour;
//m_Minutes = tstruct.tm_min;
//m_Seconds = tstruct.tm_sec;
//			}
//
//			void Show()
//			{
//				/*std::cout << "Day: " << m_Day << std::endl;
//				std::cout <<"Year: " << m_Year << std::endl;
//				std::cout << "Month: " << m_Month << std::endl;
//				std::cout << "Hour: " << m_Hour << std::endl;
//				std::cout << "Minutes: " << m_Minutes << std::endl;
//				std::cout << "Seconds: " << m_Seconds << std::endl;*/
//				std::cout << "Date: " << m_Day << '.' << m_Month << '.' << m_Year << std::endl;
//				std::cout << "Time: " << m_Hour << "h:" << m_Minutes << "m:" << m_Seconds << "s" << std::endl;
//			}
//		}*m_TimeEnter{nullptr}, * m_TimeExit{ nullptr };
 

class Tovar
{
private:
	std::string m_Name;
	float m_Weight;
	uint32_t m_Id;
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

	uint32_t GetId() { return m_Id; }

	std::string GetName() { return m_Name; }

	void SetCell(const std::string& cellName)
	{
		m_CellName = cellName;
	}

};

#endif // !_TOVAR_H_