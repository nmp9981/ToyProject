#include <iostream>
#include <cstring>
using namespace std;

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

public:
    Photon_Cannon(int x, int y, const char *cannon_name);//생성자
    Photon_Cannon(const Photon_Cannon& pc);//복사 생성자
    ~Photon_Cannon();//소멸자

    void show_status();
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {//복사만 가능
    cout << "복사 생성자 호출\n";
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}
Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {
    cout << "생성자 호출\n";
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}

//소멸자
Photon_Cannon::~Photon_Cannon() {
    if (name) delete[] name;
}

void Photon_Cannon::show_status() {
    cout << "Photon Cannon"<<name<<"\n";
    cout << " Location : ( " << coord_x << " , " << coord_y << " )\n";
    cout << " HP : " << hp << "\n";
}
int main() {
    Photon_Cannon pc1(3, 3,"cannon");
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();
    return 0;
}
