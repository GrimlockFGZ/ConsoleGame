// Handles combat interactions
#include "../../header/includes.h"
#include "../../header/Player.h"
#include "../../header/CombatManager.h"

bool inCombat;
void CombatManager::CombatLoop() {
	inCombat = true;
	std::cout << "Starting Combat\n";

	while(inCombat) {
		if(!Player::playerAlive) {
			inCombat = false;
		} else {
			std::cout<< "your health is:"; Player::getHealth();
			// Add combat logic here
			std::cout << "\nRun away?(y/n)";

			// Add user input to continue or stop combat
			char choice;
			std::cin >> choice;
			if(choice == 'y' || choice == 'Y') {
				inCombat = false;
			}
		}
	}
}
