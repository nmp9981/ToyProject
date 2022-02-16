//벡터를 활용한 로또 복권 모의실험
#include <iostream>
#include <vector>
#include <set>
#include <time.h>
#include <algorithm>
using namespace std;

void PrintElement(int n){
    cout<<n<<"\t";
}

//로또 번호를 저장하는 클래스
class LottoGenerator{
    public : 
        vector<int> ball;//로또 번호를 저장할 벡터 선언
        
        LottoGenerator(int count){
            makeRandom(count);
        }
        //6개 뽑기
        LottoGenerator(){
            makeRandom(6);
        }
        //1~45숫자 6개 고르기
        set<int> RangedRandDemo(int range_min,int range_max,int n){
            set<int> s;//중복 방지를 위해 set사용
            while(1){
                int u = (double)rand()/RAND_MAX*(range_max-range_min)+range_min;
                s.insert(u);
                if(s.size()>=n){//6개 모두 뽑음
                    break;
                }
            }
            return s;
        }
        
        void makeRandom(int count){
            set<int> s;
            s = RangedRandDemo(1,46,count);
            
            set<int>::iterator iter;
            for(iter = s.begin();iter!=s.end();iter++){
                this->ball.push_back(*iter);
            }
        }
        //번호 6개 출력
        void lottprn(){
            for_each(this->ball.begin(),this->ball.end(),PrintElement);
            cout<<"\n";
        }
};
//응모한 번호 저장
class UserLotto{
    public : 
        int pos;//복권의 번호(순서)
        LottoGenerator lotto;//구입한 로또 객체 선언
        int grade;//등수
        
        UserLotto(){
            grade = 0;
        }
};

void line(){
    cout<<"************************************************************\n";
}

void title(){
    cout<<"로또 복권 모의실험 프로그램\n";
    line();
    cout<<"1등 6개 숫자 일치 (보너스 숫자 제외) :총 상금은 2,100,000,000메소\n";
    cout<<"2등 6개 중 5개 일치 + 1개 보너스 숫자 일치 :총 상금은 400,000,000메소\n";
    cout<<"3등 5개 숫자 일치 (보너스 숫자 제외):총 상금은 70,000,000메소\n";
    cout<<"4등 4개 숫자 일치 (보너스 숫자 제외):총 상금은 18,000,000메소\n";
    cout<<"5등 3개 숫자 일치 (보너스 숫자 제외):총 상금은 500,000메소\n";
    cout<<"6등 2개 숫자 일치 (보너스 숫자 제외):총 상금은 100,000메소\n";
    cout<<"7등 1개 숫자 일치 (보너스 숫자 제외):총 상금은 15,000메소\n";
    cout<<"8등 0개 숫자 일치 (보너스 숫자 제외):총 상금은 0메소\n";
    line();
}
//실제 수령 상금 출력
void Lotto(UserLotto user){
    switch(user.grade){
        case 1:
            cout<<"1등(총 상금 2,100,000,000메소):";
            break;
        case 2:
            cout<<"2등(총 상금 400,000,000메소):";
            break;
        case 3:
            cout<<"3등(총 상금 70,000,000메소):";
            break;
        case 4:
            cout<<"4등(총 상금 18,000,000메소):";
            break;
        case 5:
            cout<<"5등(총 상금 500,000메소):";
            break;
        case 6:
            cout<<"6등(총 상금 100,000메소):";
            break;
        case 7:
            cout<<"7등(총 상금 15,000메소):";
            break;
        case 8:
            cout<<"8등(총 상금 0메소):";
            break;
    }
    //당첨되면
    if(user.grade>=1 && user.grade<=8){
        cout<<"\n NO "<<user.pos<<" : ";
        user.lotto.lottprn();
    }
}
//응모한 당첨번호와 일치되는 개수로 등수를 구함
void counts(vector<UserLotto> user, LottoGenerator lotto){
    int matchingcount;//일치하는 개수 
    vector<int>::iterator num1,num2;
    //1~userCount번까지의 유저의 입력
    for(int i=0;i<user.size();i++){
        matchingcount = 0;
        //당첨번호 6개로 반복문을 돌림
        for(num1=lotto.ball.begin();num1<lotto.ball.end()-1;num1++){
            //응모한 번호 6개로 반복문을 돌림
            for(num2=user[i].lotto.ball.begin();num2<user[i].lotto.ball.end();num2++){
                if(*num1 < *num2){//주복 확인 방지
                    break;
                }
                if(*num1 == *num2){
                    matchingcount++;
                }
            }
        }
        //몇개가 일치하는가?
        switch(matchingcount){
            case 0:
                user[i].grade = 8;
                break;
            case 1:
                user[i].grade = 7;
                break;
            case 2:
                user[i].grade = 6;
                break;
            case 3:
                user[i].grade = 5;
                break;
            case 4:
                user[i].grade = 4;
                break;
            case 5:{
                    user[i].grade = 3;
                    //보너스 숫자 비교
                    int bonus=*(lotto.ball.end()-1);
                    vector<int>::iterator iter;
                    iter = find(user[i].lotto.ball.begin(),user[i].lotto.ball.end(),bonus);
                    if(iter != user[i].lotto.ball.end()){
                        user[i].grade = 2;
                    }
                }
                break;
            case 6:
                user[i].grade = 1;
                break;
            default:
                user[i].grade = 0;
        }
        Lotto(user[i]);
    }
}

int main(){
    vector<UserLotto> user;//구입한 로또 저장
    int userCount;//구입한 로또의 개수
    int pos = 1;
    
    title();
    cout<<"로또 개수 입력 : ";
    cin>>userCount;
    
    cout<<"응모한 번호 \n";
    line();
    for(int i=1;i<=userCount;i++){
        UserLotto uselotto;
        uselotto.pos=i;
        cout<<" NO "<<uselotto.pos<<" : ";
        uselotto.lotto.lottprn();
        user.push_back(uselotto);
    }
    
    LottoGenerator lotto(7);//당첨+보너스를 서로 다른 랜덤값으로 구해서 저장하는 객체
    line();
    cout<<"당첨 번호 : ";
    lotto.lottprn();
    cout<<"보 너 스 : "<<lotto.ball[6]<<"\n";
    line();
    
    counts(user,lotto);
    return 0;
}
