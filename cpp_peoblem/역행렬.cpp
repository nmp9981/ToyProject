#include <iostream>
using namespace std;

class Matrix {
private:
	static const int maxi = 501;
	int n;//행렬 크기
	double M[maxi][2*maxi];//행렬
	bool isInverse;//역행렬 존재 여부
public:
	Matrix();//생성자
	void input();//입력
	bool IsInverse();//역행렬 존재 여부
	void Gause();//가우스 소거법
	void output();//출력
};
//생성자
Matrix::Matrix() {
	n = 0;
	isInverse = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) M[i][j] = 1;
	}
}
//입력
void Matrix::input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> M[i][j];
	}
	//뒷부분 초기 단위행렬 세팅
	for (int i = 0; i < n; i++) {
		for (int j = n; j < 2*n; j++) {
			if (i + n == j) M[i][j] = 1;
			else M[i][j] = 0;
		}
	}
}
//역행렬 존재 여부
bool Matrix::IsInverse() {
	for (int i = 0; i < n; i++) {
		int zeroCnt = 0;
		//0행렬 검사
		for (int j = 0; j < n; j++) {
			if (M[i][j] == 0) zeroCnt++;
		}
		if (zeroCnt == n) return false;//한 행이 모두 0이면 역행렬이 존재하지 않는다.
	}
	return true;
}
//가우스 소거법
void Matrix::Gause() {
	for (int j = 0; j < n; j++) {//각 열에 대해
		//M[j][j] = 1로 만들기, 계산 기준 행
		double div = M[j][j];
		for (int k = 0; k < 2*n; k++) {//M[j][j]로 나누기
			if(div!=0) M[j][k] = M[j][k] / div;
		}
		//나머지 행
		for (int i = 0; i < n; i++) {//각 행을 검사
			if (i == j) continue;//이미 j행은 계산 완료
			float mul = M[i][j];//곱하는 수
			for (int k = 0; k < 2 * n; k++) {
				M[i][k] = (-1.0)*mul*M[j][k] + M[i][k];//행 연산
			}
		}
		//0행렬 검사
		if (!IsInverse()) {
			isInverse = false;
			break;
		}
	}
}
//출력
void Matrix::output() {
	if (isInverse == false) cout << "no Inverse";
	else {
		for (int i = 0; i < n; i++) {
			for (int j = n; j < 2*n; j++) {
				cout << M[i][j] << " ";
			}
			cout << "\n";
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Matrix matrix;
	matrix.input();//입력
	matrix.Gause();//가우스 소거법
	matrix.output();//출력
	return 0;
}
