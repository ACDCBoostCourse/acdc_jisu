#include "components.h"

bool User::isBurning = false;

Item::Item(string itemName, int performance) {
	this->itemName = itemName;
	this->performance = performance;
}
int Item::GetPerformance() { return performance; }

Item Item::operator+(Item& item) { // 조합 성공했을 때 
	int newPerformance = item.GetPerformance() + GetPerformance();

	return Item("조합 성공 아이템", newPerformance);
}


User::User(string name, int level, int money, int luck) {
	this->name = name;
	this->level = level;
	this->money = money;
	this->luck = luck;
}

void User::defend() { // 방어
	cout << GetName() << " : 방어" << endl;
}

Item User::combinate(Item a, Item b) { // 아이템 조합
	int realLuck;
	srand((unsigned int)time(NULL));

	if (isBurning) {
		realLuck = 60 + luck;
		cout << "버닝 이벤트 적용" << endl;
	}
	else {
		realLuck = 50 + luck;
	}

	if (realLuck > 100) realLuck = 100;

	if (rand() % 100 + 1 <= realLuck) {
		cout << "조합 성공!" << endl;
		return a + b;
	}
	else {
		cout << "조합 실패!" << endl;
		return Item("조합 실패 아이템", 0);
	}
}

string User::GetName() { return name; }


void Warrior::attack() { // 공격
	cout << GetName() << " : 검 휘두르기" << endl;
}

void Magician::attack() { // 공격
	cout << GetName() << " : 마법 쏘기" << endl;
}

void Archer::attack() { // 공격
	cout << GetName() << " : 활 쏘기" << endl;
}

Manager::Manager(string name) {
	this->name = name;
}

void Manager::openBurningEvent() {
	User::isBurning = true;
}

void Manager::closeBurningEvent() {
	User::isBurning = false;
	cout << "버닝 이벤트 종료" << endl;
}