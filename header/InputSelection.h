#pragma once
#include "includes.h"

class InputSelection{
public:
    static void HandleInputSelection(int command);

private:
    static void ExplorationLoop();
    static void StealingLoop();
};