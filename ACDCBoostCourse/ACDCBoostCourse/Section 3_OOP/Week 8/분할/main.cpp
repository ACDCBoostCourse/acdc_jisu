// 분할 컴파일
// 헤더 파일을 여러 파일에 포함시킬 때에, 반드시 단 한 번만 포함시켜야 한다.
#include "struct.h"
//#include "new.h" // 안에 struct.h가 포함되어 있으므로 ifndef endif 사용

int main() {
	MyStruct PandaCoding = {
		"Panda",
		26
	};

	display(PandaCoding);
	return 0;
}