// 77강 오버라이딩과 정적 바인딩
// override : 우선하다 -> 부모 클래스보다 자기 고유의 클래스를 우선함
#include <iostream>

using namespace std;

class Base {
public:
	int a = 10;
	void Print() {
		cout << "From Base!!!" << endl;
	}
};

class Derived : public Base {
public:
	int a = 20;
	void Print() {
		cout << "From Derived!!!" << endl;
	}
};

int main() {
	//Base b;
	Derived d;
	/*
	cout << b.a << endl; // 10
	cout << d.a << endl; // 20
	cout << d.Base::a << endl; // 10, d에 있지만 Base클래스에 있는 a 출력
	cout << d.Derived::a << endl; // 20 
	*/
	d.Print(); // From Derived!!!
	d.Base::Print(); // From Base!!!
	d.Derived::Print(); // From Derived!!!
}