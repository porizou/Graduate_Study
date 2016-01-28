/* 距離制御のためのクラス---基底クラスPIDの派生クラス*/

#ifndef _CONTROLLDISTANCE_H
#define _CONTROLLDISTANCE_H

#include "mbed.h"
#include "PIDcontroller.h"

class ControllDistance : public PID {

public: 

	ControllDistance(float Kp, float Ki, float Kd, float tSample);

	void initPIDcontroller(void);

	float PIDcompute(float processValue);

private:
};

#endif /*_CONTROLLDISTANCE_H*/


