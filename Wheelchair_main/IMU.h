#ifndef _IMU_H
#define _IMU_H

#include "mbed.h"
#include "lsm9ds0.h"

#define LSM9DS0_XM 0x1E
#define LSM9DS0_G  0x6A

#define toDegree 57.2957795
#define SAMPLE 20

class IMU {

public:
	IMU(PinName sda , PinName scl);


	//方位の初期値を設定
	void setInicialHeading(void);
	//方位の目標値を設定 Heading 0.0~359.0[deg]
	void setDesiredHeading(float desiredHeading);
	//目標値を基準とした相対角度を返す関数
	float getAngle(void);

	/*
	 * heading0 : 起動時の方位
	 * heading  : 方向の目標値の方位
	 * angle    : 目標値を基準とした角度
	 */
	float heading0, heading, angle;
	
	float g_x, g_y, g_z;
	float a_x, a_y, a_z;
	float m_x, m_y, m_z;

private:

	LSM9DS0 dof;

	void initIMU(void);
	float calcHeading(void);	 	//方向角の計算[deg]
	float calcOrientation(void);    //姿勢角の計算[deg]

	void readGyro(void);
	void readAccel(void);
	void readMag(void);



	float pitch, roll;

};

#endif /*_IMU_H*/


