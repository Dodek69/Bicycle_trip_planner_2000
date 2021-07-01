#pragma once
#include "Place.h"
#include "difficulty_computing.h"
#include <iostream>
#include "handbook.h"

/** Klasa reprezentujaca gory */
class Mountains :
	public Place
{
	short int distance_to_mountain_hostel, height_difference, path_quality;

	virtual short int calculate_difficulty() {
		return difficulty = trim_difficulty(distance_to_mountain_hostel + height_difference / 50 + 80 / path_quality + calculate_altitude_difficulty(amsl));
	}
	virtual void show() const {
		std::cout << "Name: \"" << name << "\", type: mountains, difficulty: " << difficulty << ", height above sea level: " << amsl << show_handbook(has_ISBN_number) << handbook << ", distance to mountain hostel: " << distance_to_mountain_hostel << ", height difference " << height_difference << ", path quality: " << path_quality;
	}
public:
	Mountains(const std::string& name, const short int& amsl, const std::pair<std::string, bool>& handbook, const unsigned int& distance_to_mountain_hostel, const unsigned short int& height_difference, const unsigned short int& path_quality) : Place(name, amsl, handbook.first, handbook.second), distance_to_mountain_hostel(distance_to_mountain_hostel), height_difference(height_difference), path_quality(path_quality) {}
};

