#include "delete_place.h"
#include <iostream>
#include <conio.h>
#include "list_places.h"
#include "input_numeric.h"

void delete_place(std::map<unsigned short int, Place*>& places) {
	system("cls");
	if (!places.size())
		std::cout << "No places to delete.";
	else {
		list_places(places);
		short int id;
		do {
			id = input_numeric("Enter ID", 1, places.size());
		} while (std::find_if(places.begin(), places.end(), [id](std::pair<unsigned short int, Place*> i) { return i.first == id; }) == places.end());
		delete places[id];
		places.erase(id);
		std::cout << "Place has been deleted.";
	}
	_getch();
}