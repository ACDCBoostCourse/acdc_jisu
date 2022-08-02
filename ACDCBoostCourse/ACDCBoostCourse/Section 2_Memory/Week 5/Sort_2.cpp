/*
* int *sorted (int *arr, bool isAscending) 
1. 첫 번째 인자 arr에는 정렬을 수행하고자 하는 배열을 전달해줍니다.
2. 두 번째 인자 isAscending 에는 정렬을 오름차순으로 할 경우 true, 내림차순으로 할 경우 false를 전달합니다.
3. 선택 정렬을 이용하여 arr 배열을 오름차순 또는 내림차순으로 정렬해주는 함수를 구현합니다.

1번 함수와 기능은 동일하나, 이번엔 arr의 데이터는 유지한 채로, 정렬된 새로운 배열을 리턴하는 함수 로 구현해주세요.
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