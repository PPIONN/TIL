#pragma once
#include <string>
#include "player.h"
using namespace std;

class Warrior : public Player {
public:
    Warrior(string nickname);
    void attack() override;
    void attack(Monster* monster) override;
};