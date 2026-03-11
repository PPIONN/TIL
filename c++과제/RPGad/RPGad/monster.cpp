#include <iostream>
#include <string>
#include"monster.h"
#include <thread>
#include <chrono>

using namespace std;
Monster::Monster() {};

Monster::Monster(string name) {
     setName(name);
}

void Monster::printMonsterStatus() {
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << getName() << endl;
    cout << "체력: " << getHP() << endl;
    cout << "카르마 수치 : 절대 악" << endl;
    cout << "------------------------------------" << endl;
 
};

void Monster::fail() {
    this_thread::sleep_for(chrono::seconds(3));
    cout << getName() << "은 쓰러졌다. 공허한 두 눈은 초점을 잃어 하늘을 향해 바라볼 뿐이다." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "당신은 " << getName() << "을 쓰러뜨렸다!" << endl;
    this_thread::sleep_for(chrono::seconds(7));
}