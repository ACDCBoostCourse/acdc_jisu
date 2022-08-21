// 80�� ���� ���� �Լ��� �߻� Ŭ����
#include <iostream>

using namespace std;
/*
class A { // ���� ���� �Լ��� �ϳ��� ���ԵǸ� �߻� Ŭ����, �ν��Ͻ� ����� �Ұ�
public:
	virtual void f() = 0; // NULL ���� ���� �Լ� -> �ν��Ͻ��� ���� �� ����
};

class B : public A {
public:
	void f() {
		cout << "B::f()" << endl;
	}
};

int main() {
	A* a = new B;
	a->f();

	delete a;
}
*/
const double PI = 3.143592653589793;

class Shape {
public:
	virtual double GetArea() = 0;

	virtual void Resize(double f) = 0;

};

class Circle : public Shape {
public:
	Circle(double r) : r(r) {}

	double GetArea() {
		return PI * r * r;
	}

	void Resize(double f) {
		r *= f;
	}

private:
	double r;
};

class Rectangle : public Shape{
public:
	Rectangle(double a, double b) : a(a), b(b) {}

	double GetArea() {
		return a * b;
	}
	void Resize(double f) {
		a *= f;
		b *= f;
	}

private:
	double a, b;
};

int main() {
	Shape* shapes[] = {
		new Circle(10),
		new Rectangle(20,30)
	};
	
	for (Shape* s : shapes) {
		s->Resize(2);
	}

	for (Shape* s : shapes) {
		cout << s->GetArea() << endl;
	}

	for (Shape* s : shapes) {
		delete s;
	}
}