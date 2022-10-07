#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#pragma warning(disable:4996) // C4996 에러를 무시

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {
		cout << "Point 객체 생성\n";
	}
	~Point() {
		cout << "Point 객체 소멸\n";
	}
	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	friend ostream& operator<<(ostream& os, const Point& pos);
};
ostream& operator<<(ostream& os, const Point& pos) {
	os << "[" << pos.xpos << " " << pos.ypos << "]\n";
	return os;
}

class SmartPtr {
private:
	Point* posptr;
public:
	SmartPtr(Point* ptr) :posptr(ptr) {}//동적 할당X
	Point& operator*() const {//스마트 포인터 정의
		return *posptr;
	}
	Point* operator->() const {//스마트 포인터 정의
		return posptr;
	}
	~SmartPtr() {
		delete posptr;
	}
};
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//Point객체를 생성하면서 동시에 SmartPtr객체가 이를 가리키게함, 아래 셋은 Point객체를 가리키는 포인터처럼 동작한다.
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));

	//* 연산
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	//-> 연산
	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;
	return 0;
}
