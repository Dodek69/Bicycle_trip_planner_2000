#pragma once
#include <string>
#include <iostream>
#include <conio.h>


/// Funkcja zwracajaca pobierana od uzytkownika wartosc logiczna
/// @param msg wiadomosc dla uzytkownika
/// @return wartosc logiczna
bool input_boolean(const std::string& msg) {
	std::cout << msg << " (y/n)";
	while (true) {
		char input = _getch();

		if (input == 'Y' || input == 'y') {
			std::cout << "\n";
			return true;
		}
		else if (input == 'N' || input == 'n') {
			std::cout << "\n";
			return false;
		}
	}
}