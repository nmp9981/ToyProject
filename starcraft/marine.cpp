#include <iostream>
#include <cstring>
using namespace std;

//좌표 클래스
class Marine {
	int hp;//마린 체력
	int coord_x, coord_y;//마린 위치
	int damage;//공격력
	bool is_dead;//죽었는가?
	char* name;//마린 이름

public:
	Marine();//기본 생성자
	Marine(int x, int y, const char* marine_name);//위치,이름
	~Marine();//소멸자

	int attack();//데미지 리턴
	void be_attacked(int damage_earn);//입는 데미지
	void move(int x, int y);//새로운 위치

	void show_status();//상태를 보여준다
};

//초기화
Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}
//마린 생성 위치(생성자)
Marine::Marine(int x,int y,const char* marine_name) {
	name = new char[strlen(marine_name) + 1];
	strcpy(name, marine_name);

	coord_x = x;
	coord_y = y;
	//생성시 초기화
	hp = 50;
	damage = 8;
	is_dead = false;
}

//마린 이동
void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
//마린 공격
int Marine::attack() {
	return damage;
}
//입는 데미지
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
	cout << "***Marine : "<<name<<" ***\n";
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) \n";
	cout << " HP : " << hp << "\n";
}
//소멸자
Marine::~Marine() {
	cout << name << "의 소멸자 호출\n";
	if (name != NULL) delete[] name;
}

int main() {
	Marine* marines[100];//마린 배열
	
	marines[0] = new Marine(2, 3,"Marine 2");//위치를 넣는다
	marines[1] = new Marine(3, 5,"Marine 1");//객체 생성, 생성자 자동 호출
	
	marines[0]->show_status();
	marines[1]->show_status();

	cout << "\n 마린1이 마린2를 공격\n";
	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];//동적 메모리 해제
	delete marines[1];

	return 0;
}
