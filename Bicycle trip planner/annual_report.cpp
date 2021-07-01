#include "annual_report.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
#include "Tour.h"

bool interval_check(const std::string date) {
	unsigned short int x = date.find_first_of('-'), y = date.find_last_of('-');
	unsigned short int day = std::stoi(date.substr(0, x)), month = std::stoi(date.substr(x + 1, y - 2)), year = std::stoi(date.substr(y + 1));

	time_t rawtime;
	struct tm ltm;
	time(&rawtime);
	localtime_s(&ltm, &rawtime);

	if (year == 1900 + ltm.tm_year)
		return true;
	else if (year == 1899 + ltm.tm_year)
		if (month > 1 + ltm.tm_mon)
			return true;
		else if (month == 1 + ltm.tm_mon)
			if (day >= ltm.tm_mday)
				return true;
			else
				return false;
		else
			return false;
	return false;
}

void annual_report() {
	system("cls");
	std::vector<Tour> tours;
	short int year_avg_diff = 0, year_max_diff = 0;
	std::string year_max_diff_date;
	{
		std::ifstream tours_file("tours");
		std::string date;
		short int avg_diff, max_diff;

		while (tours_file.good()) {
			tours_file >> date >> avg_diff >> max_diff;

			if (interval_check(date)) {
				tours.emplace_back(date, avg_diff, max_diff);
				if (max_diff > year_max_diff) {
					year_max_diff = max_diff;
					year_max_diff_date = date;
				}
				year_avg_diff += avg_diff;
			}
		}
	}
	if (short int number = tours.size()) {
		std::cout << "Annual report:\nNumber of tours: " << number << "\nAvarage difficulty: " << year_avg_diff / number << "/100\nGreatest difficulty: " << year_max_diff << "/100, date: " << year_max_diff_date << "\n\nList of tours:\n";
		for (Tour tour : tours)
			tour.show();
	}
	else
		std::cout << "No tours in memory.";
	_getch();
}