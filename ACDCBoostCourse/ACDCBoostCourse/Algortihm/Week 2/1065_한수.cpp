#include <iostream>
using namespace std;

int main() {
	int num;
	int a, b, c;
	int count = 99;

	cin >> num;

	if (num < 100) {
		cout << num;
	}

	else {
		for (int i = 100; i <= num; i++) {
			a = i / 100;
			b = (i / 10) % 10;
			c = i % 10;

			if ((a - b) == (b - c)) {
				count++;
			}
		}
		cout << count;
	}
}