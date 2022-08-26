#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int nameLen = 20;
//열거형 자료구조
enum {MAKE=1,DEPOSIT,WITHDRAW,PRINT,EXIT};
//고객정보
struct Customer {
	int Number;
	string Name;
	int Money;
};
vector<Customer> Account;//고객 정보를 담은 벡터
int Accountnums = 0;//계좌의 개수

//메뉴판
void ShowMenu() {
	cout << "\n";
	cout << "----Menu----\n";
	cout << "1. 계좌개설 \n";
	cout << "2. 입 금 \n";
	cout << "3. 출 금\n";
	cout << "4. 계좌정보 전체 출력\n";
	cout << "5. 프로그램 종료\n";
}

//계좌 생성
void MakeAccount() {
	int id; string name; int balance;
	cout << "[계좌개설]\n";
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;

	Account.push_back({ id,name,balance });
	Accountnums++;
}

//입금
void AddMoney() {
	int id; int money;
	cout << "[입 금]\n";
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < Accountnums; i++) {
		if (id == Account[i].Number) {
			Account[i].Money += money;
			cout << "입금완료\n";
			return;
		}
	}
	cout << "유효하지 않은 ID입니다.\n";
}
//출금
void MinusMoney() {
	int id; int money;
	cout << "[출 금]\n";
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;

	for (int i = 0; i < Accountnums; i++) {
		if (id == Account[i].Number) {
			if (Account[i].Money < money) {
				cout << "잔액 부족\n";
				return;
			}
			Account[i].Money -= money;
			cout << "출금완료\n";
			return;
		}
	}
	cout << "유효하지 않은 ID입니다.\n";
}
//출력
void AccountPrint() {
	for (int i = 0; i < Accountnums; i++) {
		cout << "계좌ID : " << Account[i].Number << "\n";
		cout << "이 름 : " << Account[i].Name << "\n";
		cout << "잔 액 : " << Account[i].Money << "\n";
		cout << "\n";
	}
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int choice;//선택
	while (1) {
		ShowMenu();//메뉴판
		cout << "선택 : ";
		cin >> choice;
		cout << "\n";

		switch (choice) {
			case MAKE:
				MakeAccount();
				break;
			case DEPOSIT:
				AddMoney();
				break;
			case WITHDRAW:
				MinusMoney();
				break;
			case PRINT:
				AccountPrint();
				break;
			case EXIT:
				return 0;
			default:
				cout << "다시 선택 하십시오.\n";
		}
	}
	return 0;
}
