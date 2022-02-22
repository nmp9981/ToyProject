//두수를 입력받아 계산하기
#include <iostream>
using namespace std;

//제목
void title(){
    cout<<"계산식을 입력하세요."<<"\n";
    cout<<"제공하는 기호는 +,-,*,'%',/,! 입니다."<<"\n";
    cout<<"입력 예시 : 9*3, 기호가 !인 경우 종료됩니다."<<"\n";
}
//계산기
class Cal{
    private:
        int num1;
        int num2;
        char sign;
    public:
        void SetCal(int n1,int n2);//객체 초기화
        void ShowCal(char sign);//계산결과
};
//변수세팅
void Cal::SetCal(int n1,int n2){
    num1 = n1;
    num2 = n2;
}
//계산결과
void Cal::ShowCal(char sign){
    switch(sign){
        case '+':
            cout<<num1+num2<<"\n";
            break;
        case '-':
            cout<<num1-num2<<"\n";
            break;
        case '*':
            cout<<num1*num2<<"\n";
            break;
        case '/':
            cout<<num1/num2<<"\n";
            break;
        case '%':
            cout<<num1%num2<<"\n";
            break;
        default:
            cout<<"ERROR, 올바른 연산기호를 입력하세요"<<"\n";
            break;
    }
}

int x,y;
char c;

int main(){
    while(1){
        title();//제목
        Cal obj;//객체 선언
    
        cin>>x>>c>>y;//입력
        if(c=='!') break;//종료하기
        obj.SetCal(x,y);//객체 초기화
        obj.ShowCal(c);//계산 결과
    }
    return 0;
}
