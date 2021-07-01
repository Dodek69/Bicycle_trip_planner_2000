#pragma once
#include "Place.h"
#include "difficulty_computing.h"
#include <iostream>
#include "handbook.h"

/** Klasa reprezentujaca rownine */
class Plain :
	public Place
{
	virtual short int calculate_difficulty() {
		return difficulty = trim_difficulty(1 + calculate_altitude_difficulty(amsl));
	}
	virtual void show() const {
		std::cout << "Name: \"" << name << "\", type: plain, difficulty: " << difficulty << ", height above sea level: " << amsl << show_handbook(has_ISBN_number) << handbook;
	}

public:
	Plain(const std::string& name, const short int& amsl, const std::pair<std::string, bool>& handbook) : Place(name, amsl, handbook.first, handbook.second) {}
};

