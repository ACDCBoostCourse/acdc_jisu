#ifndef STRUCT
#include <iostream>

using namespace std;

struct MyStruct {
	string name;
	int age;
};

void display(MyStruct&);

#endif // !STRUCT , struct가 정의되어 있지 않은 경우에만 위의 if문 실행
/*
	헤더 파일

	1. 함수 원형
	2. #define이나 const를 사용하는 기호 상수
	3. 구조체 선언
	4. 클래스 선언
	5. 템플릿 선언
	6. 인라인 함수
*/