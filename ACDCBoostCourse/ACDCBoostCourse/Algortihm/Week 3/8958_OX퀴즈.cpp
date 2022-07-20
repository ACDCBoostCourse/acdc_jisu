#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int num;
	cin >> num;

	string OX;
	char input;

	for (int i = 0; i < num; i++) {
		cin >> OX;
		int sum = 0;
		int point = 0;
		int length = OX.length();
		
		for (int j = 0; j < length; j++) {
			input = OX[j];
			if (input == 'O') {
				++point;
			}
			else if (input == 'X') {
				point = 0;
			}
			sum = sum + point;
		}
		cout << sum << endl;
	}
}