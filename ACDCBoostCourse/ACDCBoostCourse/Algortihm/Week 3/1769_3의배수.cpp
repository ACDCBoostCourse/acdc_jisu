#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main() {
	// 0~9 -> 48~57
	char input[1000001]; //0 ~ 1,000,000 자리 입력
	cin >> input;

	int count = 0;

	while (strlen(input) > 1) {
		int sum = 0;
		for (int i = 0; i < strlen(input); i++) { // 각 자리 합 구하기
			sum = sum + input[i] - 48;
		}
		count++;
		sprintf(input, "%d", sum); //int를 char 배열로 변환?
	}
	
	if (stoi(input) % 3 == 0) {
		cout << count << endl << "YES";
	}
	else {
		cout << count << endl << "NO";
	}
}