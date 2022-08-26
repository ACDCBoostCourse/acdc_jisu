#include "components.h"

int main() {
	
	Warrior Warrior("전사", 20, 1000, 20);
	Magician Magician("마법사", 15, 5600, 55);
	Archer Archer("궁수", 35, 3500, 33);

	Manager Manager("관리자");

	// 아이템 인스턴스

	Warrior.attack();
	Magician.attack();
	Archer.attack();
	Warrior.defend();
	Magician.defend();
	Archer.defend();

	// Warrior 아이템 조합

	Manager.openBurningEvent(Warrior);
	Manager.openBurningEvent(Magician);
	Manager.openBurningEvent(Archer);

	// Magician 아이템 조합

	Manager.closeBurningEvent(Warrior);
	Manager.closeBurningEvent(Magician);
	Manager.closeBurningEvent(Archer);
	
	// Archer 아이템 조합
}
