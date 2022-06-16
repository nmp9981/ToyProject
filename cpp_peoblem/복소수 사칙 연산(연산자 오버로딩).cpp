#include <iostream>
using namespace std;

class Complex {//복소수 클래스
private:
    double real,image;
public:
    Complex(double real, double image) : real(real), image(image) {}//생성자
    Complex(const Complex& c) { real = c.real, image = c.image; }//복사 생성자
    //사칙연산
    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;
    Complex& operator=(const Complex& c);//대입

    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);
    void print() const;//출력
};

//사칙연산
Complex Complex::operator+(const Complex& c) const {
    Complex temp(real + c.real, image + c.image);
    return temp;
}
Complex Complex::operator-(const Complex& c) const {
    Complex temp(real - c.real, image - c.image);
    return temp;
}
Complex Complex::operator*(const Complex& c) const {
    Complex temp(real*c.real-image*c.image, c.real*image+real*c.image);
    return temp;
}
Complex Complex::operator/(const Complex& c) const {
    Complex temp((real * c.real + image * c.image)/(c.real*c.real+c.image*c.image), (c.real * image - real * c.image)/(c.real * c.real + c.image * c.image));
    return temp;
}
//사칙연산 대입
Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}

//대입
Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    image = c.image;

    return *this;
}
//출력
void Complex::print() const{
    cout << real << " " << image << "i\n";
}

int main() {

    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);

    Complex c(0,0);

    c = a * b + a / b + a + b;
    c.print();
    a += b;
    a.print();
    return 0;
}
