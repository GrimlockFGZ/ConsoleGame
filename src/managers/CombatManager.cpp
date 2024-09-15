#include "../header/includes.h"
#include "../header/Player.h"
#include "../header/ManagerHeaders/CombatManager.h"

CombatManager::CombatManager() : inCombat(false) {}

void CombatManager::CombatLoop() {
	inCombat = true;
	std::cout << "Starting Combat\n";

	while(inCombat) {
		if(!Player::playerAlive) {
			inCombat = false;
		} else {
			std::cout << "Your health is:" << Player::getHealth();
			// Add combat logic here
			std::cout << "\nRun away?(y/n)";

			char choice;
			std::cin >> choice;
			if(choice == 'y' || choice == 'Y') {
				inCombat = false;
			}
		}
	}
}
