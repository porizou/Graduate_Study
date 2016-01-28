#ifndef _ULTRASONIC_FRONT_H
#define _ULTRASONIC_FRONT_H

#include "mbed.h"
#include "SRF02.h"

#define INCHES       0x50    // For result in inches
#define CENTIMETERS  0x51    // For result in centimeters
#define MICROSECONDS 0x52    // For result in micro-seconds

class FrontUltrasonic {

public:
	enum SlaveAddress {
		addrFront      = 0xE0,
		addrFrontLeft  = 0xE2,
		addrFrontRight = 0xE4
	};

	FrontUltrasonic(PinName sda, PinName scl,
					SlaveAddress Front, SlaveAddress FrontLeft, SlaveAddress FrontRight);



	void mesure(void);

	float mesureFront(void);
	float mesureFrontLeft(void);
	float mesureFrontRight(void);

private:
	SRF02 srf02_Front;
	SRF02 srf02_FrontLeft;
	SRF02 srf02_FrontRight;


	int distances[3];

};

#endif /*_ULTRASONIC_FRONT_H*/
























