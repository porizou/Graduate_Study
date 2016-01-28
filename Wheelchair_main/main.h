#ifndef _MEIN_H
#define _MEIN_H

/*
 * Includes
 */

#include "mbed.h"
#include "rtos.h"
#include "ACM1602NI.h"
#include "Ultrasonic.h"
#include "Ultrasonic_Front.h"
#include "IMU.h"
#include "ControllHeading.h"
#include "ControllDistance.h"
#include "SDFileSystem.h"

/*
 * Defines
 */

#define PID_TUNING_DISTANCE
//#define PID_TUNING_HEADING

//PIDチューニング可能範囲設定
#define Kp_MIN 0.0
#define Kp_MAX 0.5
#define Ki_MIN 0.0
#define Ki_MAX 0.1
#define Kd_MIN 0.0
#define Kd_MAX 0.1

#define HEADING_FACTOR 1.0 //動いている時の方向制御の補正係数 0.0~1.0

#define FRONT_AREA 15
#define OVER_ANGLE 30

//モータの個体値調整
#define IndividualMotorR 1.0
#define IndividualMotorL 1.0

#define HeadingControllCycle 0.02 //方向制御 制御周期
#define DistanceControllCycle 0.1 //距離制御 制御周期

/* --- クラス --- */

	extern DigitalOut led1;
	extern DigitalOut led2;
	extern DigitalOut led3;
	extern DigitalOut led4;

	extern DigitalIn SW[2];

	extern BusIn Rotary; //ロータリースイッチ入力

	extern ACM1602NI lcd;
	extern Serial pc;

	//距離制御のためのクラス
	extern      Ultrasonic       ultrasonic;
	extern FrontUltrasonic front_ultrasonic;

	extern ControllDistance controll_distance;

	//方向制御のためのクラス
	extern IMU imu;

	extern ControllHeading controll_heading;

	extern Mutex spi_mutex;


/* --- グローバル変数 --- */

	//モータ制御量
	extern float motorR, motorL; //モータ操作量 -1.0~1.0
	extern float  Speed; //基準となるスピード -1.0~1.0

	//本体の基準の向きからの傾き
	extern float Angle;

	//側面の壁との距離
	extern float sideDistance;

	//PIDゲイン
	extern float Kp, Ki, Kd; 
	
	// モータ動作フラグ
	extern bool isMoving;
	
	//各PID制御の許可フラグ
	extern bool isControllDistance;
	extern bool isControllHeading;
	
	extern uint16_t MovingDistance; //移動距離[cm]


	void CAN_Thread(void const *argment); //CAN通信のスレッド
	void SPI_Thread(void const *argment); //SPI通信のスレッド
	void SD_Thread(void const *sdcard);   //SDカードのスレッド
	void DistanceThread(void const *ControllDistance); //距離制御のスレッド
	void  HeadingThread(void const *ControllHeading);  //方向制御のスレッド

	// 各モード関数の宣言
	void Mode (void);
	void Mode1(void);		   //方向制御のモード
	void Mode2(void);          //距離制御のモード
	void Mode3(void);          //方向制御＋距離制御のモード
	void PID_Tuning_Mode(void);      //PIDチューニングモード
	void   Heading_Mode(void);      //IMUデバックモード
	void  Left_Distance_Mode(void); //超音波デバックモード(左)
	void Right_Distance_Mode(void); //超音波デバックモード(右)
	void Front_Distance_Mode(void); //超音波デバックモード(前)
	void Compass_Calibrate_Mode(void);

	void mesureMode1(void);
	void mesureMode2(void);

	
	bool SW_ON(int n); //スイッチが押されているか確認
	
	bool isDetectFrontObject(float distance); //前方の障害物を検知
	bool isDetectOverAngle(float angle); //本体が傾き過ぎていないか確認

	void controll_reset(void); //PID制御のリセット及びモータの停止

	void setPIDGain(void);  //可変抵抗の値をAD変換してPIDゲインを設定する関数


#endif /*_MAIN_H*/



