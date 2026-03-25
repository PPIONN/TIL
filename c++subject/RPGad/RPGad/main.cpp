#include <iostream>
#include <string>
#include "monster.h"
#include "slime.h"
#include "player.h"
#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"
#include <thread>
#include <chrono>

using namespace std;
int main() {
    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;
    Slime* slime = new Slime("착한 슬라임");

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << endl << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;

    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }
    cout << endl;
    cout << "선택: ";
    cin >> job_choice;

    switch (job_choice) {
    case 1:
        player = new Warrior(nickname);
        break;
    case 2:
        player = new Magician(nickname);
        break;
    case 3:
        player = new Thief(nickname);
        break;
    case 4:
        player = new Archer(nickname);
        break;
    default:
        cout << "잘못된 입력입니다." << endl;
        return 1;
    }

        //player->attack();
    player->printPlayerStatus();
    this_thread::sleep_for(chrono::seconds(1));
    cout << endl;
    cout << "당신은 힘에 걸맞는 책임을 가져야하고 걸맞는 행동을 해야 한다." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "최근 당신은 마을 주변에 몬스터가 한마리 나온다는 소문을 들었다. 필히 악한 존재일 터!" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "마을의 평화를 위해 반드시 쓰러뜨려야한다. 그러면 당신의 첫 명예로운 전투는 사람들의 축복과 찬양을 받을것이다." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "몬스터와의 전투 준비는 되셨습니까 ?" << endl << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "1. YES 2. NO" << endl;
    int fightcheck = 0;
    int fightcheck2 = 0;
    cin >> fightcheck;
    if (fightcheck == 1) {
    while (1) {
            player->printFightStatus();
            slime->printMonsterStatus();
            this_thread::sleep_for(chrono::seconds(3));
            if (fightcheck2 == 2) {
                slime->specialattack(player);
                player->fail();
                this_thread::sleep_for(chrono::seconds(3));
                break;
            }
            slime->attack(player);
            this_thread::sleep_for(chrono::seconds(3));
            if (player->getHP() <= 0) {
                player->fail();
                this_thread::sleep_for(chrono::seconds(3));
                break;
            }
            cout << endl << "공격 하시겠습니까?" << endl << endl;
            cout << "1. 공격한다 2. 공격하지 않는다" << endl;
            cin >> fightcheck2;
            if(fightcheck2 == 1){
                player->attack(slime);
                if (slime->getHP() <= 0) {
                    cout << endl;
                    slime->fail();
                    player->win();
                    break;
                }
            }
            else if (fightcheck2 > 2) {
                cout << "허튼 방식만 추구하는 외도 용사는 저희 세계에는 필요 없습니다. 세상은 장난으로 돌아가지 않습니다." << endl;
                break;
            }


        }
    }
    else if(fightcheck == 2){
        player->fail();
    }
    else {
        cout << "허튼 방식만 추구하는 외도 용사는 저희 세계에는 필요 없습니다.세상은 장난으로 돌아가지 않습니다." << endl;
    }

    if (player != nullptr)
        delete player;
    if (slime != nullptr)
        delete slime;
    return 0;
}

