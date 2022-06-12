#include <iostream>
using namespace std;

class MyString{
    char* string_content;//문자열 데이터를 가리키는 포인터
    int string_length;//문자열 길이

public:
    MyString(char c);//문자 하나로 생성
    MyString(const char* str);//문자열로부터 생성
    MyString(const MyString& str);//복사 생성자

    ~MyString();

    int length() const;//문자열 길이 리턴
    void print() const;//출력
};

//생성자
MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);//입력 문자열의 길이
    string_content = new char[string_length];//배열 정의

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
//복사 생성자
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];//배열 정의
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}
//소멸자
MyString::~MyString() { delete[] string_content;}

//문자열 길이 리턴
int MyString::length() const { return string_length; }

//문자열 길이 출력
void MyString::print() const {
    for (int i = 0; i!= string_length; i++) cout << string_content[i];
    cout << "\n";
}

int main() {
    MyString str1("hello world");
    MyString str2(str1);

    str1.print();
    cout<<str2.length();
    return 0;
}
