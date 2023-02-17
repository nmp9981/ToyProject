#include <iostream>
using namespace std;
typedef long long ll;

class Cube{
    ll side;
public:
    Cube();
    Cube(ll s);
    ~Cube(){};
    void setCube(ll s) {side = s;}
    ll getVolume(){return side*side*side;}
};

Cube::Cube(){
    side = 1;
}

Cube::Cube(ll s){
    side = s;
}

int main()
{
    cout<<"생성하고자 하는 정육면체의 개수";
    int n,side;
    cin>>n;
    if(n<=0) return 0;
    
    Cube *pArray = new Cube[n];//n개 배열 할당
    for(int i=0;i<n;i++){
        cout<<"정육면체"<<i+1<<" : ";
        cin>>side;
        pArray[i].setCube(side);//각 객체를 초기화
    }
    
    int count = 0;//카운트 변수
    Cube* p = pArray;
    for(int i=0;i<n;i++){
        cout<<p->getVolume()<<" ";
        if(p->getVolume()>=8000 && p->getVolume()<32000) count++;
        p++;
    }
    cout<<"\n";
    cout<<count;
    delete [] pArray;
    return 0;
}
