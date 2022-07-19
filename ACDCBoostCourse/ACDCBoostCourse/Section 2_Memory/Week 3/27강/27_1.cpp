//27강 예제1
#include <stdio.h>

int main() {
	int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

	printf("%d\n", sizeof(arr)); //24, 4*6
	printf("%d\n", sizeof(arr[0])); //12, 0행(1차워 배열) 전체 크기
	printf("%d\n", sizeof(arr[0][0])); //4

	//아래는 다 같은 값이 출력됨
	printf("%d\n", &arr); 
	printf("%d\n", &arr[0]); 
	printf("%d\n", &arr[0][0]);
}