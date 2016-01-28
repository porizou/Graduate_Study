#include "main.h"

#define Kp_d 0.08 //距離制御 比例ゲイン
#define Ki_d 0.001 //距離制御 積分ゲイン
#define Kd_d 0.08 //距離制御 微分ゲイン

      Ultrasonic       ultrasonic(p9, p10, DistanceControllCycle);
 FrontUltrasonic front_ultrasonic(p9, p10, 
 								  FrontUltrasonic::addrFront,
 								  FrontUltrasonic::addrFrontLeft,
 								  FrontUltrasonic::addrFrontRight);

ControllDistance controll_distance(Kp_d, Ki_d, Kd_d, DistanceControllCycle);

void DistanceThread(void const *ControllDistance) {

	float frontDistance = 0.0;

#if 0
	int num = 3;
	for(int i = 0; i < num; i++) {
		frontDistance += front_ultrasonic.mesureFront();
	}
	frontDistance = frontDistance / num;
#endif

	if(isControllDistance) {
		led3 = !led3;

#ifdef PID_TUNING_DISTANCE
		setPIDGain();
		controll_distance.setGain(Kp, Ki, Kd);
#endif
		frontDistance = front_ultrasonic.mesureFront();
		if(isDetectFrontObject(frontDistance)) isMoving = 0;

		ultrasonic.readDistance(ultrasonic.LEFT_SLAVE_ADDRESS);
		sideDistance = ultrasonic.getBackDistance();

		float LOmega_d = controll_distance.PIDcompute(sideDistance);
		float ROmega_d = LOmega_d * -1.0;

		motorR = (isMoving ? Speed + ROmega_d : 0.0) * IndividualMotorR;
		motorL = (isMoving ? Speed + LOmega_d : 0.0) * IndividualMotorL;
	}
}

//0.03117s
