#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996) // C4996 에러를 무시

class Rectangle {
private:
	int width, height;
public:
	Rectangle(int wid, int hei) : width(wid), height(hei) {}
	void ShowAreaInfo(){
		cout << "면적 : " << width * height << "\n";
	}
};
class Square:public Rectangle {
public:
	Square(int side) :Rectangle(side, side) {}
};
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}
