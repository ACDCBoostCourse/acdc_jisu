#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	while (true) {
		stack<char> str;
		string s;
		bool mark = true;

		getline(cin, s);
		if (s.size() == 1 && s[0] == '.') break;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i]=='[') str.push(s[i]);
			if (s[i] == ']' || s[i] == ')') {
				if (str.empty()) {
					mark = false;
				}
				else if (s[i] == ']') {
					if (str.top() == '[') str.pop();
					else mark = false;
				}
				else if (s[i] == ')') {
					if (str.top() == '(') str.pop();
					else mark = false;
				}
			}
		}
		if (mark && str.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}