#include "../header/ManagerHeaders/ExplorationManager.h"

ExplorationManager::ExplorationManager() : directions({Direction::north, Direction::east, Direction::south, Direction::west}), isExploring(true) {}

void ExplorationManager::InitializeDirections() {
	directions = {Direction::north, Direction::east, Direction::south, Direction::west};
}

void ExplorationManager::Explore() {
	if (isExploring) {
		for (const Direction& dir : directions) {
			std::cout << "\033[K\r" << static_cast<int>(dir) << "\n";
		}
		std::cout << std::endl;
	}
	isExploring = false;
}
