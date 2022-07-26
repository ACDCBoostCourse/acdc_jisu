//66강 예제2
#include <iostream> //string.h 를 포함하고 있음
using namespace std;

class String {
public:
	String() {
		strData = NULL;
		len = 0;
	}
	String(const char* str) {
		len = strlen(str);
		strData = new char[len + 1]; //널문자 포함
		strcpy(strData, str); //깊은 복사
	}
	~String() {
		delete[] strData;
	}

	char* GetStrData() const {
		return strData;
	}
	int Getlen() const {
		return len;
	}

private:
	char* strData;
	int len;
};

int main() {
	String s;
}