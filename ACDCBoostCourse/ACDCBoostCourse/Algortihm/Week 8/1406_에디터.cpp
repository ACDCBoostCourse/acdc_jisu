// ���� 1406 �ð��ʰ�...����
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
			if (cursor != 0) { // Ŀ���� ��ġ�� �Ǿ��� �ƴ϶��
				cursor--;
			}
		}
		else if (command == "D") {
			if(cursor != str.size()) { // Ŀ���� ��ġ�� �� �ڰ� �ƴ϶��
				cursor++;
			}
		}
		else if (command == "B") {
			if (cursor != 0) { // Ŀ���� ��ġ�� �Ǿ��� �ƴ϶��
				str.erase(cursor - 1, 1); // ����
				cursor--;
			}
		}
	}
	cout << str << endl;
	return 0;
}