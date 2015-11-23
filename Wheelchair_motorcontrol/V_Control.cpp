#include "V_Control.h"

V_CONTROL::V_CONTROL(float vKp , float vKi , float vKd , float Interval)
					 : pid(vKp , vKi , vKd , Interval){

	pid_init();
}

void V_CONTROL::pid_init(void) {

	pid.setInputLimits(V_INPUT_MIN, V_INPUT_MAX);
	pid.setOutputLimits(V_OUTPUT_MIN, V_OUTPUT_MAX);
	pid.setMode(AUTO_MODE);
	pid.setSetPoint(0.0);
	pid.setProcessValue(0.0);

	/* フィードフォワード制御が有効ならバイアス値を設定 */
	#ifdef FEEDFORWARD
	pid.setBias(Bias);
	#else
	pid.setBias(0.0);
	#endif

}

float V_CONTROL::v_compute(float dv, float cv) {

	/* 目標速度の設定 -1.0~1.0 desired_velocity */
	pid.setSetPoint(fabs(dv));

	/* 現在速度の設定 -V_MAX~V_MAX current_velocity */
	pid.setProcessValue(fabs(cv)/V_MAX); //現在速度を-1~1の範囲に設定

	int direction = (dv > 0.0) ? 1.0 : -1.0;
	if(dv == 0.0) direction = 0;

	return pid.compute()*direction;

}
