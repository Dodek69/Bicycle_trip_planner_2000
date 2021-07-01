
#pragma once
#include <string>

/// Klasa abstrakcyjna reprezentujaca miejsce
class Place
{
protected:
	std::string name;		///< nazwa miejsca
	short int amsl;			///< wysokosc n.p.m.
	std::string handbook;	///< numer ISBN, badz nazwa przewodnika
	bool has_ISBN_number;	///< posiadanie numeru ISBN
	short int difficulty;	///< trudnosc
	
	/// Kostruktor klasy Place
	/// @param name nazwa miejsca
	/// @param amsl wysokosc n.p.m.
	/// @param handbook numer ISBN, badz nazwa przewodnika
	/// @param has_ISBN_number posiadanie numeru ISBN
	Place(const std::string& name, const short int& amsl, const std::string& handbook, const bool& has_ISBN_number) : name(name), amsl(amsl), handbook(handbook), has_ISBN_number(has_ISBN_number) {}
public:
	
	/// Metoda czysto wirtualna obliczajaca i zwracajaca atrybut trudnosci
	/// @return trudnosc miejsca
	virtual short int calculate_difficulty() = 0;

	
	/// Metoda czysto wirtualna wyswietlajaca atrybuty o obiektu
	virtual void show() const = 0;

	
	/// Metoda zwracajaca trudnosc miejsca
	/// @return trudnosc miejsca
	short int get_difficulty() const {
		return difficulty;
	}
};