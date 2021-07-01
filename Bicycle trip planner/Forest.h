#pragma once
#include "Place.h"
#include "difficulty_computing.h"
#include <iostream>
#include "handbook.h"

/// Klasa reprezentujaca las
class Forest :
	public Place
{
	short int path_quality;	///< jakosc drog
	
	/// Wirtualna metoda obliczajaca, inicjujaca i zwracajaca trudnosc miejsca, na podstawie wysokosci n.p.m. i jakosci drog
	/// @return trudnosc miejsca
	virtual short int calculate_difficulty() {
		return difficulty = trim_difficulty(1 + 80 / path_quality + calculate_altitude_difficulty(amsl));
	}
	
	/// Wirtualna metoda wyswietlajaca opis miejsca (atrybuty obiektu)
	virtual void show() const {
		std::cout << "Name: \"" << name << "\", type: forest, difficulty: " << difficulty << ", height above sea level: " << amsl << show_handbook(has_ISBN_number) << handbook << ", path quality: " << path_quality;
	}
public:
	
	/// Kostruktor klasy Forest
	/// @param name nazwa lasu
	/// @param amsl wysokosc n.p.m.
	/// @param handbook para opisujaca przewodnik
	/// @param path_quality jakosc drog
	Forest(const std::string& name, const short int& amsl, const std::pair<std::string, bool>& handbook, const unsigned short int& path_quality) : Place(name, amsl, handbook.first, handbook.second), path_quality(path_quality) {}
};

