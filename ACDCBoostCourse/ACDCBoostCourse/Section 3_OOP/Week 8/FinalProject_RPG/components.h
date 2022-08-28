#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Item {
public:
	Item(string itemName, int performance);

	Item operator+(Item& item);

	int GetPerformance();

private:
	string itemName; // 아이템 이름
	int performance; // 성능
};

class User {
public:
	friend class Item;
	friend class Manager;

	User(string name, int level, int money, int luck);

	void defend();

	Item combinate(Item a, Item b);

	string GetName();

private:
	static bool isBurning; // 버닝이벤트유무
	string name; // 이름
	int level; // 레벨
	int money; // 소지금
	int luck; // 운(0~50)
};

class Warrior : public User { // 전사
public:
	Warrior(string name, int level, int money, int luck)
		: User(name, level, money, luck) {};

	void attack();
};

class Magician : public User { // 마법사
public:
	Magician(string name, int level, int money, int luck)
		: User(name, level, money, luck) {};

	void attack();
};

class Archer : public User { // 궁수
public:
	Archer(string name, int level, int money, int luck)
		: User(name, level, money, luck) {};

	void attack();
};

class Manager {

public:
	Manager(string name);

	void openBurningEvent();

	void closeBurningEvent();

private:
	string name;
};