#include <iostream>
using namespace std;

int main() {
	int FirstTeam[9];
	int SecondTeam[9];

	for (int i = 0; i < 9; i++) { //울림 제미니스 점수
		cin >> FirstTeam[i];
	}

	for (int i = 0; i < 9; i++) { //스타트링크 걸리버스 점수
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