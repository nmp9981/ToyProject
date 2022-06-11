#include <iostream>
using namespace std;

class Marine {
    static int total_marine_num;//마린의 총 개수,공유변수,프로그램 종료시 소멸
    const static int i = 0;

    int hp;//마린 체력
    int coord_x, coord_y;//마린 위치
    bool is_dead;//마린 사망 여부

    const int default_damage;//기본 공격력

public:
    Marine();//기본 생성자
    Marine(int x, int y,int default_damage);//x,y좌표,데미지에 따른 마린생성
    
    int attack();//데미지 리턴
    void be_attacked(int damage_earn);//입는 데미지
    void move(int x, int y);//새로운 위치

    void show_status();//상태를 보여준다.
    static void show_total_marine();//마린의 개수

    ~Marine() { total_marine_num--; }//소멸자
};

//static변수, 함수
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    cout << "전체 마린 수 : " << total_marine_num << "\n";
}

Marine::Marine() //생성자, 생성했으니 1개 증가
    : hp(50), coord_x(0), coord_y(0), default_damage(10), is_dead(false){total_marine_num++;}

Marine::Marine(int x, int y, int default_damage) //생성자, 생성했으니 1개 증가
    : hp(50), coord_x(x), coord_y(y), default_damage(default_damage), is_dead(false) {total_marine_num++;}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    cout << "***Marine***\n";
    cout << " Location : ( " << coord_x << " , " << coord_y << " ) \n";
    cout << " HP : " << hp << "\n";
    cout << "현재 총 마린 수 : " << total_marine_num << "\n";
}

//마린 생성
void create_marine() {
    Marine marine3(10, 10, 4);
    Marine::show_total_marine();
}
int main() {
    Marine marine1(2, 3, 5);
    Marine::show_total_marine();

    Marine marine2(3, 5, 10);
    Marine::show_total_marine();

    create_marine();

    cout << "마린1이 마린2를 공격\n";
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
       
    return 0;
}
