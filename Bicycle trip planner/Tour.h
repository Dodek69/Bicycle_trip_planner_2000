#pragma once
#include <ostream>
#include <string>

/** Klasa reprezentujaca wycieczke */
class Tour
{
	friend std::ostream& operator<<(std::ostream& os, const Tour& tour);
	short int average_difficulty, greatest_difficulty;
	std::string date;
public:
	Tour(const std::string& date, const short int& average_difficulty, const short int& greatest_difficulty) : date(date), average_difficulty(average_difficulty), greatest_difficulty(greatest_difficulty) {}
	Tour(const short int& average_difficulty, const short int& greatest_difficulty) : average_difficulty(average_difficulty), greatest_difficulty(greatest_difficulty) {
		time_t rawtime;
		struct tm ltm;
		time(&rawtime);
		localtime_s(&ltm, &rawtime);

		date = std::to_string(ltm.tm_mday) + '-' + std::to_string(1 + ltm.tm_mon) + '-' + std::to_string(1900 + ltm.tm_year);
	}
	void show() {
		std::cout << "Date: " << date << ", avarage difficulty: " << average_difficulty << "/100, greatest difficulty: " << greatest_difficulty << "/100\n";
	}
};

inline std::ostream& operator<<(std::ostream& os, const Tour& tour)
{
	os << tour.date << ' ' << tour.average_difficulty << ' ' << tour.greatest_difficulty;
	return os;
}