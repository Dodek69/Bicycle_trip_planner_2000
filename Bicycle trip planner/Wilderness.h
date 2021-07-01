#pragma once
#include "Place.h"
#include "difficulty_computing.h"
#include <iostream>
#include "handbook.h"

/** Klasa reprezentujaca odludzie */
class Wilderness :
    public Place
{
	short int distance_to_public_transport;
	virtual short int calculate_difficulty() {
		return difficulty = trim_difficulty(distance_to_public_transport / 2 + calculate_altitude_difficulty(amsl));
	}
	virtual void show() const {
		std::cout << "Name: \"" << name << "\", type: wilderness, difficulty: " << difficulty << ", height above sea level: " << amsl << show_handbook(has_ISBN_number) << handbook << ", distance to public transport: " << distance_to_public_transport;
	}
public:
	Wilderness(const std::string& name, const short int& amsl, const std::pair<std::string, bool>& handbook, const unsigned int& distance_to_public_transport) : Place(name, amsl, handbook.first, handbook.second), distance_to_public_transport(distance_to_public_transport) {}
};