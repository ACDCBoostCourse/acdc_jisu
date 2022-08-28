#include "components.h"

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