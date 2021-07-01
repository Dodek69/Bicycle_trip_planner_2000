#pragma once
#include "Place.h"
#include "difficulty_computing.h"
#include <iostream>
#include "handbook.h"

/// Klasa reprezentujaca rownine
class Plain :
	public Place
{
	
	/// Wirtualna metoda obliczajaca, inicjujaca i zwracajaca trudnosc miejsca, na podstawie wysokosci n.p.m.
	/// @return trudnosc miejsca
	virtual short int calculate_difficulty() {
		return difficulty = trim_difficulty(1 + calculate_altitude_difficulty(amsl));
	}
	
	/// Wirtualna metoda wyswietlajaca opis miejsca (atrybuty obiektu)
	virtual void show() const {
		std::cout << "Name: \"" << name << "\", type: plain, difficulty: " << difficulty << ", height above sea level: " << amsl << show_handbook(has_ISBN_number) << handbook;
	}

public:
	/// Kostruktor klasy Plain
	/// @param name nazwa rowniny
	/// @param amsl wysokosc n.p.m.
	/// @param handbook para opisujaca przewodnik
	Plain(const std::string& name, const short int& amsl, const std::pair<std::string, bool>& handbook) : Place(name, amsl, handbook.first, handbook.second) {}
};