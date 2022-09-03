#include <iostream>
using namespace std;

//좌표
class Point {
private:
	int xpos, ypos;
public:
	void init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void show() const {
		cout << "[ " << xpos << " , " << ypos << " ]\n";
	}
};
//원
class Circle {
private:
	Point center;//중심좌표
	int radius;//반지름
public:
	void init(int x,int y, int r) {
		center.init(x,y);
		radius = r;
	}
	void show() const {
		cout << "radius : " << radius << "\n";
		center.show();
	}
};
//링
class Ring {
private:
	Circle inCircle;
	Circle outCircle;
public:
	void init(int x1, int y1, int r1, int x2, int y2, int r2) {
		inCircle.init(x1, y1, r1);
		outCircle.init(x2, y2, r2);
	}
	void ShowRingInfo() const {
		cout << "inner clrcle\n";
		inCircle.show();
		cout << "outter circle\n";
		outCircle.show();
	}
};
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	Ring ring;
	ring.init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
    return 0;
}
