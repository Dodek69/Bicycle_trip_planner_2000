#include <string>
#pragma once

inline std::string show_handbook(const bool& has_ISBN_number) {
	if (has_ISBN_number)
		return ", handbook ISBN number: ";
	else
		return ", handbook title: ";
}