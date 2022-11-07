#include <iostream>
#include <vector>
using namespace std;

int n,m;//우변, 항의 개수
bool flag = false;//해 존재여부
const int maxi = 15;
int cal[maxi];//계수
vector<int> sol;//해

//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < m; i++) cin >> cal[i];
}
//풀이
void solve(int m, int cnt) {
	if (cnt == m) {
		int sum = 0;
		for (int j = 0; j < m; j++) sum += (sol[j] * cal[j]);
		if (sum == n) {
			flag = true;
			for (int j = 0; j < m; j++) cout << sol[j] << " ";
			cout << "\n";
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		sol.push_back(i);
		solve(m, cnt + 1);
		sol.pop_back();
	}
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	solve(m,0);//풀이
	if(flag == false) cout << "해가 존재하지 않음";
	return 0;
}
