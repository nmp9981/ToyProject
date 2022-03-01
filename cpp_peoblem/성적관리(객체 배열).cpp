#include <iostream>
using namespace std;
//제목
void title(){
    cout<<"번호\t이름\tmath physical computer history\ttotal\taverage\n";
}

//과목 클래스
class Student{
    private :
        string name;
        int math;
        int physical;
        int computer;
        int history;
        int total;
        double avg;
    public :
        Student(string n="카이저", int m=0,int p=0,int c=0,int h=0);
        void Calculate();
        void prn() const;
};
 
//출력
void Student::prn() const{
    cout<<name<<"\t"<<math<<"\t"<<physical;
    cout<<"\t"<<computer<<"\t"<<history<<"\t"<<total<<"\t"<<avg<<"\n";
}
//생성자
Student::Student(string n,int m,int p,int c,int h){
    name = n;
    math = m;
    physical = p;
    computer = c;
    history = h;
    total = 0;
    avg = 0;
}
//멤버함수
void Student::Calculate(){
    total = math+physical+computer+history;
    avg = (double)total/4;
}
//총점 및 평균 계산
void Cal(Student *pStu){
    for(int i=0;i<5;i++) pStu[i].Calculate();
}
//출력
void Show(Student *pStu){
    for(int i=0;i<5;i++){
        cout<<i+1<<"\t";
        pStu[i].prn();
    }
}
int main(){
    //객체 배열
    Student arr[5] = {
        Student("아크",98,85,95,76),
        Student("팬텀",60,80,72,100),
        Student("비숍",85,63,90,88),
        Student("신궁",84,77,92,81),
        Student("은월",75,67,87,73)
    };
    title();//제목
    Cal(arr);//총점 및 평균계산
    Show(arr);//출력
    return 0;
} 
