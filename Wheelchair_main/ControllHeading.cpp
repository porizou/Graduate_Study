
#include "ControllHeading.h"

ControllHeading::ControllHeading(float Kp, float Ki, float Kd, float tSample)
								:PID(Kp, Ki, Kd, tSample){

	initPIDcontroller();
}

void ControllHeading::initPIDcontroller(void) {

	setInputLimits(-179.0, 179.0);
	setOutputLimits(-1.0, 1.0);

	setBias(0.0);
	setIncompleteDifferential(0.0);

	setSetPoint(0.0);
}

float ControllHeading::PIDcompute(float processValue) {

	setProcessValue(processValue);

	return compute();
}



