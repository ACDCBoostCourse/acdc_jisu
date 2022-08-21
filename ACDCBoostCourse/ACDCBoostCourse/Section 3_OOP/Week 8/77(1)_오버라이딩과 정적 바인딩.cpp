// 77�� �������̵��� ���� ���ε�
// override : �켱�ϴ� -> �θ� Ŭ�������� �ڱ� ������ Ŭ������ �켱��
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
	cout << d.Base::a << endl; // 10, d�� ������ BaseŬ������ �ִ� a ���
	cout << d.Derived::a << endl; // 20 
	*/
	d.Print(); // From Derived!!!
	d.Base::Print(); // From Base!!!
	d.Derived::Print(); // From Derived!!!
}