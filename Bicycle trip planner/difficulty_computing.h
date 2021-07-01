#pragma once


/// Funkcja zwracajaca wartosc bezwzgledna podanej wartosci calkowitej
/// @param val liczba calkowita
/// @return wartosc bezwzgledna argumentu funkcji
inline short int abs(const short int& val) {
	if (val < 0)
		return -val;
	return val;
}


/// Funkcja normalizujaca zakres trudnosci
/// @param diff trudnosc
/// @return znormalizowana wartosc trudnosci (1-100)
inline short int trim_difficulty(const short int& diff) {
	if (diff < 1)
		return 1;
	else if (diff > 100)
		return 100;
	return diff;
}


/// Funkcja obliczajaca trudnosc ze wzgledu na wysokosc n.p.m. miejsca
/// @param amsl wysokosc n.p.m. miejsca
/// @return trudnosc ze wzgledu na wysokosc n.p.m. miejsca
inline short int calculate_altitude_difficulty(const short int& amsl) {
	return abs(amsl) / 1000;
}