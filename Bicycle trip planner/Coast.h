#pragma once
#include "Place.h"
#include "difficulty_computing.h"
#include <iostream>
#include "handbook.h"

/// Klasa reprezentujaca wybrzeze
class Coast :
	public Place
{
	short int distance_to_port;	///< odleglosc od portu
	bool bike_lanes;			///< obecnosc sciezek rowerowych
	
	/// Wirtualna metoda obliczajaca, inicjujaca i zwracajaca trudnosc miejsca, na podstawie wysokosci n.p.m., odleglosci od portu i obecnosci sciezek rowerowych
	/// @return trudnosc miejsca
	virtual short int calculate_difficulty() {
		return difficulty = trim_difficulty(distance_to_port / (2 + 8 * bike_lanes) + calculate_altitude_difficulty(amsl));
	}
	
	/// Wirtualna metoda wyswietlajaca opis miejsca (atrybuty obiektu)
	virtual void show() const {
		std::cout << "Name: \"" << name << "\", type: coast, difficulty: " << difficulty << ", height above sea level: " << amsl << show_handbook(has_ISBN_number) << handbook << ", distance to port: " << distance_to_port << ", bike_lane: ";
		if (bike_lanes)
			std::cout << "yes";
		else
			std::cout << "no";
	}
public:
	
	/// Kostruktor klasy Coast
	/// @param name nazwa wybrzeza
	/// @param amsl wysokosc n.p.m.
	/// @param handbook para opisujaca przewodnik
	/// @param distance_to_port odleglosc od portu
	/// @param bike_lanes obecnosc sciezek rowerowych
	Coast(const std::string& name, const short int& amsl, const std::pair<std::string, bool>& handbook, const unsigned int& distance_to_port, const bool& bike_lanes) : Place(name, amsl, handbook.first, handbook.second), distance_to_port(distance_to_port), bike_lanes(bike_lanes) {}
};

