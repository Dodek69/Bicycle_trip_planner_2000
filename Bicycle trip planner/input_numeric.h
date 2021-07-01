#include <string>
#include <iostream>
#pragma once

inline bool is_number(const std::string& text)
{
	if (text.empty())
		return false;
	if (text[0] == '-')
		return std::find_if(text.begin()+1,
			text.end(), [](unsigned char c) { return !std::isdigit(c); }) == text.end();
	return std::find_if(text.begin(),
		text.end(), [](unsigned char c) { return !std::isdigit(c); }) == text.end();
}

inline short int input_numeric(const std::string& msg, const short int& min, const short int& max) {
	int number;
	std::string input;
	bool we_good = false;
	do {
		std::cout << msg << ": ";
		std::cin >> input;

		if (we_good = is_number(input)) {
			number = std::stoi(input);
		}
	} while (!we_good || number < min || number > max);
	return number;
}