#pragma once
#include <map>
#include "Place.h"
#include <iostream>
#include "list_places.h"
#include "difficulty_computing.h"

/// Funkcja, ktora za pomoca interfejsu umozliwia planowanie trasy
/// @param places mapa wskaznikow do miejsc
void plan(const std::map<unsigned short int, Place*>& places);

/// Funkcja obliczajaca srednia i maksymalna trudnosc trasy
/// @param route mapa wskaznikow miejsca na trasie
/// @return para - srednia oraz maksymalna trudnosc trasy
inline std::pair<short int, short int> calculate_route_difficulty(const std::map<unsigned short int, Place*>& route) {
	short int avg_diff = 0, max_diff = 0, diff;
	for (std::pair<unsigned short int, Place*> place : route) {
		diff = place.second->get_difficulty();
		avg_diff += diff;
		if (diff > max_diff)
			max_diff = diff;
	}
	return std::make_pair(avg_diff / route.size(), max_diff);
}

/// Funkcja stanowiaca interfejs podczas planowania trasy
/// @param route mapa wskaznikow na miejsca na trasie
/// @param places mapa wskaznikow na miejsca
/// @param diff para - srednia oraz maksymalna trudnosc trasy
inline void planner_interface(const std::map<unsigned short int, Place*>& route, const std::map<unsigned short int, Place*>& places, const std::pair<short int, short int>& diff) {
	system("cls");
	list_places(places);
	std::cout << "============================================================================================================================\nList of places added to the route:\n";
	if (!route.size())
		std::cout << "Empty.";
	else
		list_places(route);
	std::cout << "\n============================================================================================================================\n1. Add place to the route.\n2. Remove place from the route.\n";

	if (route.size())
		std::cout << "3. Confirm route (average difficulty: " << diff.first << ", greatest difficulty: " << diff.second << ")\n";
	std::cout << "Esc. Exit";
}

/// Funkcja dodajaca miejsce do trasy
/// @param route mapa wskaznikow na miejsca na trasie
/// @param places mapa wskaznikow na miejsca
void add_place_to_route(const std::map<unsigned short int, Place*>& places, std::map<unsigned short int, Place*>& route);

/// Funkcja usuwajaca miejsce z trasy
/// @param route mapa wskaznikow na miejsca na trasie
/// @param places mapa wskaznikow na miejsca
void remove_place_from_route(const std::map<unsigned short int, Place*>& places, std::map<unsigned short int, Place*>& route);

/// Funkcja zapisujaca trase w pliku "tours"
/// @param diff para - srednia oraz maksymalna trudnosc trasy
void confirm_route(const std::pair<short int, short int>& diff);