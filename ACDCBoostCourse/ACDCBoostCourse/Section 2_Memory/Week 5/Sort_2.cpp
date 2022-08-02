/*
* int *sorted (int *arr, bool isAscending) 
1. ù ��° ���� arr���� ������ �����ϰ��� �ϴ� �迭�� �������ݴϴ�.
2. �� ��° ���� isAscending ���� ������ ������������ �� ��� true, ������������ �� ��� false�� �����մϴ�.
3. ���� ������ �̿��Ͽ� arr �迭�� �������� �Ǵ� ������������ �������ִ� �Լ��� �����մϴ�.

1�� �Լ��� ����� �����ϳ�, �̹��� arr�� �����ʹ� ������ ä��, ���ĵ� ���ο� �迭�� �����ϴ� �Լ� �� �������ּ���.
*/
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int* sorted(int* arr, bool isAscending) {
	int index = 0;
	int* newArr = new int[4];
	for (int i = 0; i < 4; i++) {
		newArr[i] = arr[i];
	}
	if (isAscending == true) {
		for (int i = 0; i < 4; i++) {
			index = i;
			for (int j = i + 1; j < 4; j++) {
				if (newArr[index] > newArr[j]) {
					index = j;
				}
			}
			swap(newArr[index], newArr[i]);
		}
	}
	return newArr;
}

int main() {
	int items[4] = { 1,5,3,2 };
	int* newItems;
	newItems = sorted(items, true);

	for (int item : items) {
		cout << item << ' ';  // 1 5 3 2
	}

	cout << endl;

	for (int i = 0; i < 4; i++) {
		cout << newItems[i] << " "; // 1 2 3 5
	}
}