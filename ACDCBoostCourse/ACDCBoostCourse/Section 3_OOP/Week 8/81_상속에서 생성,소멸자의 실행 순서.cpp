// 81�� ��ӿ��� ����,�Ҹ��� ���� ������ ���� �Ҹ���
#include <iostream>

using namespace std;

//�Ϻ��� �����!

class Ice {
public:
	Ice() { cout << "Ice()" << endl; }
	~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
public:
	Pat() { cout << "Pat()" << endl; }
	~Pat() { cout << "~Pat()" << endl; }
};

class Bingsoo {
public:
	Bingsoo() {
		cout << "Bingsoo()" << endl;
		ice = new Ice;
	}
	virtual ~Bingsoo() { // ���� �Ҹ���
		cout << "~Bingsoo()" << endl; 
		delete ice;
	}

private:
	Ice *ice; // �����Ͷ� ice��� ��ü�� ������ ���� ������ �������� ��.
};

class PatBingsoo : public Bingsoo {
public:
	PatBingsoo() { 
		cout << "PatBingsoo()" << endl; 
		pat = new Pat;
	}
	~PatBingsoo() { 
		cout << "~PatBingsoo()" << endl; 
		delete pat;
	}

private:
	Pat *pat;
};

int main() {
	Bingsoo* p = new PatBingsoo;
	delete p; // Bingsoo Ÿ��, ~PatBingsoo()�� ȣ������ ����.
			  //	-> virtual�� ���� ���ε� �����ֱ�
}
/*	
	PatBingsoo* p = new PatBingsoo; �̰�,

	- �����Ͱ� ���� �� ��� ���

	Ice()
	Bingsoo()
	Pat()
	PatBingsoo()
	~PatBingsoo()
	~Pat()
	~Bingsoo()
	~Ice()
		-> �Ҹ��ڴ� ������ ȣ���� ����
	
	- ice �����͸� ����� �� ��� ���
	
	Bingsoo()
	Ice()
	Pat()
	PatBingsoo()
	~PatBingsoo()
	~Pat()
	~Bingsoo()
	~Ice()
*/