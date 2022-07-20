#include <iostream>
#include <string>
using namespace std;

int main() {
	// 0~9 -> 48~57
	string input;
	cin >> input;

	int count = 0;

	while (1) {
		int length = input.length();
		int sum = 0;
		int num_input = stoi(input);

		if (num_input < 10) {
			if (num_input % 3 == 0) {
				cout << count << endl << "YES";
				break;
			}
			else {
				cout << count << endl << "NO";
				break;
			}
		}
		else {
			for (int i = 0; i < length; i++) { // 각 자리 합 구하기
				int number = input[i] - 48;
				sum = sum + number;
			}
			count++;
			input = to_string(sum);
			continue;
		}
	}
	return 0;
}