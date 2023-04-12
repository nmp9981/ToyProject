#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache{
    list<int> page;//페이지 리스트
    unordered_map<int,list<int>::iterator> ma;//해시맵
    int csize;//캐시 사이즈
public:
    LRUCache(int);//생성자
    void refer(int);//LRU
    void display();//출력
};
//생성자(사이즈 초기화)
LRUCache::LRUCache(int n){
    csize = n;
}

//큐에 원소 넣기
void LRUCache::refer(int x){
    //cache에 없다면
    if(ma.find(x)==ma.end()){
        //캐시가 가득 찼다면
        if(page.size()==csize){
            //LRU요소 삭제
            int last = page.back();//맨 마지막 요소
            page.pop_back();
            ma.erase(last);//맨 마지막 요소의 주소도 삭제
        }
    }else{//cache에 있다면
        //erase()는 주소값 삭제
        page.erase(ma[x]);//원소 x의 주소 삭제
    }
    
    page.push_front(x);//원소를 큐에 앞에 넣는다.
    ma[x] = page.begin();//주소 갱신
}
//출력
void LRUCache::display(){
    for(auto i=page.begin();i!=page.end();i++){
        cout<<(*i)<<" ";
    }
    cout<<"\n";
}
int main()
{
    LRUCache ca(4);//페이지 크기 4
    
    //원소 넣기
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}
