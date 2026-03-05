#include <iostream>
//#include <iomanip> // 소수점 출력 제한을 위함
//#include <string>
//#include <cstring>
//#include <algorithm>
//#include <vector>
using namespace std;



void bonusPotion(int* ph, int* mp) {
	int h = 0;
	int m = 0;
	if (*ph == 0 || *mp == 0) {
		cout << "포션을 몇개 씩 더 충전할까요?\n";
		cout << "Hp 포션 :"; cin >> h;
		cout << "Mp 포션 :"; cin >> m;
		*ph = *ph + h;
		*mp = *mp + m;
		cout << "충전이 완료 됐습니다.\n";
	}
}


void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	switch (count) {
	case 1:
		if (*p_HPPotion > 0) {
			*p_HPPotion = *p_HPPotion - 1;
		}
		else {
			cout << "포션 수를 충전할까요? 1. OK 2. NO\n";
			int i = 0;
			cin >> i;
			if (i == 1) {
				bonusPotion(p_HPPotion, p_MPPotion);
			}
			else {
				break;

			}
		}
		break;
	case 2:
		if (*p_MPPotion > 0) {
			*p_MPPotion = *p_MPPotion - 1;
		}
		else {
			cout << "포션 수가 부족합니다.\n";
			cout << "포션 수를 충전할까요? 1. OK 2. NO\n";
			int i = 0;
			cin >> i;
			if (i == 1) {
				bonusPotion(p_HPPotion, p_MPPotion);
			}
			else {
				break;

			}
		}
		break;
	case 6:
		*p_HPPotion = 5;
		*p_MPPotion = 5;
	}

};


int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	int status[5] = { 0, };
	status[4] = { 1 };

	while (1) {
		cout << "HP와 MP를 입력해주세요: ";
		cin >> status[0] >> status[1];
		if (status[0] > 50 && status[1] > 50) {
			break;
		}
		cout << "HP와 MP는 50 이하의 값을 입력 할 수 없습니다. 다시 입력해주세요.\n";
	}
	while (1) {
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> status[2] >> status[3];
		if (status[2] > 0 && status[3] > 0) {
			break;
		}
		cout << "공격력과 방어력은 0 이하의 값을 입력 할 수 없습니다. 다시 입력해주세요.\n";
	}

	int i = 0;
	int a = 0;
	int hp = 5;
	int mp = 5;

	setPotion(i, &hp, &mp);
	bonusPotion(&hp, &mp);
	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";
	cout << "=============================================\n";

	while (1) {
		cout << "<스탯 관리 시스템>\n";
		cout << "1. HP UP\n";
		cout << "2. MP UP\n";
		cout << "3. 공격력 UP\n";
		cout << "4. 방어력 UP\n";
		cout << "5. 현재 능력치\n";
		cout << "6. Level UP\n";
		cout << "7. 모험을 떠난다!\n";
		cout << "0. 나가기\n";
		cout << "번호를 선택해 주세요:";
		cin >> a;

		if (a == 0) {
			cout << "good bye";
			break;
		}
		switch (a) {
		case 1:
			if (hp == 0) {
				cout << "포션수가 부족합니다\n";
				setPotion(a, &hp, &mp);
				break;
			}
			setPotion(a, &hp, &mp);
			status[0] = status[0] + 20;
			cout << "HP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n";
			cout << "현재 남은 HP 포션 수 :" << hp << "\n";
			break;
		case 2:
			if (mp == 0) {
				cout << "포션수가 부족합니다\n";
				setPotion(a, &hp, &mp);
				break;
			}
			setPotion(a, &hp, &mp);
			status[1] = status[1] + 20;
			cout << "MP가 20 증가되었습니다.포션이 1개 차감됩니다.\n";
			cout << "현재 남은 MP 포션 수 :" << mp << "\n";
			break;
		case 3:
			status[2] = status[2] * 2;
			cout << "공격력이 2배로 증가되었습니다.\n";
			cout << "현재 공격력" << status[2];
			break;
		case 4:
			status[3] = status[3] * 2;
			cout << "방어력이 2배로 증가되었습니다.\n";
			cout << "현재 방어력" << status[3];
			break;

		case 5:
			cout << "HP : " << status[0] << " MP : " << status[1] << " 공격력 : " << status[2] << " 방어력 : " << status[3] << " 레벨 : " << status[4] << " 남은 HP / MP 포션 수 : " << hp << " / " << mp << "\n";
			break;

		case 6:
			cout << "레벨업! HP/MP 포션이 지급됩니다.\n";
			setPotion(a, &hp, &mp);
			++status[4];
			cout << "남은 HP/MP 포션 수 :" << hp << mp << "\n";
			break;
		case 7:
			cout << "당신은 모험을 떠났다!\n";
			cout << "날도 좋은데 산책이라도 다녀오심이 어떠실까요?\n";

			return 0;

		}


	}




	return 0;
}

