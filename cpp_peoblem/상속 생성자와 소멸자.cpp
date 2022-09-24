#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996) // C4996 에러를 무시

class Person {
private:
	char* name;//이름
public:
	Person(const char* myname) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	~Person() {
		delete[]name;
	}
	void WhatName() const {
		cout << "이름 : " << name << "\n";
	}
};

class User :public Person{
private:
	char* job;//직업
public:
	User(const char* myname, const char* myjob) :Person(myname) {
		job = new char[strlen(myjob) + 1];
		strcpy(job, myjob);
	}
	~User() {
		delete[]job;
	}
	void WhoJob() const {
		WhatName();
		cout << "직업 : " << job << "\n";
		cout << "\n";
	}
};
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	User user1("다오", "파이터");
	user1.WhoJob();
	User user2("로두마니", "스트라이커");
	user2.WhoJob();
    return 0;
}
