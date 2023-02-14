#include <iostream>
using namespace std;

class House{
    int numOfRooms;
    int size;
public:
    House(int n,int s);
    ~House();
};
//생성자
House::House(int n,int s){
    numOfRooms = n;
    size = s;
    cout<<numOfRooms<<" "<<size<<"\n";
}
//소멸자
House::~House(){
    cout<<numOfRooms<<" "<<size<<"소멸\n";//b->c->a->a소멸->d->d소멸->c소멸->b소멸 
}
void f(){
    House a(2,20);
}

House b(3,30),c(4,40);
int main()
{
    f();
    House d(5,50);
    return 0;
}
