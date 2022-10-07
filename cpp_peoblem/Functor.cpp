#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#pragma warning(disable:4996) // C4996 에러를 무시

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	Point operator+(const Point& pos) const {//Point객체에 대한 + 연산자 오버로딩
		return Point(xpos + pos.xpos, ypos + pos.ypos);//Point형 임시객체를 생성과 동시에 반환
	}
	friend ostream& operator<<(ostream& os, const Point& pos);
};
ostream& operator<<(ostream& os, const Point& pos) {
	os << "[" << pos.xpos << " " << pos.ypos << "]\n";
	return os;
}
class Adder {
public:
	int operator()(const int& n1,const int& n2) {
		return n1 + n2;
	}
	Point operator()(const Point& pos1, const Point& pos2) {
		return pos1 + pos2;
	}
};
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	Adder adder;
	cout << adder(64, 36)<<"\n";//객체를 함수처럼
	cout << adder(Point(3, 4), Point(7, 9));//함수 호출문에서 임시객체 생성가능
	return 0;
}
