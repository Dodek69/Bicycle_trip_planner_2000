#pragma once

inline short int abs(const short int& val) {
	if (val < 0)
		return -val;
	return val;
}

inline short int trim_difficulty(const short int& diff) {
	if (diff < 1)
		return 1;
	else if (diff > 100)
		return 100;
	return diff;
}

inline short int calculate_altitude_difficulty(const short int& amsl) {
	return abs(amsl) / 1000;
}