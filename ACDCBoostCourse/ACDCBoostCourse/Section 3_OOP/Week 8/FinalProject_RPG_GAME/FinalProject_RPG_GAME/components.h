#include <iostream>
// �����Լ��� ����...
#include <cstdlib>
#include <ctime>

using namespace std;

class User {
public:
	
	User(string name, int level, int money, int luck) {
	}

	virtual void attck() {} // ����

	void defend() { 
	}

	string GetName();
	int GetLevel();
	int Getmoney();
	int GetLuck();

	friend class Item;
	friend class Manager;

	//Item combinate(Item a, Item b) {


	//} // ������ ����

	static Item Sum();


private:
	string name; // �̸�
	int level; // ����
	int money; // ������
	int luck; // ��(0~50)
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

class Archer : public User { // �ü�
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
	string name; // �̸�
	int performance; // ����
};

class Manager {
public:
	Manager(string name) {}
	void openBurningEvent(User Burning) {}
	void closeBurningEvent(User Burning) {}

private:
	string name;
};
