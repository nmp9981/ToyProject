#include <iostream>
using namespace std;
//숫자 구조체
struct X{
    int r_num,i_num;
};
//복소수 객체
class Complex{
    private : 
        int real;
        int image;
    public : 
        Complex(int r=0,int i=0);
        void prn() const;
        Complex operator*(Complex right);
};
//출력
void Complex::prn() const{
    if(image>0) cout<<real<<"+"<<image<<"i\n";
    else if(image<0) cout<<real<<image<<"i\n";
    else cout<<real<<"\n";
}
//생성자(초기화)
Complex::Complex(int r,int i){
    real = r;image = i;
}
//복소수 곱셈
Complex Complex::operator*(Complex right){
    Complex res;
    res.real = (this->real*right.real)-(this->image*right.image);
    res.image = (this->image*right.real)+(this->real*right.image);
    return res;
}
int main(){
    X a,b;//두 숫자
    cin>>a.r_num>>a.i_num>>b.r_num>>b.i_num;//입력
    Complex x(a.r_num,a.i_num),y(b.r_num,b.i_num),z;//객체 정의
    z = x*y;
    z.prn();
    return 0;
}
