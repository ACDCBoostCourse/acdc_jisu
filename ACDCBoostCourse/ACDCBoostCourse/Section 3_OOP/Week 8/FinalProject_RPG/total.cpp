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

	Item operator+(Item& item) const { // ���� �������� �� 
		int newPerformance = item.GetPerformance() + GetPerformance();

		return Item("���� ���� ������", newPerformance);
	}

	int GetPerformance() const { return performance; }

private:
	string itemName; // ������ �̸�
	int performance; // ����
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

	// virtual void attck() {} // ����

	void defend() { // ���
		cout << GetName() << " : ���" << endl;
	}

	Item combinate(Item a, Item b) { // ������ ����
		int realLuck;
		srand((unsigned int)time(NULL));

		if (isBurning) {
			realLuck = 60 + luck;
			cout << "���� �̺�Ʈ ����" << endl;
		}
		else {
			realLuck = 50 + luck;
		}

		if (realLuck > 100) realLuck = 100;

		if (rand() % 100 + 1 <= realLuck) {
			cout << "���� ����!" << endl;
			return a + b;
		}
		else {
			cout << "���� ����!" << endl;
			return Item("���� ���� ������", 0);
		}
	}

	string GetName() const { return name; }

private:
	static bool isBurning; // �����̺�Ʈ����
	string name; // �̸�
	int level; // ����
	int money; // ������
	int luck; // ��(0~50)

};

bool User::isBurning = false;

class Warrior : public User { // ����
public:
	Warrior(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() { // ����
		cout << GetName() << " : �� �ֵθ���" << endl;
	}

private:

};

class Magician : public User { // ������
public:
	Magician(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() { // ����
		cout << GetName() << " : ���� ���" << endl;
	}

private:

};

class Archer : public User { // �ü�
public:
	Archer(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() { // ����
		cout << GetName() << " : Ȱ ���" << endl;
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
		cout << "���� �̺�Ʈ ����" << endl;
	}

private:
	string name;
};

int main() {

	Warrior Warrior("����", 20, 1000, 0);
	Magician Magician("������", 15, 5600, 55);
	Archer Archer("�ü�", 35, 3500, 12);

	Manager Manager("������");

	Item warriorItem1("���������1", 32);
	Item warriorItem2("���������2", 28);

	Item magicianItem1("�����������1", 58);
	Item magicianItem2("�����������2", 15);

	Item archerItem1("�ü�������1", 44);
	Item archerItem2("�ü�������2", 23);

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