//25강 예제1
#include <stdio.h>

int main() {
	int a = 10;
	int* ptr_a = &a;

	printf("ptr_a의 값 : %d\n", ptr_a);
	printf("ptr_a + 1의 값 : %d\n", ptr_a + 1); //int 는 4바이트이므로 4가 더해짐
}