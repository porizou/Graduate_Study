#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(PinName sda, PinName scl, float Interval)
					 : i2c(sda, scl) {

	tSample = Interval;

	frontDistance = 0;
	backDistance = 0;
	avgDistance = 0.0;
	prevAvgDistance  = 0.0;

}

void Ultrasonic::readDistance(slave_addr addr) {
	bool i;
	do{ i = i2c.read(addr, distance, 2);}while(i);

	frontDistance = distance[0];
	backDistance  = distance[1];
}

int Ultrasonic::getFrontDistance(void) {
	return frontDistance;
}

int Ultrasonic::getBackDistance(void) {
	return backDistance;
}

int Ultrasonic::getDiffDistance(void) {
	return fabs(frontDistance - backDistance);
}

float Ultrasonic::getAvgDistance(void) {

	prevAvgDistance = avgDistance;
	avgDistance = (frontDistance + backDistance) / 2.0;
	return avgDistance;
}

float Ultrasonic::getDifferentialDistance(void) {
	return (avgDistance - prevAvgDistance) / tSample;
}



