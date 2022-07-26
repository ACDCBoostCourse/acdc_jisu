//66강 예제1
#include <iostream>
using namespace std;

int main() {
	int* a = new int(5);
	int* b = new int(3);

	//a = b; 얕은 복사(참조면 복사)
	*a = *b; //깊은 복사(값을 복사)

	delete a;
	delete b;
}