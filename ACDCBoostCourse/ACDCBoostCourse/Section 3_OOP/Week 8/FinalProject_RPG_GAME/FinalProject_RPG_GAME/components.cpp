#include "components.h"

class User {
public:
	static bool const isBurning = 0; // �����̺�Ʈ����

	User(string name, int level, int money, int luck) {
		this->name = name;
		this->level = level;
		this->money = money;
		this->luck = luck;
	}

	virtual void attck() {} // ����

	void defend() { // ���
		cout << GetName() << " : ���" << endl;
	}

	string GetName() const { return name; }
	int GetLevel() { return level; }
	int Getmoney() { return money; }
	int GetLuck() { return luck; }
	//bool GetIsBurning() { return isBurning; }


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


class Warrior : public User { // ����
public:
	Warrior(string name, int level, int money, int luck)
		: User(name, level, money, luck) {}

	void attack() { // ����
		cout << GetName() << " : �� �ֵθ���" << endl;
	}

	void combinate() { // ������ ����

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

	void combinate() { // ������ ����

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

	void combinate() { // ������ ����

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
		// rand �Լ��� luck ���� ���� ��
		//if ("����") {

		//}
		//return 0;
	//}

	string GetName() const { return name; }
	int GetPerformance() const { return performance; }

private:
	string name; // �̸�
	int performance; // ����
};

class Manager {
public:
	Manager(string name) {
		this->name = name;
	}

	void openBurningEvent(User Burning) {
		const bool isBurning = true;
		cout << "���� �̺�Ʈ ����" << endl;
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
