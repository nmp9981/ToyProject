#include "car.h"

int main() {
	Car recky;
	recky.InitMembers("recky", 100);
	recky.Accel();
	recky.Accel();
	recky.Accel();
	recky.ShowCarState();
	recky.Break();
	recky.ShowCarState();
	return 0;
}
