#include <iostream>
#include<string>
using namespace std;

int main() {
	string english;
	int num[26] = { 0 };

	cin >> english;

	int length = english.length();
	for (int i = 0; i < length; i++) {
		if (english[i] < 97) { //대문자 65~90
			num[english[i] - 65]++;
		}
		else{
			num[english[i] - 97]++; //소문자 97~122
		}
	}

	int alpha, max = 0;
	for (int i = 0; i < 26; i++) {
		if (max < num[i]) {
			max = num[i];
			alpha = i;
		}
	}

	int over = 0 ; //중복 
	for (int i = 0; i < 26; i++) {
		if (max == num[i]){
			over++;
		}
	}
	//출력
	if (over > 1) {
		cout << "?";
	}
	else {
		cout << (char)(alpha + 65);
	}
}