#include <iostream>
// 랜덤함수를 위해...
#include <cstdlib>
#include <ctime>

using namespace std;

class User {
public:
	
	User(string name, int level, int money, int luck) {
	}

	virtual void attck() {} // 공격

	void defend() { 
	}

	string GetName();
	int GetLevel();
	int Getmoney();
	int GetLuck();

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


class Warrior : public User {
public:
	Warrior(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() {}

	void combinate() {}

};

class Magician : public User { 
public:
	Magician(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() {}

	void combinate() {}

};

class Archer : public User { // 궁수
public:
	Archer(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() {}

	void combinate() {}

};

class Item {
public:
	Item(string name, int performance) {}
	string GetName();
	int GetPerformance();

private:
	string name; // 이름
	int performance; // 성능
};

class Manager {
public:
	Manager(string name) {}
	void openBurningEvent(User Burning) {}
	void closeBurningEvent(User Burning) {}

private:
	string name;
};
