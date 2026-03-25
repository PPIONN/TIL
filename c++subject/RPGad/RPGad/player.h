#pragma once
#include <string>
using namespace std;

class Monster;

class Player {
public:
    Player();
    Player(string nickname);
    virtual ~Player() { 
       // cout << getNickname()<<"소멸자" << endl; 
    };
    virtual void attack() = 0;
    virtual void attack(Monster* monster) = 0;
    void printPlayerStatus();
    void printFightStatus();
    void win();
    void fail();
    // getter 함수
    string getJobName() { return job_name; };
    string getNickname() { return nickname; };
    int getLevel() { return level; };
    int getHP() { return HP; };
    int getMP() { return MP; };
    int getPower() { return power; };
    int getDefence() { return defence; };
    int getAccuracy() { return accuracy; };
    int getSpeed() { return speed; };
    int realPower(int a, int b) { 
        if (a - b <= 0) {
            return 1;
        }
        return a - b; 
    };

    // setter 함수
    void setNickname(string nickname) { this->nickname = nickname; };
    void setJobjname(string Jobname) { job_name = Jobname; };
    void setLevel(int level) { this->level = level; };
    void setHP(int HP) { this->HP = HP; };
    void setMP(int MP) { this->MP = MP; };
    void setPower(int power) { this->power = power; };
    void setDefence(int defence) { this->defence = defence; };
    void setAccuracy(int accuracy) { this->accuracy = accuracy; };
    void setSpeed(int speed) { this->speed = speed; };

protected:
    string job_name;
    string nickname;
    int level;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;
};
