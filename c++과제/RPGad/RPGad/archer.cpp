#include <iostream>
#include <string>
#include"archer.h"
#include"monster.h"
#include <thread>
#include <chrono>
using namespace std;

Archer::Archer(string nickname) {
    setNickname(nickname);
    setJobjname("궁수");
    setLevel(1);
    setHP(50);
    setMP(50);
    setPower(15);
    setDefence(10);
    setAccuracy(10);
    setSpeed(10);
};
void Archer::attack(){
    cout << getNickname() << "은 활 시위를 당겨 적의 목을 노렸다!" << endl;
}
void Archer::attack(Monster* monster) {
    cout << endl;
    setPower(getPower() - monster->getDefence());
    if (getPower() <= 0) {
        setPower(1);
    }
    attack();
    this_thread::sleep_for(chrono::seconds(3));

    for (int i = 0; i < 3; i++) {
        monster->setHP(monster->getHP() - realPower(getPower(), monster->getDefence()) / 3);
        cout << "상대방에게 " << (realPower(getPower(), monster->getDefence()) / 3) << "의 피해를 입혔다 !" << endl;
    }
    this_thread::sleep_for(chrono::seconds(3));
    cout << "\"!!!!!\"" << endl;
    cout << "당신의 활을 맞은 상대는 몸이 관통당해 찾아온 맹렬한 고통에 못이겨 몸부림 치고있다!" << endl;
    this_thread::sleep_for(chrono::seconds(3));

};
// 플레이어의 공격력-몬스터의 방어력을 계산하여 데미지로 정의합니다.
       // 계산된 데미지가 0 이하일 경우, 데미지를 1로 정의합니다.

       // 공격 문장을 출력합니다.
       // - 전사, 마법사: 계산된 데미지로 1회 공격
       // - 궁수: 계산된 데미지/3으로 3회 공격 (소수점 생략)
       // - 도적: 계산된 데미지/5으로 5회 공격 (소수점 생략)
       // - 궁수와 도적의 경우, 3과 5로 나눈 결과가 0이라면 1로 정의합니다.
       // ex) * 슬라임에게 화살로 3의 피해를 입혔다! 3번 출력

       // 몬스터의 setHP를 호출하여 몬스터의 HP-데미지를 계산한 값을 매개변수로 전달합니다.
       // 몬스터의 getHP를 호출 분기문이 실행됩니다.
       // 몬스터가 생존했을 경우 몬스터의 남은 HP 출력
       // 몬스터가 생존하지 못했을 경우 플레이어의 승리 문구 출력