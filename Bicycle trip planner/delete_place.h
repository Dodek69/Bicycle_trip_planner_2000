#include <map>
#include "Place.h"
#pragma once


/// Funkcja usuwajaca miejsce. W tym celu wyswietla miejsca i pobiera ID miejsca od uzytkownika
/// @param places mapa wskaznikow do obiektow klasy Place
void delete_place(std::map<unsigned short int, Place*>& places);