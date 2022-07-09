#include <iostream>
using namespace std;

class User {
protected://자식이 써야함
	int user_hp;
	int user_mp;
	int user_attack;
public:
	User(int hp,int mp,int attack) : user_hp(hp), user_mp(mp), user_attack(attack) {}
	bool Death();
	static int max(int x, int y);
};

//user 사망
bool User::Death() {
	if (user_hp <= 0) return true;
	return false;
}
int User::max(int x, int y) {
	return x > y ? x : y;
}
//스킬
class Skill : public User {
private:
	int Skill_percentage = 3;//퍼뎀
	int cost_mp = 30;//소모mp
	int Skill_count = 6;//공격횟수
public:
	Skill(int user_hp, int user_mp, int user_attack) 
		: User(user_hp, user_mp, user_attack) {}//상속시 생성자는 따로 정의
	void consum_MP(int cost_mp);//마나소비
	int Attack();//공격
};

void Skill::consum_MP(int cost_mp) {
	user_mp = max(0,user_mp-cost_mp);
}
int Skill::Attack() {
	return Skill_count * Skill_percentage * user_attack;
}

int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Skill impale(2000,1000,1500);
	cout << impale.Attack();
    return 0;
}
