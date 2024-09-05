#pragma once
#include <sstream>
#include <string>
#include <vector>

#include "InputSelection.h"

class Terminal {
	std::ostringstream oss;
	const int MAX_OPTIONS = 6;
	const int ANIMATION_DURATION = 50;
	std::vector<std::string> options = {"Explore", "Enter combat mode", "Steal valuable resources",
																		 "View available commands","options", "Quit"};
	const std::string color = "\033[32m";  // Green color

public:
	Terminal();
	 int hubInput;

	void initializeHub() const;
	void animate(int duration);
	void drawOptions();
};



