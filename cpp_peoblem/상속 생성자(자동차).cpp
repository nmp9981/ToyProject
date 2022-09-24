#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996) // C4996 에러를 무시

class Car {
private:
	int gasolineGauge;
public:
	Car(int myGasoline) :gasolineGauge(myGasoline) {}
	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car {
private:
	int electricGauge;
public:
	HybridCar(int myGasoline, int myelectric) : Car(myGasoline), electricGauge(myelectric) {}
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;
public:
	HybridWaterCar(int myGasoline, int myelectric, int mywater) : HybridCar(myGasoline, myelectric), waterGauge(mywater) {}
	void ShowCurrentGauge() {
		cout << "잔여 가솔린 : " << GetGasGauge() << "\n";
		cout << "잔여 전기량 : " << GetElecGauge() << "\n";
		cout << "잔여 워터량 : " << waterGauge << "\n";
	}
};

int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	HybridWaterCar hybrridWaterCar(100,100,100);
	hybrridWaterCar.ShowCurrentGauge();
    return 0;
}
