/* 方向制御のためのクラス---基底クラスPIDの派生クラス*/

#ifndef _CONTROLLHEADING_H
#define _CONTROLLHEADING_H

#include "mbed.h"
#include "PIDcontroller.h"

class ControllHeading : public PID {

public: 

	ControllHeading(float Kp, float Ki, float Kd, float tSample);

	void initPIDcontroller(void);

	float PIDcompute(float processValue);

private:
};

#endif /*_CONTROLLHEADING_H*/







