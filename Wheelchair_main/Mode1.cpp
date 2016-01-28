#include "main.h"

void Mode1(void) {

	lcd.locate(0,0); lcd.printf("MODE1    \n");
	isControllHeading  = 1;
	isControllDistance = 0;

	float frontDistance = 0.0;
	/*
	for(int i = 0; i < 3; i++) {
		frontDistance += front_ultrasonic.mesureFront();
	}
	frontDistance /= 3;
	*/
	ultrasonic.readDistance(ultrasonic.LEFT_SLAVE_ADDRESS);
	frontDistance = ultrasonic.getFrontDistance();
	if(isDetectFrontObject(frontDistance)) isMoving = 0;


	if(SW_ON(2)) isMoving = 1;
}

void mesureMode1(void) {

	lcd.locate(0,0); lcd.printf("MEASURE MODE1    \n");
	isControllHeading  = 1;
	isControllDistance = 0;

	Angle = imu.getAngle();

	if(SW_ON(2)) isMoving = 1;
}
