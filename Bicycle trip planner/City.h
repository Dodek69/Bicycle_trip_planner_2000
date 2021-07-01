#pragma once
#include "Place.h"
#include "difficulty_computing.h"
#include <iostream>
#include "handbook.h"

/** Klasa reprezentujaca miasto */
class City :
	public Place
{
	short int traffic, bike_lanes_length;
	virtual short int calculate_difficulty() {
		return difficulty = trim_difficulty(traffic / (5 + bike_lanes_length) + calculate_altitude_difficulty(amsl));
	}
	virtual void show() const {
		std::cout << "Name: \"" << name << "\", type: city, difficulty: " << difficulty << ", height above sea level: " << amsl << show_handbook(has_ISBN_number) << handbook << ", traffic: " << traffic << ", bike lanes length " << bike_lanes_length;
	}
public:
	City(const std::string& name, const short int& amsl, const std::pair<std::string, bool>& handbook, const unsigned short int& traffic, const unsigned short int& bike_lanes_length) : Place(name, amsl, handbook.first, handbook.second), traffic(traffic), bike_lanes_length(bike_lanes_length) {}
};

