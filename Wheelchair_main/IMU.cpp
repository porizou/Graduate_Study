#include "IMU.h"

IMU::IMU(PinName sda, PinName scl)
		:dof(sda, scl, LSM9DS0_G, LSM9DS0_XM)
{
	initIMU();
	setInicialHeading();

	pitch   = 0.0;
	roll    = 0.0;
}

void IMU::initIMU(void) {
	dof.begin(dof.G_SCALE_2000DPS,dof.A_SCALE_6G,dof.M_SCALE_2GS);
}

void IMU::setInicialHeading(void) {

	float accumHeading = 0.0;
	for (int i = 0; i < SAMPLE; i++) {
		accumHeading += calcHeading();
	}
	heading0 = accumHeading / SAMPLE;

	heading = heading0;
}

void IMU::setDesiredHeading(float desiredHeading) {

	heading = heading0 + desiredHeading;
	if(heading >= 360) heading -= 360;
}

float IMU::getAngle(void) {

	float angle;
	angle = heading - calcHeading();
	//angleを-179~179の範囲に設定
	if(angle >=  180) angle -= 360;
	if(angle <= -180) angle += 360;

	return angle;
}


void IMU::readMag(void) {
	dof.readMag();

	m_x = dof.calcMag(dof.mx);
	m_y = dof.calcMag(dof.my);
	m_z = dof.calcMag(dof.mz);
}

void IMU::readAccel(void) {
	dof.readAccel();

	a_x = dof.calcAccel(dof.ax);
	a_y = dof.calcAccel(dof.ay);
	a_z = dof.calcAccel(dof.az);
}

void IMU::readGyro(void) {
	dof.readGyro();

	g_x = dof.calcGyro(dof.gx);
	g_y = dof.calcGyro(dof.gy);
	g_z = dof.calcGyro(dof.gz);
}


float IMU::calcHeading(void) {

	float Heading = 0.0;
	readMag();

	if(m_y >= 0 && m_x > 0) {
		Heading = ((atan(m_y / m_x)) * toDegree);
	}
	else if(m_y < 0 && m_x >= 0) {
		Heading = 360.0 + ((atan(m_y / m_x)) * toDegree);
	}
	else if(m_x < 0) {
		Heading = 180.0 + ((atan(m_y / m_x)) * toDegree);
	}

	return Heading;
}

float IMU::calcOrientation(void) {
	readAccel();
	return 0;
}
