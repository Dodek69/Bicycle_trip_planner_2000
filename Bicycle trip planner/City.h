#pragma once
#include "Place.h"
#include "difficulty_computing.h"
#include <iostream>
#include "handbook.h"

/// Klasa reprezentujaca miasto
class City :
	public Place
{
	short int traffic,		///< natezenie ruchu
		bike_lanes_length;	///< dlugosc sciezek rowerowych
	
	/// Wirtualna metoda obliczajaca, inicjujaca i zwracajaca trudnosc miejsca, na podstawie wysokosci n.p.m., natezenia ruchu i dlugosci sciezek rowerowych
	/// @return trudnosc miejsca
	virtual short int calculate_difficulty() {
		return difficulty = trim_difficulty(traffic / (5 + bike_lanes_length) + calculate_altitude_difficulty(amsl));
	}
	
	/// Wirtualna metoda wyswietlajaca opis miejsca (atrybuty obiektu)
	virtual void show() const {
		std::cout << "Name: \"" << name << "\", type: city, difficulty: " << difficulty << ", height above sea level: " << amsl << show_handbook(has_ISBN_number) << handbook << ", traffic: " << traffic << ", bike lanes length " << bike_lanes_length;
	}
public:
	
	/// Kostruktor klasy City
	/// @param name nazwa miasta
	/// @param amsl wysokosc n.p.m.
	/// @param handbook para opisujaca przewodnik
	/// @param traffic natezenie ruchu
	/// @param bike_lanes_length dlugosc sciezek rowerowych
	City(const std::string& name, const short int& amsl, const std::pair<std::string, bool>& handbook, const unsigned short int& traffic, const unsigned short int& bike_lanes_length) : Place(name, amsl, handbook.first, handbook.second), traffic(traffic), bike_lanes_length(bike_lanes_length) {}
};