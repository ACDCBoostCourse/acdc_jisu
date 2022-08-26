#include "components.h"

int main() {
	
	Warrior Warrior("����", 20, 1000, 20);
	Magician Magician("������", 15, 5600, 55);
	Archer Archer("�ü�", 35, 3500, 33);

	Manager Manager("������");

	// ������ �ν��Ͻ�

	Warrior.attack();
	Magician.attack();
	Archer.attack();
	Warrior.defend();
	Magician.defend();
	Archer.defend();

	// Warrior ������ ����

	Manager.openBurningEvent(Warrior);
	Manager.openBurningEvent(Magician);
	Manager.openBurningEvent(Archer);

	// Magician ������ ����

	Manager.closeBurningEvent(Warrior);
	Manager.closeBurningEvent(Magician);
	Manager.closeBurningEvent(Archer);
	
	// Archer ������ ����
}
