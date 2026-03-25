#pragma once
#include <string>
using namespace std;


class Player;

class Monster {
public:
    Monster();
    Monster(string name);
    ~Monster() { 
        //cout << getName() << "소멸자" << endl;
    };
    virtual void attack(Player* player) = 0;
    void printMonsterStatus();
    void fail();
    void setName(string name) { this->name = name; };
    void setHP(int HP) { this->HP = HP; };
    void setPower(int power) { this->power = power; };
    void setDefence(int defence) { this->defence = defence; };
    void setSpeed(int speed) { this->speed = speed; };

    string getName() { return name; };
    int getHP() { return HP; };
    int getPower() { return power; };
    int getDefence() { return defence; };
    int getSpeed() { return speed; };

protected:
    string name;
    int HP;
    int power;
    int defence;
    int speed;


};

//이름(`name`), HP(10), 공격력(30), 방어력(10), 스피드(10)를 속성으로 가집니다.
	//- 생성자에서 이름을 입력받고, 모든 능력치를 기본값으로 초기화하세요.