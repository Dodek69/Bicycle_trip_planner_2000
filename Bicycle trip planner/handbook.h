#include <string>
#pragma once


/// Funkcja zwracajaca odpowiedni tekst, w zaleznosci od wartosci logicznej parametru, okreslajacego czy przewodnik opsiujacy miejsce ma numer ISBN
/// @param has_ISBN_number wartosc logiczna okreslajaca, czy przewodnik opsiujacy miejsce ma numer ISBN
/// @return tekst 
inline std::string show_handbook(const bool& has_ISBN_number) {
	if (has_ISBN_number)
		return ", handbook ISBN number: ";
	else
		return ", handbook title: ";
}