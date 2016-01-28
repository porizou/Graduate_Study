#include "main.h"

void Mode(void) {

	lcd.locate(0,0); lcd.printf("%d\r\n", MovingDistance);
	Angle = imu.getAngle();


}

void Heading_Mode(void) {

	lcd.locate(0,0); lcd.printf("HEADING:%0.2f\n",imu.getAngle());
	lcd.locate(0,1); lcd.printf("heading:%0.2f\n",imu.heading);
	wait(0.5);

}

void Left_Distance_Mode(void) {

	ultrasonic.readDistance(ultrasonic.LEFT_SLAVE_ADDRESS);

	lcd.locate(0,0); lcd.printf("FL:%3dcm\n", ultrasonic.getFrontDistance());
	lcd.locate(0,1); lcd.printf("BL:%3dcm\n", ultrasonic.getBackDistance());

	wait(0.1);
}

void Right_Distance_Mode(void) {

	ultrasonic.readDistance(ultrasonic.RIGHT_SLAVE_ADDRESS);

	lcd.locate(0,0); lcd.printf("FR:%3dcm\n", ultrasonic.getFrontDistance());
	lcd.locate(0,1); lcd.printf("BR:%3dcm\n", ultrasonic.getBackDistance());

	wait(0.1);
}

void Front_Distance_Mode(void) {

	lcd.locate(0,0); lcd.printf("FRONT:%0.2fcm\n", front_ultrasonic.mesureFront());

	wait(0.1);
}
