#pragma once
#include "includes.h"

class Terminal {
    std::vector<std::string> commands;

public:
    static void animate(int duration);
    static void initializeHub();
    static void drawOptions();
};

