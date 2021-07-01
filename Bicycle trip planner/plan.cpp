#include "plan.h"
#include <conio.h>
#include "difficulty_computing.h"
#include "input_numeric.h"
#include <fstream>
#include "Tour.h"

void plan(const std::map<unsigned short int, Place*>& places) {
	if (!places.size()) {
		system("cls");
		std::cout << "You need to add places first.";
		_getch();
	}
	else {
		std::map<unsigned short int, Place*> route;
		char selection_key;
		std::pair<short int, short int> difficulty;
		do {
			if (route.size())
				difficulty = calculate_route_difficulty(route);
			planner_interface(route, places, difficulty);
			selection_key = _getch();
			switch (selection_key) {
			case '1': // Add place to route
				add_place_to_route(places, route);
				break;
			case '2': // Remove place from route
				remove_place_from_route(places, route);
				break;
			case '3': // Confirm route
				if (route.size())
				{
					confirm_route(difficulty);
					selection_key = 27;
				}
		}
		} while (selection_key != 27);
	}
}


void add_place_to_route(const std::map<unsigned short int, Place*>& places, std::map<unsigned short int, Place*>& route) {
	system("cls");
	if (places.size() == route.size()) {
		std::cout << "No more places to add.";
		_getch();
	}
	else {
		short int id;
		do {
			id = input_numeric("Enter ID", 1, places.size());
		} while (std::find_if(route.begin(), route.end(), [id](std::pair<unsigned short int, Place*> i) { return i.first == id; }) != route.end());
		route[id] = places.at(id);
	}
}


void remove_place_from_route(const std::map<unsigned short int, Place*>& places, std::map<unsigned short int, Place*>& route) {
	system("cls");
	if (!route.size()) {
		std::cout << "Route is empty.";
		_getch();
	}
	else {
	short int id;
	do {
		id = input_numeric("Enter ID", 1, places.size());
	} while (std::find_if(route.begin(), route.end(), [id](std::pair<unsigned short int, Place*> i) { return i.first == id; }) == route.end());
	route.erase(id);
	}
}

void confirm_route(const std::pair<short int, short int>& diff) {
	std::ofstream tour_file("tours", std::ios::app);
	tour_file << "\n" << Tour(diff.first, diff.second);
	system("cls");
	std::cout << "Route confirmed.";
	_getch();
}