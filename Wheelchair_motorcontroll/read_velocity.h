/* --- エンコーダから回転角を取得して速度を計算するクラス --- */

#ifndef __read_velocity_h
#define __read_velocity_h

/**
 * Includes.
 */
#include "mbed.h"
#include "QEI.h"

/**
 * Defines.
 */
#define PI 3.14159265358979

#define LPF 0.95 //0~1 速度計算,LPF係数
//#define vSample 0.002 //回転角取得周期

class ReadVelocity {

public:

	/**
	 *
	 * A エンコーダA相ピン変化割り込みピン
	 * B エンコーダB相ピン変化割り込みピン
	 * pulseNum 一回転辺りのパルス数
	 * Sample 回転角取得周期
	*/		
	ReadVelocity(PinName A , PinName B , int pulseNum , float Sample);

	/* 初期値の設定 */
	void initParam(void);

	/* 回転角を取得するタイマー割り込み関数　*/
	void readEncoder(void);

	/* 回転速度を計算する関数 */
	float culcVelocity(void);

	int getPulse(void);

	float getAngle(void);

	float getRevolution(void);

private:

	QEI qei;

	Ticker sampleTicker; // 速度計算タイマー割り込み

	int pulseNum_;
	float Sample_;

	float  Angle;   // 回転角度 [rad]
	float  pAngle;  // 前回の回転角度 [rad]

	float  Velocity;  // 回転速度 [rad/s]
	float  pVelocity; // 前回の回転速度 [rad/s]


};

#endif 







						

							




















