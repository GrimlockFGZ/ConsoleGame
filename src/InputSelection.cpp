#include "../header/inputselection.h"
#include "../header/terminal.h"
#include "../header/OptionsManager.h"
#include "../header/CombatManager.h"


bool exploring;
bool stealing;

void InputSelection::ExplorationLoop() { std::cout << "Exploring"; }

void InputSelection::StealingLoop() {
    std::cout << "Stealing things";
    //todo: implement this LootingManager::StealingLoop();
}

void InputSelection::HandleInputSelection(const int command) {
    switch(command) {
        default:return;
        case 1:ExplorationLoop();
            break;
        case 2:CombatManager::CombatLoop();
            break;
        case 3:StealingLoop();
            break;
        case 4:Terminal::drawOptions();
            break;
        case 5:OptionsManager::DrawSettings();
            break;
        case 6:;
    }
}
