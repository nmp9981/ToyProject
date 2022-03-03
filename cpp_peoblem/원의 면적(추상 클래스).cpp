#include <iostream>
using namespace std;

double x;//반지름
const double pi = 3.141592;
//추상 클래스
class Shape{
    protected ://외부에서 사용 못하게
        double area;
    public : 
        virtual void draw()=0;//완전 가상함수
        virtual double GetSize()=0;
};
//원 클래스
class Circle : public Shape{
    protected : 
        double radius;
    public :
        Circle(double r=0);//생성자
        void draw();//오버라이딩
        double GetSize();
};
Circle::Circle(double r){
    radius = r;
}
//오버라이딩된 두 가상함수
void Circle::draw(){
    cout<<"원을 그린다.\n";
}
double Circle::GetSize(){
    return area = radius*radius*pi;
}
int main(){
    cin>>x;
    Circle Obj(x);
    Obj.draw();
    cout<<"면적 : ";
    printf("%.2f",Obj.GetSize());
    return 0;
}
