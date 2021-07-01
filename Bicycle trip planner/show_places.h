#pragma once
#include <map>
#include "Place.h"

/// Funkcja wyswietlajaca miejsca oraz informacje o nich
/// @param places mapa wskaznikow na miejsca
void show_places(const std::map<unsigned short int, Place*>& places);