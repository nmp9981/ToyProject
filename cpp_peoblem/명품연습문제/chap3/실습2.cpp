#include <iostream>
#include <string>
using namespace std;

//Date 클래스
class Date{
private:
    int year;
    int month;
    int day;
public:
    Date(int y, int m, int d);//생성자
    Date(string s);//생성자
    
    void show(){
        cout<<year<<"년"<<month<<"월"<<day<<"일\n";
    }
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}
};
//생성자
Date::Date(int y,int m,int d){
    year = y;
    month = m;
    day = d;
}
Date::Date(string s){//문자열을 쪼개 정수로 변환
    year = stoi(s.substr(0,4));
    month = stoi(s.substr(5,1));
    day = stoi(s.substr(7,2));
}

int main()
{
    Date birth(2014,3,20);
    Date independenceDay("1945/8/15");
    independenceDay.show();
    cout<<birth.getYear()<<","<<birth.getMonth()<<","<<birth.getDay()<<"\n";
    return 0;
}
