//백준 10845
#include <iostream>
#include <string>
using namespace std;

//template <typename T>

class Queue {
private:
	int arr[10000];
	int q_size;
	int topCursor; //back
	int bottomCursor; //front

public:
	Queue() {
		q_size = 0;
		for (int i = 0; i < 10000; i++) {
			arr[i] = 0;
		}
		topCursor = 0;
		bottomCursor = 0;
	}
	/*
	~Queue() {
		delete[] arr;
	}
	*/
	void push(int elem) { // 원소 넣기
		arr[topCursor] = elem;
		topCursor++;
		q_size++;
	}
	void pop() { // front 값 출력
		if (q_size != 0) {
			cout << arr[bottomCursor] << endl;
			arr[bottomCursor] = 0;
			bottomCursor++;
			q_size--;
		}
		else {
			cout << "-1" << endl;
		}
	}
	int front() {
		if (arr[bottomCursor] == 0) return -1;
		else return arr[bottomCursor];
	}
	int back() {
		if (arr[topCursor - 1] == 0) return -1;
		else return arr[topCursor - 1];
	}
	bool empty() {
		if (q_size == 0) return true;
		else return false;
	}
	int size() {
		return q_size;
	}
};

int main() {
	string command;
	int elem;
	int num;

	cin >> num; // 명령 개수
	
	Queue q_queue;
	
	for (int i = 0; i < num + 1; i++) {

		getline(cin,command);

		elem = atoi(command.substr(command.find(" ") + 1, command.length()).c_str()); // 공백을 기준으로 뒤에 있는 문자 받기 -> atoi(문자.c_str()) 사용해서 정수형으로 변환
		command = command.substr(0, command.find(" ")); // 공백을 기준으로 앞에 있는 명령어 받기

		if (command == "push") {
			q_queue.push(elem);
		}
		else if (command == "pop") {
			q_queue.pop();
		}
		else if (command == "front") {
			cout << q_queue.front() << endl;
		}
		else if (command == "back") {
			cout << q_queue.back() << endl;
		}
		else if (command == "empty") {
			cout << q_queue.empty() << endl;
		}
		else if (command == "size") {
			cout << q_queue.size() << endl;
		}
	}
	return 0;
}