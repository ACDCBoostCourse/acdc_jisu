#include "components.h"

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