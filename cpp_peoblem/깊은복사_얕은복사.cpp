#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996) // C4996 에러를 무시

class Monster {
public:
	char* name;
	int lv;

	//생성자
	Monster(const char* _name, int _lv) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		lv = _lv;
	}
	/*
	//얕은 복사(단순 대입)
	Monster(const Monster& m) {
		cout << "얕은 복사\n";
		name = m.name;
		lv = m.lv;
	}
	*/
	//깊은 복사(복사 생성자)
	Monster(const Monster& m) {
		cout << "깊은 복사\n";
		name = new char[strlen(m.name) + 1];
		strcpy(name, m.name);
		lv = m.lv;
	}
	
};
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	Monster mob1 = Monster("로보토이", 41);
	Monster mob2 = mob1;//복사

	strcpy(mob1.name, "플래툰 크로노스");//mob의 name변경
	cout << mob1.name <<" " << mob1.lv << "\n";
	cout << mob2.name << " " << mob2.lv << "\n";
	return 0;
}
