// 76강 상속이 필요한 이유 (1)
// 메시지(텍스트, 이미지)를 주고받는 메신저 구현
#include <iostream>
#include <string>

using namespace std;

class Image {
public:
	operator string() { // string으로 형변환을 하는 연산자 오버로딩
		return "사진";
	}
};

class Message { // 부모 클래스
public:
	Message(int sendTime, string sendName) {
		this->sendTime = sendTime;
		this->sendName = sendName;
	}
	int GetSendTime() const { return sendTime; }
	string GetSendName() const { return sendName; }

private:
	int sendTime;
	string sendName;
};

class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text) 
		: Message(sendTime, sendName) {
		this->text = text;
	}

	string GetText() const { return text; }

private:
	string text;
};

class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image *image) 
		: Message(sendTime, sendName) {
		this->image = image; // 얕은 복사 문제x
	}

	Image *GetImage() const { return image; } // image에 대한 포인터 반환

private:
	Image *image; // 이미지 클래스가 있다고 가정
};

int main() {
	// 두들 : "안녕"
	// 두들 : "(이미지)강아지 사진"
	Image* p_dogImage = new Image();
	TextMessage* hello = new TextMessage(10, "두들", "안녕");
	ImageMessage* dog = new ImageMessage(20, "두들", p_dogImage);

	cout << "보낸 시간 : " << hello->GetSendTime() << endl;
	cout << "보낸 사람 : " << hello->GetSendName() << endl;
	cout << " 내   용  : " << hello->GetText() << endl;
	cout << endl;

	cout << "보낸 시간 : " << dog->GetSendTime() << endl;
	cout << "보낸 사람 : " << dog->GetSendName() << endl;
	cout << " 내   용  : " << (string) * dog->GetImage() << endl;
	cout << endl;


	delete hello;
	delete dog;
	delete p_dogImage;
}