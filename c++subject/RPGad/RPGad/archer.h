#pragma once
#include <string>
#include "player.h"
using namespace std;

class Archer : public Player {
public:
    Archer(string nickname);
    void attack() override;
    void attack(Monster* monster) override;
};