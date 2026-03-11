#include <iostream>
#include <string>
#include "thief.h"
#include "monster.h"
#include <thread>
#include <chrono>
using namespace std;

Thief::Thief(string nickname)  {
    setNickname(nickname);
    setJobjname("도적");
    setLevel(1);
    setHP(50);
    setMP(50);
    setPower(15);
    setDefence(10);
    setAccuracy(10);
    setSpeed(10);
};
void Thief::attack() {
    cout << getNickname() << "은 적의 품으로 들어가 손에 쥔 단검을 깊게 쑤셔넣고 손목을 최대한 비틀어 돌렸다!" << endl;
}
void Thief::attack(Monster* monster) {
    cout << endl;
    attack();
    //setPower(getPower() - monster->getDefence());
    this_thread::sleep_for(chrono::seconds(2));
    for (int i = 0; i < 5; i++) {
        monster->setHP(monster->getHP() - realPower(getPower(), monster->getDefence()) / 5);
        cout << "상대방에게 " << (realPower(getPower(), monster->getDefence()) / 5) << "의 피해를 입혔다 !" << endl;
    }
    this_thread::sleep_for(chrono::seconds(2));
    cout << "\"!!!!!\"" << endl;
    cout << "상대방은 신경이 뒤틀리는 아찔한 통증에 동공이 크게 떨리고 식은땀을 흘리며 몸부림 치기 시작했다!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
};
