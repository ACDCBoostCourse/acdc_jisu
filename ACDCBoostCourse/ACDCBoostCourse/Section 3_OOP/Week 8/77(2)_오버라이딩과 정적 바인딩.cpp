// 77강 오버라이딩과 정적 바인딩
// 논리적 오류가 없기 때문에 C++에서 부모를 가리키는 포인터가 자식을 가리킬 수도 있음
// 바인딩 : 모호한 포인터의 결정?
#include <iostream>

using namespace std;

class Base { // 남자에 비유
public:
	void Print() {
		cout << "From Base!!!" << endl;
	}
};

class Derived : public Base { // 총각?에 비유
public:
	void Print() {
		cout << "From Derived!!!" << endl;
	}
};

class Derived2 : public Base {

};

int main() {
	Base* b = new Derived();
	b->Print(); // (*b.)Print()와 같음 // From Base!!! // 정적 바인딩(기본적)
	b = new Derived2();
	b->Print(); // From Base!!!
	// Base, Derived, Derived2 판별하기 어려움 -> Base를 가리키는 포인터로 가정
	delete b;
}
// 동적 바인딩의 경우 3가지 모두를 경우의 수로 취급