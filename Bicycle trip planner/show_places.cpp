#include "show_places.h"
#include <iostream>
#include "list_places.h"
#include <conio.h>

void show_places(const std::map<unsigned short int, Place*>& places) {
	system("cls");
	if (!places.size())
		std::cout << "You need to add places first.";
	else
		list_places(places);
	_getch();
}