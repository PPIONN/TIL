#include <iostream>
#include <string>
#include "warrior.h"
#include "monster.h"
#include <thread>
#include <chrono>
using namespace std;

Warrior::Warrior(string nickname){
    setNickname(nickname);
    setJobjname("전사");
    setLevel(1);
    setHP(100);
    setMP(50);
    setPower(15);
    setDefence(10);
    setAccuracy(10);
    setSpeed(10);
};
void Warrior::attack() {
    cout << getNickname() << "은 손에 쥔 검을 하늘을 향해 들어올려 온 힘을 다해 내리쳤다!" << endl;
}
void Warrior::attack(Monster* monster) {
    cout << endl;
    attack();
    this_thread::sleep_for(chrono::seconds(2));
    monster->setHP(monster->getHP() - realPower(getPower(), monster->getDefence()));
    this_thread::sleep_for(chrono::seconds(2));
    cout << "상대방은 절단된 자신의 몸을 보며 믿을 수 없다는듯 비명을 지르며 몸부림치기 시작했다!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
};
