#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


// 1. typedef 선언
typedef string transactionName_t;
typedef int won_t;
typedef string name_t;

// 별명을 붙여줌
// 가독성이 좋아짐
// 끝에 _t를 붙이는 것이 관례

// 2. Transaction 구조체 정의
struct Transaction {
	transactionName_t transactionName;
	won_t depositAndWithdrawal;
};
// Upper Camel Case

// 3. DatOfTheWeek
enum DayOfTheWeek {
	Monday = 0,
	Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};
// enum : 열거형으로 여러 개의 값 중 하나를 지칭하는 형태의 데이터

// 4. BankAccount 클래스 정의
class BankAccount { // 클래스는 private이 기본값
	//Attributes
private: //정보 은닉
	name_t clientName;
	int password;
	int accountID;
	won_t accountBalance;
	DayOfTheWeek termDepositDay;
	Transaction transactionList[2];

public:
	// Constructors
	BankAccount() :clientName("강지수"), password(1234), accountID(rand() % 10000), accountBalance(0), termDepositDay(Monday) {
		transactionList[0] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
		transactionList[1] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
		cout << clientName << "님의 계좌가 생성되었습니다. Account ID: " << accountID << endl;
	}

	BankAccount(name_t clientName, int password, DayOfTheWeek termDepositDay) : clientName(clientName), password(password), accountID(rand() % 10000), accountBalance(0), termDepositDay(termDepositDay) {
		transactionList[0] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
		transactionList[1] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
		cout << clientName << "님의 계좌가 생성되었습니다. Account ID: ";
		printf("%04d\n", accountID);
	}

	~BankAccount() {
		cout << clientName << "님의 계좌가 삭제되었습니다. Account ID: ";
		printf("%04d\n", accountID);
		// 멤버 변수 중 동적 할당된 것이 없으므로 메모리 해제할 것이 없다.
	}

	//Methods
	name_t getName() {
		return clientName;
	}

	won_t getAccountBalance() {
		return accountBalance;
	}

	int getPassword() {
		return password;
	}

	string getDayOfTheWeek() {
		switch (termDepositDay) {
		case Monday:
			return "Monday";
			break;

		case Tuesday:
			return "Tuesday";
			break;

		case Wednesday:
			return "Wednesday";
			break;

		case Thursday:
			return "Thursday";
			break;

		case Friday:
			return "Friday";
			break;

		case Saturday:
			return "Saturday";
			break;

		case Sunday:
			return "Sunday";
			break;

		dafault:
			break;
		}
	}

	void setDayOfTheWeek(DayOfTheWeek termDepsitDay) {
		this->termDepositDay = termDepositDay;
	}

	void printTransactionList() {
		for (int i = 0; i < 2; i++) {
			cout << "거래 이름: " << transactionList[i].transactionName << "  거래 금액: " << transactionList[i].depositAndWithdrawal << endl;
		}
	}

	void addTransaction(name_t transactionName, won_t depositAndWithdrawal) {
		for (int i = 0; i < 2; i++) {
			if (transactionList[i].transactionName == "거래 없음") {
				transactionList[i].transactionName = transactionName;
				transactionList[i].depositAndWithdrawal = depositAndWithdrawal;
				accountBalance += depositAndWithdrawal;
				break; 
			}
		}
	}

	// mergeAccount 함수에서 accountBalance에 접근하기 위해 추가적인 Method 구현
	void mergeAccountBalance(won_t mergedMoney) {
		accountBalance += mergedMoney;
	}

	// private 에 있는 accountID에 접근하기 위해 Getter 구현
	int getAccountID() {
		return accountID;
	}
};

// 5. mergeAccount 함수 구현

// Call by Pointer
void mergeAccount(BankAccount* absorbing, BankAccount* absorbed) {
	won_t mergedMoney = absorbed->getAccountBalance();
	absorbing->mergeAccountBalance(mergedMoney);
}

// Call by Reference
void mergeAccount(BankAccount& absorbing, BankAccount& absorbed) {
	won_t mergedMoney = absorbed.getAccountBalance();
	absorbing.mergeAccountBalance(mergedMoney);
}

// 6. Main 함수 구현
int main() {
	srand(time(NULL));
	name_t name;
	int password;
	int temp;
	DayOfTheWeek dayOfTheWeek;
	transactionName_t transactionName;
	won_t money;

	//A, B 계좌 등록
	cout << "이름을 입력해주세요." << endl;
	cin >> name;
	cout << "비밀번호를 입력해주세요." << endl;
	cin >> password;
	cout << "정기 예금 요일을 숫자로 입력해주세요. \n월요일 - 1\n화요일 - 2\n수요일 - 3\n목요일 - 4\n금요일 - 5\n토요일 - 6\n일요일 - 7" << endl;
	cin >> temp;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);

	BankAccount A(name, password, dayOfTheWeek);

	cout << "이름을 입력해주세요." << endl;
	cin >> name;
	cout << "비밀번호를 입력해주세요." << endl;
	cin >> password;
	cout << "정기 예금 요일을 숫자로 입력해주세요. \n월요일 - 1\n화요일 - 2\n수요일 - 3\n목요일 - 4\n금요일 - 5\n토요일 - 6\n일요일 - 7" << endl;
	cin >> temp;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);

	BankAccount B(name, password, dayOfTheWeek);

	// A, B 예금
	cout << "거래 이름과 예금할 금액을 입력해주세요." << endl;
	cout << "거래 이름: ";
	cin >> transactionName;
	cout << "예금할 금액: ";
	cin >> money;

	A.addTransaction(transactionName, money);
	cout << "계좌 잔액: " << A.getAccountBalance() << endl;
	A.printTransactionList();

	cout << "거래 이름과 예금할 금액을 입력해주세요." << endl;
	cout << "거래 이름: ";
	cin >> transactionName;
	cout << "예금할 금액: ";
	cin >> money;

	B.addTransaction(transactionName, money);
	cout << "계좌 잔액: " << B.getAccountBalance() << endl;
	B.printTransactionList();

	// A 요일 변경
	cout << "바꿀 요일을 입력해주세요. \n월요일 - 1\n화요일 - 2\n수요일 - 3\n목요일 - 4\n금요일 - 5\n토요일 - 6\n일요일 - 7" << endl;
	cin >> temp;
	cout << "바꾸기 전 요일 : " << A.getDayOfTheWeek() << endl;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);
	A.setDayOfTheWeek(dayOfTheWeek);
	cout << "바꾼 후 요일 : " << A.getDayOfTheWeek() << endl;

	// B 출금
	cout << "거래 이름과 출금할 금액 (음수로 입력) 을 입력해주세요." << endl;
	cout << "거래 이름: ";
	cin >> transactionName;
	cout << "출금할 금액: ";
	cin >> money;

	B.addTransaction(transactionName, money);
	cout << "남은 금액 : " << B.getAccountBalance() << endl;
	B.printTransactionList();

	//계좌 합치기
	mergeAccount(A, B);

	cout << "합친 계좌 이름: " << A.getName() << endl;
	cout << "합친 계좌 잔고: " << A.getAccountBalance() << endl;
	cout << "합친 계좌 ID: " << A.getAccountID() << endl;
	cout << "합친 계좌 비밀번호: " << A.getPassword() << endl;
	A.printTransactionList();
	cout << A.getDayOfTheWeek() << endl;

	return 0;
}