//28�� ����3
#include <stdio.h>

int main() {
	/*
	char str[] = "Hello";
	printf("%s\n", &str[0]); //�ι��ڰ� ���ö����� ���
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