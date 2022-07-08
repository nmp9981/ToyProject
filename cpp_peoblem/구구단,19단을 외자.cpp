#include <iostream>
#include <cstdlib>
using namespace std;

class gugudan {
private:
    int a, b,ans,exp;
public:
    int maxi;//단수 설정
    gugudan(int a, int b,int ans,int exp) : a(a), b(b),ans(ans),exp(exp) {};//생성자 리스트
    void input();//입력
    bool answer();//정답
    int score(){ return exp; };//점수
};

//입력
void gugudan::input() {
    a = rand() % maxi; b = rand() % maxi;//0~maxi 랜덤
    cout << a << " x " << b << " = ";//문제
    cin >> ans;//정답 입력
    cout << "\n";
}
//정답 검사
bool gugudan::answer() {
    if (ans == a * b) {
        exp += 10;
        return true;
    }
    return false;
}
//단계 입력
int start() {
    cout << "단계를 입력하시오. (1단계 : 9단, 2단계 : 19단) \n";
    int step;
    cin>> step;
    return step;
}

int main()
{
    srand(time(NULL));//시드값 변경, 매번 문제가 랜덤하게
    gugudan gugu(1,1,1,0);

    //단계입력
    int st_step = start();
    if (st_step==1) gugu.maxi = 10;
    else if (st_step == 2) gugu.maxi = 20;

    //게임 진행
    while (1) {
        gugu.input();//입력
        if (!gugu.answer()) break;//정답이 아니면 종료
        cout << "현재 점수는 " << gugu.score() << "점 입니다.\n";
    }
    cout <<"최종 점수 : "<<gugu.score()  << "점";
    return 0;
}
