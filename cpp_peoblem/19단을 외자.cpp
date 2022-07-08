#include <iostream>
#include <cstdlib>
using namespace std;

class gugudan {
private:
    int a, b,ans,exp;
public:
    gugudan(int a, int b,int ans,int exp) : a(a), b(b),ans(ans),exp(exp) {};//생성자 리스트
    void input();//입력
    bool answer();//정답
    int score(){ return exp; };//점수
};

//입력
void gugudan::input() {
    a = rand() % 20; b = rand() % 20;
    cout << a << " x " << b << " = ";
    cin >> ans;
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

int main()
{
    srand(time(NULL));//시드값 변경
    gugudan gugu(1,1,1,0);
    while (1) {
        gugu.input();//입력
        if (!gugu.answer()) break;//정답검사
        cout << "현재 점수는 " << gugu.score() << "점 입니다.\n";
    }
    cout <<"최종 점수 : "<<gugu.score()  << "점";
    return 0;
}
