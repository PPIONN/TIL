#include <iostream>
#include <string>
#include"player.h"
#include <thread>
#include <chrono>

using namespace std;
Player::Player() {};

Player::Player(string nickname) {
    setNickname(nickname);
}

void Player::printPlayerStatus() {
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "* 현재 능력치" << endl;
    cout << "닉네임: " << getNickname() << endl;
    cout << "직업: " << getJobName() << endl;
    cout << "Lv. " << getLevel() << endl;
    cout << "HP: " << getHP() << endl;
    cout << "MP: " << getMP() << endl;
    cout << "공격력: " << getPower() << endl;
    cout << "방어력: " << getDefence() << endl;
    cout << "정확도: " << getAccuracy() << endl;
    cout << "속도: " << getSpeed() << endl;
    cout << "------------------------------------" << endl;
};
void Player::printFightStatus() {
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << getNickname() << endl;
    cout << "Lv. " << getLevel() << endl;
    cout << "HP: " << getHP() << endl;
    cout << "MP: " << getMP() << endl;
    cout << "------------------------------------" << endl;
};
void Player::win() {
    cout << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "... ... ..." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "... ... ..." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "\"당신은 마을의 평화를 지켜냈다. 설령 쓰러뜨린 상대가 악한 존재가 아니였을지라도, 그것을 판단할 눈썰미도, 경험도 부족하다. 옳은 선택을 했다.\"" << endl;
    this_thread::sleep_for(chrono::seconds(7));
    cout << "마을 사람들은 악한 존재가 사라짐을 느껴 용사의 위엄을 칭송하고 화자하였다." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "하늘에 떠있는 용사의 별이 반짝하고 빛났다." << endl;
    this_thread::sleep_for(chrono::seconds(5));
};
void Player::fail() {
    cout << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "... ... ..." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "... ... ..." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "\"당신은 용사가 아니다. 당신에겐 자격이 없다. 전 세계의 모든 인류는 당신에게 실망할것이고 나 또한 당신의 선택에 큰 실망감을 가졌다.\"" << endl;
    this_thread::sleep_for(chrono::seconds(7));
    cout << "당신을 향해 세계의 모든 인류는 비난과 힐난을 보낸다." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "세계는 멸망했다.더 이상 평화의 잔재는 세계에 남아있지 않다. 영웅의 별이 추락했다." << endl;
    this_thread::sleep_for(chrono::seconds(5));
}
