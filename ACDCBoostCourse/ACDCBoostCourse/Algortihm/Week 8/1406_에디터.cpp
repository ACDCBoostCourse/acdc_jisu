// 백준 1406 시간초과...ㅋㅋ
#include <iostream>
#include <string>

using namespace std;

int main() {
	int count;
	int cursor;
	string str;
	string command;
	string item;

	cin >> str;

	cursor = str.size();

	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> command;

		if (command == "P") {
			cin >> item;

			str.insert(cursor, item);
			cursor++;
		}
		else if (command == "L") {
			if (cursor != 0) { // 커서의 위치가 맨앞이 아니라면
				cursor--;
			}
		}
		else if (command == "D") {
			if(cursor != str.size()) { // 커서의 위치가 맨 뒤가 아니라면
				cursor++;
			}
		}
		else if (command == "B") {
			if (cursor != 0) { // 커서의 위치가 맨앞이 아니라면
				str.erase(cursor - 1, 1); // 삭제
				cursor--;
			}
		}
	}
	cout << str << endl;
	return 0;
}