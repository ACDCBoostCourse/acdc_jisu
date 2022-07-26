//66�� ����2
#include <iostream> //string.h �� �����ϰ� ����
using namespace std;

class String {
public:
	String() {
		strData = NULL;
		len = 0;
	}
	String(const char* str) {
		len = strlen(str);
		strData = new char[len + 1]; //�ι��� ����
		strcpy(strData, str); //���� ����
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