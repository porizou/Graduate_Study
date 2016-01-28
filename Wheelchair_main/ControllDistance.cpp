#include "ControllDistance.h"

ControllDistance::ControllDistance(float Kp, float Ki, float Kd, float tSample)
								  :PID(Kp, Ki, Kd, tSample) {

	initPIDcontroller();
}

void ControllDistance::initPIDcontroller(void) {

	setInputLimits(0.0, 50.0);
	setOutputLimits(-1.0, 1.0);

	setBias(0.0);
	setIncompleteDifferential(0.20);

	setSetPoint(25.0);
}

float ControllDistance::PIDcompute(float processValue) {

	setProcessValue(processValue);

	return compute();
}
