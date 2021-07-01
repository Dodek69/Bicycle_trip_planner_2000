#pragma once
#include <string>
#include <iostream>

std::string input_text(const std::string& msg) {
	std::cout << msg << ": ";
	std::string input;
	do {
		getline(std::cin, input);
	} while (!input.size());
	return input;
}