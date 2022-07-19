/*
	27강 예제2
	1. arr == &arr[0]
	2. *arr == arr[0]
	3. ptr + 1 == ptr에 sizeof(*ptr)을 더한 값
		-> &arr + 1 == &ptr에 sizeof(arr)을 더한 값
*/
#include <stdio.h>

int main() {
	int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

	int(*ptr)[3] = arr; //ptr = arr

	// 1. ptr[i] == arr[i]
	// 2. ptr[i][j] == arr[i][j]
	// 3. ptr == arr 

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", ptr[i][j]);
		}
		printf("\n");
	}
}