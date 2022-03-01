#include <iostream>
using namespace std;
//계좌 클래스
class Account{
    private : 
        string accountNum;
        string name;
        int balance;
    public : 
        Account(string a="",string n="",int b=0);//생성자
        void prn() const;
        void deposit(int money=0);//입금
        void withdraw(int money=0);//출금
        void getBalance();//잔고확인
};

//생성자
Account::Account(string a,string n,int b){
    accountNum = a;
    name = n;
    balance = b;
}
//현황출력
void Account::prn() const{
    cout<<"계좌정보 => 계좌번호 : "<<accountNum;
    cout<<", 계좌 소유주 명 : "<<name<<", 잔고 : "<<balance<<"\n";
}
//입금
void Account::deposit(int money){
    balance+=money;
    cout<<accountNum<<"계좌에 "<<money<<"메소 입금\n";
}
//출금
void Account::withdraw(int money){
    balance-=money;
    cout<<accountNum<<"계좌에서 "<<money<<"메소 출금\n";
}
//잔고확인
void Account::getBalance(){
    cout<<accountNum<<"계좌의 현재 잔고는 "<<balance<<"메소 입니다\n";
}
//현황출력
void Show(Account *pAcc){
    for(int i=0;i<4;i++){
        cout<<i+1<<"번 ";
        pAcc[i].prn();
    }
}
//잔고출력
void Show_balance(Account *pAcc){
    for(int i=0;i<4;i++){
        pAcc[i].getBalance();
    }
}
int main(){
    //객체 배열
    Account arr[4] = {
        Account("20-700","ENFP",45000),
        Account("45-711","ENFJ",65000),
        Account("84-280","ISFJ",105000),
        Account("27-413","INTJ",80000)
    };
    
    Show(arr);//현황출력
    //진행
    arr[0].deposit(100000);
    arr[0].withdraw(30000);
    arr[1].deposit(400000);
    arr[2].withdraw(33000);
    arr[3].deposit(220000);
    Show_balance(arr);//잔고출력
    return 0;
}
