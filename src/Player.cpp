#include "../header/Player.h"

bool Player::playerAlive = getHealth() > 0;
float Player::armor =2.5f;
float Player::health =5.0f;

float Player::getHealth() {
	const float fullHealth = armor*100/health;
	return fullHealth;
}


