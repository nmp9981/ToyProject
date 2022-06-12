#include <iostream>
using namespace std;

class MyString{
    char* string_content;//문자열 데이터를 가리키는 포인터
    int string_length;//문자열 길이
    int memory_capacity;//할당된 메모리 공간 크기

public:
    MyString(char c);//문자 하나로 생성
    MyString(const char* str);//문자열로부터 생성
    MyString(const MyString& str);//복사 생성자

    ~MyString();//소멸자

    int length() const;//문자열 길이 리턴
    int capacity() const;//메모리 용량 리턴
    void print() const;//출력
    MyString& assign(const char* str);//문자열 대입
    MyString& insert(int loc, const MyString& str);//문자열 삽입
    char at(int i) const;//임의 위치의 문자 출력
};

//생성자
MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);//입력 문자열의 길이
    memory_capacity = string_length;//메모리 공간
    string_content = new char[string_length];//배열 정의

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
//복사 생성자
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];//배열 정의
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}
//소멸자
MyString::~MyString() { delete[] string_content;}

//문자열 길이 리턴
int MyString::length() const { return string_length; }

//메모리 용량 리턴
int MyString::capacity() const { return memory_capacity; }

//문자열 길이 출력
void MyString::print() const {
    for (int i = 0; i!= string_length; i++) cout << string_content[i];
    cout << "\n";
}

//assign
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > string_length) {//기존보다 길다면 재할당
        delete[] string_content;//제거 후 재할당

        string_content = new char[str_length];//재할당
        memory_capacity = str_length;//현재 할당된 메모리 공간의 크기
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }
    string_length = str_length;

    return *this;
}

//문자열 삽입, 위치 loc 바로 앞에 문자 삽입
MyString& MyString::insert(int loc, const MyString& str) {
    //범위내에 드는가?
    if (loc < 0 || loc >= string_length) return *this;

    //동적할당
    if (string_length + str.string_length > memory_capacity) {
        memory_capacity = string_length + str.string_length;//새 크기

        char* prev_string_content = string_content;//이전 문자열
        string_content = new char[memory_capacity];

        //loc이전 문자열까지 복사
        for (int i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }

        //새롭게 insert되는 문자열을 넣는다
        for (int j = 0; j != str.string_length; j++) {
            string_content[loc + j] = str.string_content[j];
        }

        //나머지 뒷부분 목사
        for (int i = loc; i < string_length; i++) {
            string_content[str.string_length+i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    }

    //초과하지 않는 경우
    //효율적으로 insert하기 위해, 밀리는 부분을 먼저 뒤로 밀어낸다
    for (int i = string_length - 1; i >= loc; i--) {
        //뒤로 밀기
        string_content[i + str.string_length] = string_content[i];
    }
    //insert문자 넣기
    for (int i = 0; i < str.string_length; i++) {
        string_content[i + loc] = str.string_content[i];
    }
    string_length = string_length + str.string_length;
    return *this;
}
//i번에 있는 문자 출력
char MyString::at(int i) const {
    if (i >= string_length || i < 0) return NULL;
    else return string_content[i];
}

int main() {
    MyString str1("hello world");
    MyString str2(str1);

    str1.print();
    cout<<str2.length()<<"\n";

    str1.assign("The Dark knight's dark impale is a skill gained after changing jobs for the fourth time");
    str1.print();
    cout<<" : " << str1.capacity() << "\n";
    str1.assign("cube");
    cout << str1.at(3) << "\n";//3번째 문자 출력
    return 0;
}
