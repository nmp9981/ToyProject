#include <iostream>
#include <string>
using namespace std;

//Integer 클래스
class Integer{
private:
    int integer;
public:
    Integer(int i){integer = i;}//생성자
    Integer(string s){integer = stoi(s);}//생성자, 정수로 변환
    
    void set(int x){integer = x;}//수 변경
    int get(){//정수 반환
        return integer;
    }
    bool isEven(){return integer%2?false:true;}//짝수인가?
};

int main()
{
    Integer n(30);
    cout<<n.get()<<" ";//30출력
    n.set(50);
    cout<<n.get()<<" ";//50출력
    
    Integer m("300");
    cout<<m.get()<<" ";//300출력
    cout<<m.isEven();//1출력
    return 0;
}
