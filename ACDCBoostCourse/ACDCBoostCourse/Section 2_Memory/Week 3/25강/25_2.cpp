//25강 예제2
#include <stdio.h>

int main() {
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++) {
		printf("&arr[%d] = %d\n", i, &arr[i]);
		//4씩 차이남을 알 수 있음 -> 메모리상에서도 일렬로 저장
		printf("arr + %d = %d\n", i, arr + i); //arr + i = &arr[i]
	}
}