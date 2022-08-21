// 77�� �������̵��� ���� ���ε�
// ���� ������ ���� ������ C++���� �θ� ����Ű�� �����Ͱ� �ڽ��� ����ų ���� ����
// ���ε� : ��ȣ�� �������� ����?
#include <iostream>

using namespace std;

class Base { // ���ڿ� ����
public:
	void Print() {
		cout << "From Base!!!" << endl;
	}
};

class Derived : public Base { // �Ѱ�?�� ����
public:
	void Print() {
		cout << "From Derived!!!" << endl;
	}
};

class Derived2 : public Base {

};

int main() {
	Base* b = new Derived();
	b->Print(); // (*b.)Print()�� ���� // From Base!!! // ���� ���ε�(�⺻��)
	b = new Derived2();
	b->Print(); // From Base!!!
	// Base, Derived, Derived2 �Ǻ��ϱ� ����� -> Base�� ����Ű�� �����ͷ� ����
	delete b;
}
// ���� ���ε��� ��� 3���� ��θ� ����� ���� ���