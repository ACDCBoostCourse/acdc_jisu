#include <iostream>
using namespace std;

int main() {
	int FirstTeam[9];
	int SecondTeam[9];

	for (int i = 0; i < 9; i++) { //�︲ ���̴Ͻ� ����
		cin >> FirstTeam[i];
	}

	for (int i = 0; i < 9; i++) { //��ŸƮ��ũ �ɸ����� ����
		cin >> SecondTeam[i];
	}
	int SumFirst = 0;
	int SumSecond = 0;

	for (int i = 0; i < 9; i++) {
		SumFirst = SumFirst + FirstTeam[i];
		if (SumFirst > SumSecond) {
			cout << "Yes";
			return 0;
		}
		SumSecond = SumSecond + SecondTeam[i];
	}
	cout << "No";
	return 0;
}