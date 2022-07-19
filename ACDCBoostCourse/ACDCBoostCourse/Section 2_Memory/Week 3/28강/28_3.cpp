//28강 예제3
#include <stdio.h>

int main() {
	/*
	char str[] = "Hello";
	printf("%s\n", &str[0]); //널문자가 나올때까지 출력
	*/
	char strings[3][10] = { "Hello", "World", "Doodle" };
	char *p_str[3];

	for (int i = 0; i < 3; i++) {
		p_str[i] = strings[i];
	}

	for (int i = 0; i < 3; i++) {
		printf("%s\n", p_str[i]);
	}
}