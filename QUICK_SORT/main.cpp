#include "initializeStructure.hpp"

int main() {
	Information info; // Initialize the structure

	if (!info.textFile("HATENESS.txt")) {
		std::cout << "ERROR TO CREATE THE FILE!";
		return 1;
	}

	info.vvod();
	std::cout << "\nOriginal list of trains:\n";
	info.vivod();

	// THE FIND
	std::cout << "\nTrains with long journey times:\n";
	info.find();

	// THE QUICK SORT(OH MAN, IT'S JUST REALLY CRAZY!!!)
	std::cout << "\nSorted by destination:\n";
	info.sortTrains();
	info.vivod();
	return 0;
}