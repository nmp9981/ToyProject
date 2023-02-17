#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    void setRadius(int radius);
    double getArea();
};

void Circle::setRadius(int radius){
    this->radius = radius;
}

double Circle::getArea(){
    return 3.14*radius*radius;
}

int main()
{
    int radius;
    Circle *pArray = new Circle[3];//3개 배열 할당
    for(int i=0;i<3;i++){
        cout<<"원 "<<i+1<<"의 반지름 : ";
        cin>>radius;
        pArray[i].setRadius(radius);//각 객체를 초기화
    }
    
    int count = 0;//카운트 변수
    Circle* p = pArray;
    for(int i=0;i<3;i++){
        if(p->getArea()>100) count++;
        p++;
    }
    cout<<"면적이 100보다 큰 원은 "<<count<<"개 입니다.";
    delete [] pArray;
    return 0;
}
