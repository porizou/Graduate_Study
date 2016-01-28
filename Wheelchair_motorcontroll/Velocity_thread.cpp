/*  --- 速度制御を行うスレッド --- */
/**
 * Includes
 */

#include "main.h"
#include "V_Control.h"
#include "read_velocity.h"

/**
 * Defines.
 */


// 速度サンプリング周期[s]
#define V_SAMPLE_RIGHT 0.002
#define V_SAMPLE_LEFT  0.002

// 速度制御周期[s]
#define V_RATE_RIGHT 0.002
#define V_RATE_LEFT  0.002

// エンコーダの設定
#define N_ENC (70 * 4)

//ホイールの直径D [cm]
#define DIAMETER 15.0

#define R_CH_A p21
#define R_CH_B p20
#define L_CH_A p23
#define L_CH_B p24

// PIDゲインの設定
#define R_vKp 1.0
#define R_vKi 0.0
#define R_vKd 0.0

#define L_vKp 1.0
#define L_vKi 0.0
#define L_vKd 0.0

ReadVelocity rightVelocity(p26 , p25 , N_ENC , V_SAMPLE_RIGHT);
ReadVelocity  leftVelocity(p28 , p27 , N_ENC , V_SAMPLE_LEFT);

int MovingDistance = 0.0;

void VelocityThread(void const *velocitycontroll) {

	while(1) {

		MovingDistance = (PI * DIAMETER) / N_ENC * rightVelocity.getPulse();
		//pc.printf("revolutions : %0.2f, movingdistance : %0.2f[cm]\r\n", Revolutions, MovingDistance);

		Thread::wait(1);
	}
}















