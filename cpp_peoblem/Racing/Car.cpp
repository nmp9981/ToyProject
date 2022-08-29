#include <iostream>
#include <cstring>
#include "car.h"
using namespace std;

//객체 초기화
void Car::InitMembers(const char *ID, int fuel) {
	strcpy_s(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

//차 상태
void Car::ShowCarState() {
	cout << "소유자 ID : " << gamerID << "\n";
	cout << "연료량 : " << fuelGauge << "%\n";
	cout << "현재 속도 : " << curSpeed << "km/h\n";
}

//악셀
void Car::Accel() {
	if (fuelGauge <= 0) return;
	else fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD) {
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

//브레이크
void Car::Break() {
	if (curSpeed < CAR_CONST::BRK_STEP) {
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}
