#include <iostream>
using namespace std;

//Tower 클래스
class Tower{
private:
    int height;
public:
    Tower(){height=1;}//생성자
    Tower(int h){height = h;}//매개변수 1개 생성자
    int getHeight();//높이 반환 함수
};
//높이 반환
int Tower::getHeight(){
    return height;
}

int main()
{
    Tower myTower;
    Tower seoulTower(100);
    cout<<"높이는 "<<myTower.getHeight()<<"m\n";
    cout<<"높이는 "<<seoulTower.getHeight()<<"m\n";
    return 0;
}
