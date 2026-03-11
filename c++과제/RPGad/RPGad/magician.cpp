#include <iostream>
#include <string>
#include "monster.h"
#include"magician.h"
#include <thread>
#include <chrono>
using namespace std;

Magician::Magician(string nickname) {
    setNickname(nickname);
    setJobjname("법사");
    setLevel(1);
    setHP(50);
    setMP(100);
    setPower(15);
    setDefence(5);
    setAccuracy(10);
    setSpeed(10);
};
void Magician::attack() {
    cout << "당신은 전신에 흐르는 에너지를 한대 모아 적을 향해 날렸다!" << endl;
}
void Magician::attack(Monster* monster) {
    cout << endl;
    attack();
    this_thread::sleep_for(chrono::seconds(3));
    monster->setHP(monster->getHP() - realPower(getPower(), monster->getDefence()));
    cout << "\"!!!!!\"" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "상대방은 쏟아지는 에너지의 파동때문에 전신으로 흐르는 격한 통증을 느끼며 몸부림 치고있다!" << endl;
    this_thread::sleep_for(chrono::seconds(3));

};
