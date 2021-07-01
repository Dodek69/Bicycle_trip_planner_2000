#pragma once
#include <map>
#include "Place.h"


/// Funkcja dodajaca miejsce. W tym celu pobiera dane od uzytkownika, tworzy i inicjuje obiekt klasy Place, a nastepnie umieszcza wskaünik do obiektu w danej mapie
/// @param places mapa wskaznikow do obiektow klasy Place
void add_place(std::map<unsigned short int, Place*>& places);