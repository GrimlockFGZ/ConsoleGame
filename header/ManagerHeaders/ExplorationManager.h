#pragma once
#include "../header/includes.h"

class ExplorationManager {
	enum class Direction { north = 1, east = 2, south = 3, west = 4 };
	std::vector<Direction> directions;
	bool isExploring;

public:
	void Explore();

	ExplorationManager();

	void InitializeDirections();
};
