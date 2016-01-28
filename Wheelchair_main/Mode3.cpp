#include "main.h"

void Mode3(void) {

	lcd.locate(0,0); lcd.printf("MODE3    \n");

	Angle = imu.getAngle();

	isControllHeading  = isDetectOverAngle(Angle);
	isControllDistance = !isControllHeading;

	if(SW_ON(2)) isMoving = 1;
}

bool isDetectOverAngle(float angle) {
	return fabs(angle) > OVER_ANGLE ? 1 : 0;
}
