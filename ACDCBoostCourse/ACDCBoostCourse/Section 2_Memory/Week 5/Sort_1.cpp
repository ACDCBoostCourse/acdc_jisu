/*
* void sort(int *arr, bool isAscending)
1. 첫 번째 인자 arr에는 정렬을 수행하고자 하는 배열을 전달해줍니다.
2. 두 번째 인자 isAscending 에는 정렬을 오름차순으로 할 경우 true, 내림차순으로 할 경우 false를 전달합니다.
3. 선택 정렬을 이용하여 arr 배열을 오름차순 또는 내림차순으로 정렬해주는 함수를 구현합니다.
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
