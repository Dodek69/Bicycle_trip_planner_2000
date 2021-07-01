#pragma once
#include <map>
#include <iostream>
#include "annual_report.h"
#include <conio.h>
#include "plan.h"
#include "add_place.h"
#include "delete_place.h"
#include "show_places.h"

int main() {
	system("title Bicycle trip planner 2000");
	std::map<unsigned short int, Place*> places;
	char selection_key;
	do {
		std::cout << "1. Plan route\n2. Add place\n3. Delete place\n4. Places\n5. Annual report\nEsc. Exit";
		selection_key = _getch();

		switch (selection_key) {
		case '1': // Plan route
			plan(places);
			break;
		case '2': // Add place
			add_place(places);
			break;
		case '3': // Delete place
			delete_place(places);
			break;
		case '4': // Places
			show_places(places);
			break;
		case '5': // Annual report
			annual_report();
		}
		system("cls");
	} while (selection_key != 27); // Exit
	return 0;
}