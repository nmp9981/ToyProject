#include <iostream>
#include <string>
#include <vector>
using namespace std;

//큰 수 클래스
class bigInt {
private:
    string number;//숫자
public:
    bigInt(string n = "");//생성자
    inline int max(int a, int b);//min
    void Show() const;//결과
    bool operator<(const bigInt& num);//<
    bool operator>(const bigInt& num);//>
    bigInt operator+(const bigInt& num);//+
    bigInt operator-(const bigInt& num);//-
    bigInt operator*(const bigInt& num);//*
    bigInt operator/(const bigInt& num);// /
    bigInt operator%(const bigInt& num);//%
};
//생성자
bigInt::bigInt(string n) {
    number = n;
}
//max
inline int bigInt::max(int a, int b) {
    return a > b ? a : b;
}
//계산 결과
void bigInt::Show() const {
    cout << number << "\n";
}
//n1 < n2
bool bigInt::operator<(const bigInt& n) {
    string n1 = this->number;//
    string n2 = n.number;
    int n1_size = n1.size(); int n2_size = n2.size();

    if (n1_size < n2_size) return true;//n2의 자릿수가 더 크다
    else if (n1_size > n2_size) return false;//n1의 자릿수가 더 크다
    else {//자릿수가 같다
        for (int i = 0; i < n1_size; i++) {//각 자릿수 비교
            if ((n1[i] - '0') < (n2[i] - '0')) return true;
            else if ((n1[i] - '0') > (n2[i] - '0')) return false;
        }
    }
    return false;
}
//n1 > n2
bool bigInt::operator>(const bigInt& n) {
    string n1 = this->number;//
    string n2 = n.number;
    int n1_size = n1.size(); int n2_size = n2.size();

    if (n1_size < n2_size) return false;//n2의 자릿수가 더 크다
    else if (n1_size > n2_size) return true;//n1의 자릿수가 더 크다
    else {//자릿수가 같다
        for (int i = 0; i < n1_size; i++) {//각 자릿수 비교
            if ((n1[i] - '0') > (n2[i] - '0')) return true;
            else if ((n1[i] - '0') < (n2[i] - '0')) return false;
        }
    }
    return false;
}
//+
bigInt bigInt::operator+(const bigInt& n) {
    bigInt ans;//최종 결과
    string res = "";//계산 결과
    string n1 = this->number;
    string n2 = n.number;
    int n1_size = n1.size(); int n2_size = n2.size();
    //두 문자열의 사이즈를 같게한다.(ex, 1999, 14=>1999 ,0014)
    string zero = "";
    if (n1_size < n2_size) {
        for (int i = 0; i < n2_size - n1_size; i++) zero += '0';
        n1 = zero + n1;
    }
    else if (n1_size > n2_size) {
        for (int i = 0; i < n1_size - n2_size; i++) zero += '0';
        n2 = zero + n2;
    }
    //일의 자리수부터 더해나간다.
    int cal_size = max(n1_size, n2_size);//계산 사이즈
    int up = 0;//받아 올림 여부
    //계산
    for (int i = 1; i <= cal_size; i++) {
        int dit = (n1[cal_size - i] - '0') + (n2[cal_size - i] - '0') + up;
        if (dit >= 10) {
            dit -= 10;
            up = 1;
        }
        else up = 0;
        res += to_string(dit);
    }
    if (up == 1) res += to_string(up);
    //문자열 바로 붙이기
    for (int i = res.size() - 1; i >= 0; i--) ans.number += res[i];
    return ans;
}
//-
bigInt bigInt::operator-(const bigInt& n) {
    bigInt ans;//최종 결과
    string res = "";//계산 결과
    string n1 = this->number;
    string n2 = n.number;
    int n1_size = n1.size(); int n2_size = n2.size();
    //두 문자열의 사이즈를 같게한다.(ex, 1999, 14=>1999 ,0014)
    string zero = "";
    if (n1_size < n2_size) {
        for (int i = 0; i < n2_size - n1_size; i++) zero += '0';
        n1 = zero + n1;
    }
    else if (n1_size > n2_size) {
        for (int i = 0; i < n1_size - n2_size; i++) zero += '0';
        n2 = zero + n2;
    }
    //일의 자리수부터 뺄셈을 한다.
    int cal_size = max(n1_size, n2_size);//계산 사이즈
    int down = 0;//받아 내림 여부
    //계산
    for (int i = 1; i <= cal_size; i++) {
        int dit = (n1[cal_size - i] - '0') - (n2[cal_size - i] - '0') - (down / 10);
        if (dit < 0) {//음수여서 받아 내림을 해야한다.
            dit += 10;
            down = 10;
        }
        else down = 0;
        res += to_string(dit);
    }
    //앞 0제거
    int zeroIndex = 0;//답이 0일 수 있다.
    for (int i = res.size() - 1; i >= 0; i--) {
        if (res[i] != '0') {
            zeroIndex = i;
            break;
        }
    }
    //문자열 바로 붙이기
    for (int i = zeroIndex; i >= 0; i--) ans.number += res[i];
    return ans;
}
//*
bigInt bigInt::operator*(const bigInt& n) {
    bigInt ans;//최종 결과
    string n1 = this->number;
    string n2 = n.number;
    int n1_size = n1.size();int n2_size = n2.size();
    
    //0을 곱함
    if (n1 == "0" || n2 == "0") {
        ans.number = "0";
        return ans;
    }
    //계산 결과 배열 할당
    vector<vector<int>> mulArray;
    for (int j = 0; j < n2_size; j++) {
        vector<int> zero;
        for (int i = 0; i < n1_size; i++) zero.push_back(0);
        mulArray.push_back(zero);
    }

    //초등학교 알고리즘 적용(o(n2))
    for (int j = 0; j < n2_size; j++) {
        for (int i = 0; i < n1_size; i++) mulArray[n2_size - j - 1][i] = (n1[i] - '0') * (n2[j] - '0');
    }
    //열 증가
    string res = "";
    int digit = 0;//결과 값
    for (int k = n1_size - 1; k >= 0; k--) {//기준점
        int row = 0; int col = k;//기준 좌표
        //대각선으로 더하기
        while (col - row == k) {
            digit += mulArray[row][col];
            col++; row++;
            if (row >= n2_size || col >= n1_size) break;//배열 범위 초과
        }
        res += to_string(digit % 10);//문자열 붙이기
        digit = digit / 10;
    }
    //행 증가
    for (int k = 1; k < n2_size; k++) {//기준점
        int row = k; int col = 0;//기준 좌표
        //대각선으로 더하기
        while (row - col == k) {
            digit += mulArray[row][col];
            col++; row++;
            if (row >= n2_size || col >= n1_size) break;//배열 범위 초과
        }
        res += to_string(digit % 10);//문자열 붙이기
        digit = digit / 10;
    }
    //문자열 바로 붙이기(up, 맨 앞자리에 오는것부터)
    if (digit > 0) ans.number += to_string(digit);
    for (int i = res.size() - 1; i >= 0; i--) ans.number += res[i];
    return ans;
}
// / (n1/n2), 몫 구하기
bigInt bigInt::operator/(const bigInt& n) {
    bigInt ans;//최종 결과
    string n1 = this->number;//나눠야하는 수
    bigInt n2 = n.number;//나누는 수
    int n1_size = n1.size();//n1의 자릿수

    if (n2.number == "0") return ans.number = "INF\n";//0으로 나눔
    if ((bigInt)n1 < n2) return ans.number = "0";//몫이 0

    //몫이 존재, 초등학교 알고리즘 적용
    string share = "";//몫
    string divided; bigInt dividNum; bigInt ten;
    dividNum.number = "0";
    for(int i=0;i<n1_size;i++) {
        divided = n1[i];//나눗셈을 진행할 문자열
        ten.number = "10";//10
        dividNum = dividNum * ten + (bigInt)(divided);//나누어지는 수
        if (dividNum < n2) share+=to_string(0);//0 출력
        else {//나눌 수 있음
            int minusCount = 0;
            while (true) {
                if (dividNum < n2) break;//뺄셈 종료
                dividNum = dividNum - n2;
                minusCount++;
            }
            share += to_string(minusCount);//몫 구하기
        }
    }
    //출력
    int frontZero = 0;//맨 앞이 0
    for (int i = 0; i < share.size(); i++) {
        if (share[i] != '0') {
            frontZero = i;
            break;
        }
    }
    ans.number = share.substr(frontZero);//정답
    return ans;
}

// / (n1%n2), 나머지 구하기
bigInt bigInt::operator%(const bigInt& n) {
    bigInt ans;//최종 결과
    string n1 = this->number;//나눠야하는 수
    bigInt n2 = n.number;//나누는 수
    int n1_size = n1.size();//n1의 자릿수

    if (n2.number == "0") return ans.number = "NO\n";//0으로 나눔, 나머지가 존재하지 않음
    if ((bigInt)n1 < n2) return ans.number = n1;//몫이 0이므로 n1 그대로

    //몫이 존재, 초등학교 알고리즘 적용
    string divided; bigInt dividNum; bigInt ten;
    dividNum.number = "0";
    for (int i = 0; i < n1_size; i++) {
        divided = n1[i];//나눗셈을 진행할 문자열
        ten.number = "10";//10
        dividNum = dividNum * ten + (bigInt)(divided);//나누어지는 수
        if (dividNum < n2) { }
        else {//나눌 수 있음
            while (true) {
                if (dividNum < n2) break;//뺄셈 종료
                dividNum = dividNum - n2;
            }
        }
    }
    ans = dividNum;//정답
    return ans;//나머지
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    bigInt x(s1), y(s2);//큰 수 정의
    //크기 비교
    if (x > y) cout << "x승\n";
    else cout << "y승\n";
    //덧셈
    bigInt add = x + y;
    add.Show();
    //뺄셈
    bigInt minus = x - y;
    minus.Show();
    //곱셈
    bigInt multi = x * y;
    multi.Show();
    //나눗셈
    bigInt division = x / y;
    division.Show();
    //나머지
    bigInt rest = x % y;
    rest.Show();
    return 0;
}
