#include "main.h"

AnalogIn VR1(p15);
AnalogIn VR2(p16);
AnalogIn VR3(p17);

float Kp = 0.0, Ki = 0.0, Kd = 0.0;

void PID_Tuning_Mode(void) {

	setPIDGain();
	
	lcd.locate(0,0); lcd.printf("Kp:%0.2f\n", Kp);
	lcd.locate(0,1); lcd.printf("Ki:%0.2f\n", Ki * 10);
	lcd.locate(8,1); lcd.printf("Kd:%0.2f\n", Kd * 10);
	
}

void setPIDGain(void) {

	Kp = Kp_MIN + (VR1 * (Kp_MAX - Kp_MIN));
	Ki = Ki_MIN + (VR2 * (Ki_MAX - Ki_MIN));
	Kd = Kd_MIN + (VR3 * (Kd_MAX - Kd_MIN));
}


