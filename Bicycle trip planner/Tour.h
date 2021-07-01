#pragma once
#include <ostream>
#include <string>

/// Klasa reprezentujaca wycieczke
class Tour
{
	friend std::ostream& operator<<(std::ostream& os, const Tour& tour);
	short int average_difficulty,	///< srednia trudnosc
		greatest_difficulty;		///< najwieksza trudnosc
	std::string date;				///< data

public:
	/// Kostruktor klasy Tour
	/// @param date data
	/// @param amsl wysokosc n.p.m.
	/// @param average_difficulty srednia trudnosc
	/// @param greatest_difficulty najwyzsza trudnosc
	Tour(const std::string& date, const short int& average_difficulty, const short int& greatest_difficulty) : date(date), average_difficulty(average_difficulty), greatest_difficulty(greatest_difficulty) {}

	/// Kostruktor klasy Tour, inicializujacy pole Date dzisiejsza datom
	/// @param average_difficulty srednia trudnosc
	/// @param greatest_difficulty najwyzsza trudnosc
	Tour(const short int& average_difficulty, const short int& greatest_difficulty) : average_difficulty(average_difficulty), greatest_difficulty(greatest_difficulty) {
		time_t rawtime;
		struct tm ltm;
		time(&rawtime);
		localtime_s(&ltm, &rawtime);

		date = std::to_string(ltm.tm_mday) + '-' + std::to_string(1 + ltm.tm_mon) + '-' + std::to_string(1900 + ltm.tm_year);
	}

	/// Funkcja wyswietlajaca informacje o wycieczce
	void show() {
		std::cout << "Date: " << date << ", avarage difficulty: " << average_difficulty << "/100, greatest difficulty: " << greatest_difficulty << "/100\n";
	}
};


/// Przeciazenie operatora << klasy Tour
/// @param os sturmien wyjsciowy
/// @param tour wycieczka
/// @return sturmien wyjsciowy
inline std::ostream& operator<<(std::ostream& os, const Tour& tour)
{
	os << tour.date << ' ' << tour.average_difficulty << ' ' << tour.greatest_difficulty;
	return os;
}