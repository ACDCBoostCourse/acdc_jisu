// 81강 상속에서 생성,소멸자 실행 순서와 가상 소멸자
#include <iostream>

using namespace std;

//팥빙수 만들기!

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
	virtual ~Bingsoo() { // 가상 소멸자
		cout << "~Bingsoo()" << endl; 
		delete ice;
	}

private:
	Ice *ice; // 포인터라 ice라는 객체는 생성이 되지 않으니 만들어줘야 함.
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
	delete p; // Bingsoo 타입, ~PatBingsoo()를 호출하지 못함.
			  //	-> virtual로 동적 바인딩 시켜주기
}
/*	
	PatBingsoo* p = new PatBingsoo; 이고,

	- 포인터가 없을 때 출력 결과

	Ice()
	Bingsoo()
	Pat()
	PatBingsoo()
	~PatBingsoo()
	~Pat()
	~Bingsoo()
	~Ice()
		-> 소멸자는 생성자 호출의 역순
	
	- ice 포인터만 사용할 때 출력 결과
	
	Bingsoo()
	Ice()
	Pat()
	PatBingsoo()
	~PatBingsoo()
	~Pat()
	~Bingsoo()
	~Ice()
*/