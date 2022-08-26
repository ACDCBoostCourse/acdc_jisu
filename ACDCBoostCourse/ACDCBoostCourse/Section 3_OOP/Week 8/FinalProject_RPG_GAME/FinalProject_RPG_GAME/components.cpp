#include "components.h"

class User {
public:
	static bool const isBurning = 0; // 버닝이벤트유무

	User(string name, int level, int money, int luck) {
		this->name = name;
		this->level = level;
		this->money = money;
		this->luck = luck;
	}

	virtual void attck() {} // 공격

	void defend() { // 방어
		cout << GetName() << " : 방어" << endl;
	}

	string GetName() const { return name; }
	int GetLevel() { return level; }
	int Getmoney() { return money; }
	int GetLuck() { return luck; }
	//bool GetIsBurning() { return isBurning; }


	friend class Item;
	friend class Manager;

	//Item combinate(Item a, Item b) {


	//} // 아이템 조함

	static Item Sum();


private:

	string name; // 이름
	int level; // 레벨
	int money; // 소지금
	int luck; // 운(0~50)

};


class Warrior : public User { // 전사
public:
	Warrior(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() { // 공격
		cout << GetName() << " : 검 휘두르기" << endl;
	}

	void combinate() { // 아이템 조합

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

	void combinate() { // 아이템 조합

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

	void combinate() { // 아이템 조합

	}

private:

};

class Item {
public:
	Item(string name, int performance) {
		this->name = name;
		this->performance = performance;
	}

	//Item operator+(const Item rhs) const {
		// rand 함수로 luck 관련 구현 후
		//if ("성공") {

		//}
		//return 0;
	//}

	string GetName() const { return name; }
	int GetPerformance() const { return performance; }

private:
	string name; // 이름
	int performance; // 성능
};

class Manager {
public:
	Manager(string name) {
		this->name = name;
	}

	void openBurningEvent(User Burning) {
		const bool isBurning = true;
		cout << "버닝 이벤트 적용" << endl;
		if (Burning.luck <= 90) {
			Burning.luck += 10;
		}
		else if (Burning.luck > 90) {
			Burning.luck = 100;
		}

	}
	void closeBurningEvent(User Burning) {
		//Burning.isBurning = false;
	}

private:
	string name;
};
