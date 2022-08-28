#include "components.h"

bool User::isBurning = false;

Item::Item(string itemName, int performance) {
	this->itemName = itemName;
	this->performance = performance;
}
int Item::GetPerformance() { return performance; }

Item Item::operator+(Item& item) { // ���� �������� �� 
	int newPerformance = item.GetPerformance() + GetPerformance();

	return Item("���� ���� ������", newPerformance);
}


User::User(string name, int level, int money, int luck) {
	this->name = name;
	this->level = level;
	this->money = money;
	this->luck = luck;
}

void User::defend() { // ���
	cout << GetName() << " : ���" << endl;
}

Item User::combinate(Item a, Item b) { // ������ ����
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

string User::GetName() { return name; }


void Warrior::attack() { // ����
	cout << GetName() << " : �� �ֵθ���" << endl;
}

void Magician::attack() { // ����
	cout << GetName() << " : ���� ���" << endl;
}

void Archer::attack() { // ����
	cout << GetName() << " : Ȱ ���" << endl;
}

Manager::Manager(string name) {
	this->name = name;
}

void Manager::openBurningEvent() {
	User::isBurning = true;
}

void Manager::closeBurningEvent() {
	User::isBurning = false;
	cout << "���� �̺�Ʈ ����" << endl;
}