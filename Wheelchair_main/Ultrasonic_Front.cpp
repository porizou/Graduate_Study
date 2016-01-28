#include "Ultrasonic_Front.h"

FrontUltrasonic::FrontUltrasonic(PinName sda, PinName scl,
								 SlaveAddress Front, SlaveAddress FrontLeft, SlaveAddress FrontRight) 
								: srf02_Front     (sda, scl, Front,      CENTIMETERS),
								  srf02_FrontLeft (sda, scl, FrontLeft,  CENTIMETERS),
								  srf02_FrontRight(sda, scl, FrontRight, CENTIMETERS) {


}

float FrontUltrasonic::mesureFront(void) {

	return srf02_Front.read();
}

float FrontUltrasonic::mesureFrontLeft(void) {

	return srf02_FrontLeft.read();
}

float FrontUltrasonic::mesureFrontRight(void) {

	return srf02_FrontRight.read();
}
