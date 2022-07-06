#include <iostream>
using namespace std;

int main() {
	int num[10] = { 0 };
	int a, b, c;
	int mul;
	int result;

	cin >> a >> b >> c;
	mul = a * b * c;

	for (int i = 0; i < 10; i++) {
		result = mul % 10;
		num[result]++;
		mul = mul/10;

		if (mul == 0) {
			break;
		}
	}
	
	for (int i = 0; i < 10; i++) { // 출력
		cout << num[i] << endl;
	}
}