#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


// 1. typedef ����
typedef string transactionName_t;
typedef int won_t;
typedef string name_t;

// ������ �ٿ���
// �������� ������
// ���� _t�� ���̴� ���� ����

// 2. Transaction ����ü ����
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
// enum : ���������� ���� ���� �� �� �ϳ��� ��Ī�ϴ� ������ ������

// 4. BankAccount Ŭ���� ����
class BankAccount { // Ŭ������ private�� �⺻��
	//Attributes
private: //���� ����
	name_t clientName;
	int password;
	int accountID;
	won_t accountBalance;
	DayOfTheWeek termDepositDay;
	Transaction transactionList[2];

public:
	// Constructors
	BankAccount() :clientName("������"), password(1234), accountID(rand() % 10000), accountBalance(0), termDepositDay(Monday) {
		transactionList[0] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
		transactionList[1] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
		cout << clientName << "���� ���°� �����Ǿ����ϴ�. Account ID: " << accountID << endl;
	}

	BankAccount(name_t clientName, int password, DayOfTheWeek termDepositDay) : clientName(clientName), password(password), accountID(rand() % 10000), accountBalance(0), termDepositDay(termDepositDay) {
		transactionList[0] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
		transactionList[1] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
		cout << clientName << "���� ���°� �����Ǿ����ϴ�. Account ID: ";
		printf("%04d\n", accountID);
	}

	~BankAccount() {
		cout << clientName << "���� ���°� �����Ǿ����ϴ�. Account ID: ";
		printf("%04d\n", accountID);
		// ��� ���� �� ���� �Ҵ�� ���� �����Ƿ� �޸� ������ ���� ����.
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
			cout << "�ŷ� �̸�: " << transactionList[i].transactionName << "  �ŷ� �ݾ�: " << transactionList[i].depositAndWithdrawal << endl;
		}
	}

	void addTransaction(name_t transactionName, won_t depositAndWithdrawal) {
		for (int i = 0; i < 2; i++) {
			if (transactionList[i].transactionName == "�ŷ� ����") {
				transactionList[i].transactionName = transactionName;
				transactionList[i].depositAndWithdrawal = depositAndWithdrawal;
				accountBalance += depositAndWithdrawal;
				break; 
			}
		}
	}

	// mergeAccount �Լ����� accountBalance�� �����ϱ� ���� �߰����� Method ����
	void mergeAccountBalance(won_t mergedMoney) {
		accountBalance += mergedMoney;
	}

	// private �� �ִ� accountID�� �����ϱ� ���� Getter ����
	int getAccountID() {
		return accountID;
	}
};

// 5. mergeAccount �Լ� ����

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

// 6. Main �Լ� ����
int main() {
	srand(time(NULL));
	name_t name;
	int password;
	int temp;
	DayOfTheWeek dayOfTheWeek;
	transactionName_t transactionName;
	won_t money;

	//A, B ���� ���
	cout << "�̸��� �Է����ּ���." << endl;
	cin >> name;
	cout << "��й�ȣ�� �Է����ּ���." << endl;
	cin >> password;
	cout << "���� ���� ������ ���ڷ� �Է����ּ���. \n������ - 1\nȭ���� - 2\n������ - 3\n����� - 4\n�ݿ��� - 5\n����� - 6\n�Ͽ��� - 7" << endl;
	cin >> temp;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);

	BankAccount A(name, password, dayOfTheWeek);

	cout << "�̸��� �Է����ּ���." << endl;
	cin >> name;
	cout << "��й�ȣ�� �Է����ּ���." << endl;
	cin >> password;
	cout << "���� ���� ������ ���ڷ� �Է����ּ���. \n������ - 1\nȭ���� - 2\n������ - 3\n����� - 4\n�ݿ��� - 5\n����� - 6\n�Ͽ��� - 7" << endl;
	cin >> temp;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);

	BankAccount B(name, password, dayOfTheWeek);

	// A, B ����
	cout << "�ŷ� �̸��� ������ �ݾ��� �Է����ּ���." << endl;
	cout << "�ŷ� �̸�: ";
	cin >> transactionName;
	cout << "������ �ݾ�: ";
	cin >> money;

	A.addTransaction(transactionName, money);
	cout << "���� �ܾ�: " << A.getAccountBalance() << endl;
	A.printTransactionList();

	cout << "�ŷ� �̸��� ������ �ݾ��� �Է����ּ���." << endl;
	cout << "�ŷ� �̸�: ";
	cin >> transactionName;
	cout << "������ �ݾ�: ";
	cin >> money;

	B.addTransaction(transactionName, money);
	cout << "���� �ܾ�: " << B.getAccountBalance() << endl;
	B.printTransactionList();

	// A ���� ����
	cout << "�ٲ� ������ �Է����ּ���. \n������ - 1\nȭ���� - 2\n������ - 3\n����� - 4\n�ݿ��� - 5\n����� - 6\n�Ͽ��� - 7" << endl;
	cin >> temp;
	cout << "�ٲٱ� �� ���� : " << A.getDayOfTheWeek() << endl;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);
	A.setDayOfTheWeek(dayOfTheWeek);
	cout << "�ٲ� �� ���� : " << A.getDayOfTheWeek() << endl;

	// B ���
	cout << "�ŷ� �̸��� ����� �ݾ� (������ �Է�) �� �Է����ּ���." << endl;
	cout << "�ŷ� �̸�: ";
	cin >> transactionName;
	cout << "����� �ݾ�: ";
	cin >> money;

	B.addTransaction(transactionName, money);
	cout << "���� �ݾ� : " << B.getAccountBalance() << endl;
	B.printTransactionList();

	//���� ��ġ��
	mergeAccount(A, B);

	cout << "��ģ ���� �̸�: " << A.getName() << endl;
	cout << "��ģ ���� �ܰ�: " << A.getAccountBalance() << endl;
	cout << "��ģ ���� ID: " << A.getAccountID() << endl;
	cout << "��ģ ���� ��й�ȣ: " << A.getPassword() << endl;
	A.printTransactionList();
	cout << A.getDayOfTheWeek() << endl;

	return 0;
}