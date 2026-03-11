#pragma once
#include <string>
#include "monster.h"
using namespace std;

class Slime : public Monster {
public:
	Slime(string name);
	int playerHeal(Player* player, int heal);

	void attack(Player* player) override;
	void specialattack(Player* player);
	
};