#include <iostream>
#include <string>
#include"slime.h"
#include"player.h"
#include <thread>
#include <chrono>
using namespace std;


Slime::Slime(string name){
	//HP(10), 공격력(30), 방어력(10), 스피드(10)
    setName(name);
    setHP(10);
    setPower(30);
    setDefence(10);
    setSpeed(10);
}
int Slime::playerHeal(Player* player, int heal) {
    player->setHP(player->getHP() + heal);
    return player->getHP();
}
void Slime::attack(Player* player) {
    cout << endl;
    cout << "\"난 착한 슬라임이야! 널 해칠 생각은 없어! 너도 공격하지 말아줘! 제발!\"" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "착한 슬라임은 " << player->getNickname() << "의 상처를 치료해줬다!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << player->getNickname() << "의 HP : " << playerHeal(player, getPower()) << " 로 상승했다!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
}
void  Slime::specialattack(Player* player) {
    cout << endl;
    cout << "\"꼴에 온정이라도 느꼇나보지? 너같은 인간이 용사라니... 세계도 멸망할때가 왔군.\"" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "\"죽어라! 멍청하고 오만한 용사!!! 공격을 포기한 자에게 죽음을 내리는 마법 !!!\"" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    player->setHP(player->getHP() - player->getHP());
    this_thread::sleep_for(chrono::seconds(5));
    cout << player->getNickname() << "의 HP : " << player->getHP() << endl;

}