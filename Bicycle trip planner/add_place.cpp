#include "add_place.h"
#include "Plain.h"
#include "Forest.h"
#include "City.h"
#include "Mountains.h"
#include "Coast.h"
#include "Wilderness.h"
#include <conio.h>
#include "input_numeric.h"
#include "input_boolean.h" 
#include "input_text.h"
#include <algorithm>

std::pair<std::string, bool> input_handbook() {
	std::string handbook = input_text("handbook ISBN number (type \"none\" if none)");
	bool has_ISBN_number = true;
	if (handbook == "none") {
		has_ISBN_number = false;
		handbook = input_text("handbook title");
	}
	return std::make_pair(handbook, has_ISBN_number);
}

void add_place(std::map<unsigned short int, Place*>& places) {
	system("cls");
	Place* place = nullptr;
	{
		bool rety;
		do {
			rety = false;

			std::string type = input_text("Type (available: plain, forest, city, mountains, coast, wilderness)");
			std::transform(type.begin(), type.end(), type.begin(),
				[](unsigned char c) { return std::tolower(c); });

			if (type == "plain")
				place = new Plain(input_text("Name"), input_numeric("Height above sea level (m)", -431, 8849), input_handbook());
			else if (type == "forest")
				place = new Forest(input_text("Name"), input_numeric("Height above sea level (m)", -431, 8849), input_handbook(), input_numeric("Path quality (1-100)", 1, 100));
			else if (type == "city")
				place = new City(input_text("Name"), input_numeric("Height above sea level (m)", -431, 8849), input_handbook(), input_numeric("Traffic (1-100)", 1, 100), input_numeric("Bike lanes length (km)", 0, SHRT_MAX));
			else if (type == "mountains")
				place = new Mountains(input_text("Name"), input_numeric("Height above sea level (m)", -431, 8849), input_handbook(), input_numeric("Distance to mountain hostel (km)", 0, SHRT_MAX), input_numeric("Average height difference (m)", 0, SHRT_MAX), input_numeric("Path quality (1-100)", 1, 100));
			else if (type == "coast")
				place = new Coast(input_text("Name"), input_numeric("Height above sea level (m)", -431, 8849), input_handbook(), input_numeric("Distance to port (km)", 0, SHRT_MAX), input_boolean("Bike_lanes"));
			else if (type == "wilderness")
				place = new Wilderness(input_text("Name"), input_numeric("Height above sea level (m)", -431, 8849), input_handbook(), input_numeric("Distance to public transport (km)", 0, SHRT_MAX));
			else {
				std::cout << "Invalid place type. ";
				rety = true;
			}
		} while (rety);
	}
	place->calculate_difficulty();
	places[places.size() + 1] = place;

	std::cout << "Place has been added.";
	_getch();
}