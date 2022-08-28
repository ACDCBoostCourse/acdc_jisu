#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Item {
public:
	Item(string itemName, int performance) {
		this->itemName = itemName;
		this->performance = performance;
	}

	Item operator+(Item& item) const { // 조합 성공했을 때 
		int newPerformance = item.GetPerformance() + GetPerformance();

		return Item("조합 성공 아이템", newPerformance);
	}

	int GetPerformance() const { return performance; }

private:
	string itemName; // 아이템 이름
	int performance; // 성능
};

class User {
public:
	friend class Item;
	friend class Manager;

	User(string name, int level, int money, int luck) {
		this->name = name;
		this->level = level;
		this->money = money;
		this->luck = luck;
	}

	// virtual void attck() {} // 공격

	void defend() { // 방어
		cout << GetName() << " : 방어" << endl;
	}

	Item combinate(Item a, Item b) { // 아이템 조합
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

	string GetName() const { return name; }

private:
	static bool isBurning; // 버닝이벤트유무
	string name; // 이름
	int level; // 레벨
	int money; // 소지금
	int luck; // 운(0~50)

};

bool User::isBurning = false;

class Warrior : public User { // 전사
public:
	Warrior(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() { // 공격
		cout << GetName() << " : 검 휘두르기" << endl;
	}

private:

};

class Magician : public User { // 마법사
public:
	Magician(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() { // 공격
		cout << GetName() << " : 마법 쏘기" << endl;
	}

private:

};

class Archer : public User { // 궁수
public:
	Archer(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() { // 공격
		cout << GetName() << " : 활 쏘기" << endl;
	}

private:

};

class Manager {

public:
	Manager(string name) {
		this->name = name;
	}

	void openBurningEvent() {
		User::isBurning = true;
	}

	void closeBurningEvent() {
		User::isBurning = false;
		cout << "버닝 이벤트 종료" << endl;
	}

private:
	string name;
};

int main() {

	Warrior Warrior("전사", 20, 1000, 0);
	Magician Magician("마법사", 15, 5600, 55);
	Archer Archer("궁수", 35, 3500, 12);

	Manager Manager("관리자");

	Item warriorItem1("전사아이템1", 32);
	Item warriorItem2("전사아이템2", 28);

	Item magicianItem1("마법사아이템1", 58);
	Item magicianItem2("마법사아이템2", 15);

	Item archerItem1("궁수아이템1", 44);
	Item archerItem2("궁수아이템2", 23);

	Warrior.attack();
	Warrior.defend();
	Magician.attack();
	Magician.defend();
	Archer.attack();
	Archer.defend();

	cout << endl;

	cout << Warrior.combinate(warriorItem1, warriorItem2).GetPerformance() << endl;

	Manager.openBurningEvent();

	cout << Magician.combinate(magicianItem1, magicianItem2).GetPerformance() << endl;

	Manager.closeBurningEvent();

	cout << Archer.combinate(archerItem1, archerItem2).GetPerformance() << endl;

}