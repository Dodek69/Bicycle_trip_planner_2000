#pragma once
#include <string>

/** Klasa abstrakcyjna reprezentujaca miejsce */
class Place
{
protected:
	std::string name;
	short int amsl;
	std::string handbook;
	bool has_ISBN_number;

	short int difficulty;

	Place(const std::string& name, const short int& amsl, const std::string& handbook, const bool& has_ISBN_number) : name(name), amsl(amsl), handbook(handbook), has_ISBN_number(has_ISBN_number) {}
public:
	virtual short int calculate_difficulty() = 0;
	virtual void show() const = 0;
	short int get_difficulty() const {
		return difficulty;
	}
};

