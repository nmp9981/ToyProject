#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996) // C4996 에러를 무시

class String {
private:
	int len;
	char* str;
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
	String& operator=(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	String operator+(const String& s);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
};

String::String() {
	len = 0;
	str = NULL;
}
String::String(const char* s) {
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}
String::String(const String& s) {
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}
String::~String() {
	if (str != NULL) {
		delete[]str;
	}
}
//대입 연산
String& String::operator=(const String& s) {
	if (str != NULL) {
		delete[]str;
	}
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}
//+= 연산
String& String::operator+=(const String& s) {
	len += (s.len + 1);//Null이 2번 포함되어 있으므로 1개를 빼야한다.
	char* tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	if (str != NULL) {
		delete[]str;
	}
	str = tempstr;
	return *this;
}
//== 연산
bool String::operator==(const String& s) {
	return strcmp(str, s.str) ? false : true;
}
//+ 연산
String String::operator+(const String& s) {
	char* tempstr = new char[len+s.len-1];//Null이 2번 포함되어 있으므로 1개를 빼야한다.
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	String temp(tempstr);//String temp = tempstr(temp의 생성자)
	delete []tempstr;
	return temp;
}
//<<연산
ostream& operator<<(ostream& os, const String& s) {
	os << s.str;
	return os;
}
//>>연산
istream& operator>>(istream& is, String& s) {
	char str[100];
	is >> str;
	s = String(str);
	return is;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	String str1 = "I like ";
	String str2 = "마작";
	String str3 = str1 + str2;

	cout << str1 << "\n";
	cout << str2 << "\n";
	cout << str3 << "\n";

	str1 += str2;
	if (str1 == str3) {
		cout << "동일 문자열\n";
	}
	else {
		cout << "동일하지 않은 문자열\n";
	}
	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << "\n";
	return 0;
}
