#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H

#include "mbed.h"

class Ultrasonic {

public:

	Ultrasonic(PinName sda, PinName scl, float Interval);

	enum slave_addr {
		LEFT_SLAVE_ADDRESS  = 0xA0,
		RIGHT_SLAVE_ADDRESS = 0XA1
	};

	void readDistance(slave_addr addr);

	int getFrontDistance(void); //前方の超音波センサの値
	int getBackDistance(void);  //後方の超音波センサの値
	int getDiffDistance(void);  //前後の超音波センサの値の差分

	float getAvgDistance(void);			 //前後の超音波センサの値の平均値

	float getDifferentialDistance(void); //平均値の微分値

private:

	I2C i2c;
	char distance[2];

	int frontDistance;
	int backDistance;

	float avgDistance;
	float prevAvgDistance;

	float tSample;


};

#endif /*_ULTRASONIC_H*/





















