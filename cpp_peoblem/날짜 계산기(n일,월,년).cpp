#include <iostream>
using namespace std;

class Date {
	int year_;	//연도
	int month_;  // 1 부터 12 까지.
	int day_;    // 1 부터 31 까지.

public:
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	}
	void AddDay(int inc) {
		int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		day_ += inc;
		//윤년 처리
		if (year_ % 4 == 0 && year_ % 100 != 0) {
			Month[2] = 29;
		}
		else if (year_ % 400 == 0) {
			Month[2] = 29;
		}
		else {
			Month[2] = 28;
		}

		while (day_ > Month[month_]) {
			//윤년 처리
			if (year_ % 4 == 0 && year_ % 100 != 0) {
				Month[2] = 29;
			}
			else if (year_ % 400 == 0) {
				Month[2] = 29;
			}
			else {
				Month[2] = 28;
			}
			//날짜 계산
			day_ -= Month[month_];
			month_ += 1;
			if (month_ >= 13) {
				year_ += 1;
				month_ -= 12;
			}
		}
	}
	void AddMonth(int inc) {
		month_ += inc;//결과
		year_ += (month_-1) / 12;//13월 이상일 경우
		if (month_ % 12 == 0) month_ = 12;//12월인가?
		else month_ = month_ % 12;
	}
	void AddYear(int inc) {
		year_ += inc;
	}
	void ShowDate() {
		cout << year_ << "년 " << month_ << "월 " << day_ << "일\n";
	}
};

int add, mode;//더하는 값

//입력
void input() {
	cin >> add;
	cout << "모드 입력 : ";
	cin >> mode;
}

int main() {

	Date date;

	input();//입력
	date.SetDate(2022, 6, 7);
	if (mode == 1) {
		date.AddDay(add);
		date.ShowDate();
	}
	else if (mode == 2) {
		date.AddMonth(add);
		date.ShowDate();
	}
	else if (mode == 3) {
		date.AddYear(add);
		date.ShowDate();
	}
	return 0;
}
