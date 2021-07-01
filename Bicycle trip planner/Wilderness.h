#pragma once
#include "Place.h"
#include "difficulty_computing.h"
#include <iostream>
#include "handbook.h"

/// Klasa reprezentujaca odludzie
class Wilderness :
    public Place
{
	short int distance_to_public_transport;		///< odleglosc od srodka publicznego transportu

	/// Wirtualna metoda obliczajaca, inicjujaca i zwracajaca trudnosc miejsca, na podstawie wysokosci n.p.m. i odleglosci od srodka publicznego transportu
	/// @return trudnosc miejsca
	virtual short int calculate_difficulty() {
		return difficulty = trim_difficulty(distance_to_public_transport / 2 + calculate_altitude_difficulty(amsl));
	}

	/// Wirtualna metoda wyswietlajaca opis miejsca (atrybuty obiektu)
	virtual void show() const {
		std::cout << "Name: \"" << name << "\", type: wilderness, difficulty: " << difficulty << ", height above sea level: " << amsl << show_handbook(has_ISBN_number) << handbook << ", distance to public transport: " << distance_to_public_transport;
	}
public:

	/// Kostruktor klasy Wilderness
	/// @param name nazwa gor
	/// @param amsl wysokosc n.p.m.
	/// @param handbook para opisujaca przewodnik
	/// @param distance_to_public_transport odleglosc od srodka publicznego transportu
	Wilderness(const std::string& name, const short int& amsl, const std::pair<std::string, bool>& handbook, const unsigned int& distance_to_public_transport) : Place(name, amsl, handbook.first, handbook.second), distance_to_public_transport(distance_to_public_transport) {}
};