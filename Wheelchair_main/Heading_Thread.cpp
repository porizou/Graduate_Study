#include "main.h"

#define Kp_h 0.70 //方向制御 比例ゲイン
#define Ki_h 0.00 //方向制御 積分ゲイン
#define Kd_h 0.07//方向制御 微分ゲイン

IMU imu(p28, p27);
ControllHeading controll_heading(Kp_h, Ki_h, Kd_h, HeadingControllCycle);

void HeadingThread(void const *ControllHeading) {

	if(isControllHeading) {
		led4 = !led4;

#ifdef PID_TUNING_HEADING
		setPIDGain();
		controll_heading.setGain(Kp_h, Ki_h, Kd_h);
#endif
		float angle = 0.0;
		Angle = imu.getAngle();
		if(isMoving) {
			angle = (-3 < Angle && Angle < 3) ? 0.0 : Angle;
		}
		else angle = Angle;


		float ROmega_h = controll_heading.PIDcompute(angle);
		float LOmega_h = ROmega_h * -1.0;

		motorR = (isMoving ? Speed + (ROmega_h * HEADING_FACTOR) : ROmega_h) * IndividualMotorR;;
		motorL = (isMoving ? Speed + (LOmega_h * HEADING_FACTOR) : LOmega_h) * IndividualMotorL;
	}
}

//0.00248s
