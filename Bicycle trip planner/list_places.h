#pragma once
#include <map>
#include "Place.h"
#include <iostream>

inline void list_places(const std::map<unsigned short int, Place*>& places) {
	std::cout << "Places:\n";
	for (std::pair<short int, Place*> place : places) {
		std::cout << "ID: " << place.first << ", ";
		place.second->show();
		std::cout << "\n";
	}
}
