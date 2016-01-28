/* --- 速度PID制御のクラス --- */
#ifndef __V_Control_h
#define __V_Control_h

/**
 * Includes
 */
#include "mbed.h"
#include "PID.h"

/**
 * Defines.
 */

#define V_INPUT_MIN 0.0
#define V_INPUT_MAX 1.0
#define V_OUTPUT_MIN 0.0
#define V_OUTPUT_MAX 1.0

#define Bias 1.0 // フィードフォワード制御バイアス値 0~1

#define V_MAX 10000.0 //速度の最大値[rad/s]

//#define FEEDFORWARD //フィードフォワード制御有効

class V_CONTROL{

public: 
	/*
	 * vKp PID比例ゲイン
	 * vKi PID積分ゲイン
	 * vKd PID微分ゲイン
	 * Interval 速度制御周期[s]
	 */
	V_CONTROL(float vKp , float vKi , float vKd , float Interval);

	/* 現在速度,目標速度よりPIDの出力を計算 */
	float v_compute(float dv , float cv);

private:

	/* PID初期設定 */
	void pid_init(void);

	PID pid;

	int direction; //モーター回転方向 0->停止 1->正転 -1->逆転


};

#endif /* __V_Control_h */









