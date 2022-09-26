#include <iostream>
#include <cstring>
#include <vector>
#pragma warning(disable:4996) // C4996 에러를 무시
using namespace std;

const int nameLen = 20;
//열거형 자료구조
enum {MAKE=1,DEPOSIT,WITHDRAW,PRINT,EXIT};

class Account {
private:
	int accID;//계좌번호
	int balance;//잔액
	char* cusName;//고객 이름
public:
	Account(int ID, int money, char* name);//생성자
	Account(const Account& ref);//깊은 복사(포인터가 가리키는 대상까지 복사)
	int GetAccID() const;//계좌번호
	void Deposit(int money);//입금
	int WithDraw(int money);//출금액 반환
	void AccountPrint() const;//현황
	~Account();//소멸자
};
//생성자
Account::Account(int ID, int money, char* name) :accID(ID), balance(money) {
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}
//깊은 복사
Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance) {
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}
//계좌번호
int Account::GetAccID() const { return accID; }
//입금
void Account::Deposit(int money) {
	balance += money;
}
//출금액 반환
int Account::WithDraw(int money) {//출금액 반환
	if (balance < money) return 0;
	balance -= money;
	return money;
}
//출력
void Account::AccountPrint() const {
	cout << "계좌ID : " << accID << "\n";
	cout << "이 름 : " << cusName << "\n";
	cout << "잔 액 : " << balance << "\n";
	cout << "\n";
}
//소멸자
Account::~Account() {
	delete[]cusName;
}

//컨트롤 클래스 제작(앞의 전역함수들은 이 클래스의 멤버함수)
class AccountHandler {
private:
	Account* accArr[100];//Account배열 저장
	int accNum = 0;//고객 수
public:
	AccountHandler();//생성자
	void ShowMenu(void) const;//메뉴판
	void MakeAccount(void);//계좌개설
	void DepositMoney(void);//입금
	void WithdrawMoney(void);//출금
	void ShowAllAccInfo(void) const;//전체 출력
	~AccountHandler();//소멸자
};
//생성자
AccountHandler::AccountHandler() : accNum(0) {}
//메뉴판
void AccountHandler::ShowMenu(void) const {
	cout << "\n";
	cout << "----Menu----\n";
	cout << "1. 계좌개설 \n";
	cout << "2. 입 금 \n";
	cout << "3. 출 금\n";
	cout << "4. 계좌정보 전체 출력\n";
	cout << "5. 프로그램 종료\n";
}

//계좌 생성
void AccountHandler::MakeAccount(void) {
	int id; char name[nameLen]; int balance;
	cout << "[계좌개설]\n";
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;

	accArr[accNum++] = new Account(id, balance, name);
}

//입금
void AccountHandler::DepositMoney(void) {
	int id; int money;
	cout << "[입 금]\n";
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (id==accArr[i]->GetAccID()) {//계좌번호가 일치한가?
			accArr[i]->Deposit(money);
			cout << "입금완료\n";
			return;
		}
	}
	cout << "유효하지 않은 ID입니다.\n";
}
//출금
void AccountHandler::WithdrawMoney(void) {
	int id; int money;
	cout << "[출 금]\n";
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (id == accArr[i]->GetAccID()) {
			if (accArr[i]->WithDraw(money) == 0) {
				cout << "잔액 부족\n";
				return;
			}
			cout << "출금완료\n";
			return;
		}
	}
	cout << "유효하지 않은 ID입니다.\n";
}
//모두 출력
void AccountHandler::ShowAllAccInfo(void) const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->AccountPrint();
	}
}
//소멸자
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	AccountHandler manager;
	int choice;//선택
	while (1) {
		manager.ShowMenu();//메뉴판
		cout << "선택 : ";
		cin >> choice;
		cout << "\n";

		switch (choice) {
			case MAKE:
				manager.MakeAccount();
				break;
			case DEPOSIT:
				manager.DepositMoney();
				break;
			case WITHDRAW:
				manager.WithdrawMoney();
				break;
			case PRINT:
				manager.ShowAllAccInfo();
				break;
			case EXIT:
				return 0;
			default:
				cout << "다시 선택 하십시오.\n";
		}
	}
	return 0;
}
