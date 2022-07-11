#include <iostream>
#include <cstdlib>
using namespace std;

//몬스터
class Monster {
private:
	const int Mob_Max_HP = 100000;
	int Mob_HP = Mob_Max_HP;
	int Mob_attack = 2100;
	int Mob_EXP = 3000;
public:
	int Attack();//공격
	int Hitted(int damage);//피격
	int GetEXP() { return Mob_EXP; }//경험치 획득
	bool IsMobDeath();//사망
};
int Monster::Attack() {//몬스터 공격
	int maxDamage = Mob_attack;
	int minDamage = maxDamage * 8 / 10;
	return minDamage + (rand() % (maxDamage - minDamage + 1));
}
int Monster::Hitted(int damage) {//몬스터 피격
	Mob_HP = max(0, Mob_HP - damage);
	return Mob_HP;
}
bool Monster::IsMobDeath() {
	if (Mob_HP <= 0) return true;
	return false;
}

//유저
class User {
protected://자식이 써야함
	const int user_max_hp = 3000; 
	const int user_max_mp = 3000;
	const int user_max_attack = 900;
	int user_hp = user_max_hp;
	int user_mp = user_max_mp;
	int user_min_attack = user_max_attack * 9 / 10;
	int user_attack;
public:
	static int max(int x, int y);//max함수 정의
	bool IsDeath();//사망 처리
	void Attacked(int damage);//피격
	void Heal();//회복
};

//user 사망
bool User::IsDeath() {
	if (user_hp <= 0) return true;
	return false;
}
//max함수 정의
int User::max(int x, int y) {
	return x > y ? x : y;
}
//피격
void User::Attacked(int damage) {
	user_hp = max(0, user_hp - damage);
	cout <<"HP : "<< user_hp<<" / "<<user_max_hp<<"\n";
}
//회복
void User::Heal() {
	user_hp = user_max_hp;
	user_mp = user_max_mp;
	cout << "HP : " << user_hp << " / " << user_max_hp << "\n";
}

//임페일
class Impale : public User {
private:
	int Impale_percentage = 2;//퍼뎀
	int cost_mp = 30;//소모mp
	int Skill_count = 6;//공격횟수
public:
	void consum_MP(int cost_mp);//마나소비
	int Attack();//공격
};

void Impale::consum_MP(int cost_mp) {
	user_mp = max(0,user_mp-cost_mp);
}
int Impale::Attack() {
	int sumDamage = 0;//총합 데미지
	for (int i = 0; i < Skill_count; i++) {
		user_attack = user_min_attack + rand() % (user_max_attack - user_min_attack + 1);//한줄 데미지
		int presentDamage = Impale_percentage * user_attack;
		cout << presentDamage << "\n";
		sumDamage += presentDamage;
	}
	return sumDamage;
}

int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	srand(time(NULL));//시드값 변경, 매번 랜덤하게

	Monster boss;
	User user;
	Impale impale;

	while (!boss.IsMobDeath()) {
		cout << "Boss : " << boss.Hitted(impale.Attack()) << "\n";
		cout << boss.Attack() << "\n";
		user.Attacked(boss.Attack());
		user.Heal();
		cout << "\n";
	}
    return 0;
}
