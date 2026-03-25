#pragma once
#include <string>
#include "player.h"
using namespace std;

class Thief : public Player {
public:
    Thief(string nickname);
    void attack() override;
    void attack(Monster* monster) override;
};