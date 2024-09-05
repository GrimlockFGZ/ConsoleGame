#include "../header/inputselection.h"
#include "../header/terminal.h"
#include "../header/OptionsManager.h"
#include "../header/CombatManager.h"
#include "../header/ExplorationManager.h"
#include "../header/LootingManager.h"

InputSelection::InputSelection() = default;

// ReSharper disable once CppMemberFunctionMayBeStatic
void InputSelection::HandleInputSelection(int command) {
    switch(command) {
        default: return;
        case 1: ExplorationManager().Explore(); break;
        case 2: CombatManager().CombatLoop(); break;
        case 3: LootingManager().Stealing(); break;
        case 4: Terminal().drawOptions(); break;
        case 5: OptionsManager().DrawSettings(); break;
    }
}
