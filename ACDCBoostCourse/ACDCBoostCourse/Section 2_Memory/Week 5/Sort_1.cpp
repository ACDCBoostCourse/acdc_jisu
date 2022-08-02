/*
* void sort(int *arr, bool isAscending)
1. ù ��° ���� arr���� ������ �����ϰ��� �ϴ� �迭�� �������ݴϴ�.
2. �� ��° ���� isAscending ���� ������ ������������ �� ��� true, ������������ �� ��� false�� �����մϴ�.
3. ���� ������ �̿��Ͽ� arr �迭�� �������� �Ǵ� ������������ �������ִ� �Լ��� �����մϴ�.
*/
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void sort(int* arr, bool isAscending) {
	int index = 0;
	if (isAscending == true) {
		for (int i = 0; i < 4; i++) {
			index = i;
			for (int j = i + 1; j < 4; j++) {
				if (arr[index] > arr[j]) {
					index = j;
				}
			}
			swap(arr[index], arr[i]);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			index = i;
			for (int j = i + 1; j < 4; j++) {
				if (arr[index] < arr[j]) {
					index = j;
				}
			}
			swap(arr[index], arr[i]);
		}
	}
}

int main() {
	int items[4] = { 1,5,3,2 };
	sort(items, true);

	for (int item : items) {
		cout << item << ' ';  // 1 2 3 5
	}

	cout << endl;
	sort(items, false);

	for (int item : items) {
		cout << item << ' ';  // 5 3 2 1
	}
}
