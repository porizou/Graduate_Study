/*  --- 速度制御を行うスレッド --- */

/**
 * Includes
 */
#include "mbed.h"
#include "rtos.h"

#include "V_Control.h"
#include "read_velocity.h"
#include "motordriver.h"

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
















