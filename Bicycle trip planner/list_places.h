#pragma once
#include <map>
#include "Place.h"
#include <iostream>

/// Funkcja wyswietlajaca obiekty klasy Place zawarte w mapie wskaznikow na nie
/// @param places mapa wskaznikow na obiekty klasy Place
inline void list_places(const std::map<unsigned short int, Place*>& places) {
	std::cout << "Places:\n";
	for (std::pair<short int, Place*> place : places) {
		std::cout << "ID: " << place.first << ", ";
		place.second->show();
		std::cout << "\n";
	}
}