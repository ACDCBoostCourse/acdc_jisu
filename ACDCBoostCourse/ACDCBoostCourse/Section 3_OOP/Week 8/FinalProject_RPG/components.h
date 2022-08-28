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
	string itemName; // ������ �̸�
	int performance; // ����
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
	static bool isBurning; // �����̺�Ʈ����
	string name; // �̸�
	int level; // ����
	int money; // ������
	int luck; // ��(0~50)
};

class Warrior : public User { // ����
public:
	Warrior(string name, int level, int money, int luck)
		: User(name, level, money, luck) {};

	void attack();
};

class Magician : public User { // ������
public:
	Magician(string name, int level, int money, int luck)
		: User(name, level, money, luck) {};

	void attack();
};

class Archer : public User { // �ü�
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