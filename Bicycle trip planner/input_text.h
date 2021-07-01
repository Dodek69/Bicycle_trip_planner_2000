#pragma once
#include <string>
#include <iostream>

/// Funkcja zwracajaca pobrany od uzytkownika tekst
/// @param msg wiadomosc dla uzytkownika
/// @return pobrany od uzytkownika tekst
std::string input_text(const std::string& msg) {
	std::cout << msg << ": ";
	std::string input;
	do {
		getline(std::cin, input);
	} while (!input.size());
	return input;
}