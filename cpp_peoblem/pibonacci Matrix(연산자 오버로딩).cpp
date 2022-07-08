#include <iostream>
#include <array>
#define endl '\n'
using namespace std;
const long long mod = 1000000007;
const int siz = 2;
using Matrix = array<array<long long, siz>, siz>;//자료형 정의

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
	Matrix ret{};
	for (int i = 0; i < siz; i++) {
		for (int j = 0; j < siz; j++) {
			for (int k = 0; k < siz; k++) {
				ret[i][j] += (lhs[i][k] * rhs[k][j]) % mod;
				ret[i][j] %= mod;
			}
		}
	}
	return ret;
}

Matrix pow(const Matrix& mat, long long fac) {
	if (fac == 1) return mat;

	Matrix ret;
	if (fac % 2 == 0) {
		ret = pow(mat, fac / 2);
		ret = ret * ret;
	}
	else {
		ret = pow(mat, fac - 1) * mat;
	}
	return ret;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;
	Matrix mat;
	mat[0] = { 1,1 };
	mat[1] = { 1,0 };

	mat = pow(mat, n);
	cout << mat[0][1]<<endl;
	return 0;
}
