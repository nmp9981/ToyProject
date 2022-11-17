#include <iostream>
using namespace std;

//큰 수 클래스
class bigInt{
private:
    string number;//숫자
public:
    bigInt(string n = "");//생성자
    inline int max(int a,int b);//min
    void Show();//결과
    bigInt operator+(const bigInt &num);//+
};
//생성자
bigInt::bigInt(string n){
    number = n;
}
//max
inline int bigInt::max(int a,int b){
    return a>b?a:b;
}
//계산 결과
void bigInt::Show(){
    cout<<number<<"\n";
}

//+
bigInt bigInt::operator+(const bigInt &n){
    bigInt ans;//최종 결과
    string res = "";//계산 결과
    string n1 = this->number;
    string n2 = n.number;
    int n1_size = n1.size();
    int n2_size = n2.size();
    //두 문자열의 사이즈를 같게한다.(ex, 1999, 14=>1999 ,0014)
    string zero ="";
    if(n1_size<n2_size){
        for(int i=0;i<n2_size-n1_size;i++) zero+='0';
        n1 = zero+n1;
    }else if(n1_size>n2_size){
        for(int i=0;i<n1_size-n2_size;i++) zero+='0';
        n2 = zero+n2;
    }
    //일의 자리수부터 더해나간다.
    int cal_size = max(n1_size,n2_size);//계산 사이즈
    int up = 0;//받아 올림 여부
    //계산
    for(int i=1;i<=cal_size;i++){
        int dit = (n1[cal_size-i]-'0')+(n2[cal_size-i]-'0')+up;
        if(dit>=10){
            dit-=10;
            up = 1;
        }else up = 0;
        res+=to_string(dit);
    }
    if(up==1) res+=to_string(up);
    //문자열 바로 붙이기
    for(int i=res.size()-1;i>=0;i--) ans.number+=res[i];
    return ans;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    bigInt x(s1),y(s2);//큰 수 
    bigInt z = x+y;
    z.Show();
    return 0;
}
