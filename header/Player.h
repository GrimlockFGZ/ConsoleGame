#pragma once

class Player {

	static float health;
	static float armor;

public:
	static float getHealth();
	static bool playerAlive;

	int Strength;
	int Perception;
	int Endurance;
	int Charisma;
	int Intelligence;
	int Agility;
	int Luck;

};
