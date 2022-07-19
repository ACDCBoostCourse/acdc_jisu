/* 
	26�� ����2
	1. ptr == &ptr[0]
	2. *ptr == ptr[0]
	3. ptr + 1 == ptr�� sizeof(*ptr)�� ���� ��
		-> &arr + 1 == &ptr�� sizeof(arr)�� ���� ��
*/

#include <stdio.h>

int main() {

	int arr[3] = { 1, 2, 3 };
	
	printf("arr = %d\n", arr);
	printf("arr + 1 = %d\n", arr + 1);

	printf("&arr = %d\n", &arr);
	printf("&arr + 1 = %d\n", &arr + 1); 
	//12�� ������. arr�� ũ�Ⱑ �� 12����Ʈ.

}