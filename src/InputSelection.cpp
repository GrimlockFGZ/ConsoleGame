#include "../header/inputselection.h"
#include "../header/terminal.h"
#include "../header/ManagerHeaders/OptionsManager.h"
#include "../header/ManagerHeaders/CombatManager.h"
#include "../header/ManagerHeaders/ExplorationManager.h"
#include "../header/ManagerHeaders/LootingManager.h"

InputSelection::InputSelection() = default;

// ReSharper disable once CppMemberFunctionMayBeStatic
void InputSelection::HandleInputSelection(const int command) {
    switch(command) {
        default: return;
        case 1: ExplorationManager().Explore(); break;
        case 2: CombatManager().CombatLoop(); break;
        case 3: LootingManager().Stealing(); break;
        case 4: Terminal().drawOptions(); break;
        case 5: OptionsManager().DrawSettings(); break;
    }
}
