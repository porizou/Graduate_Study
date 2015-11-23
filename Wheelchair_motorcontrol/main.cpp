/**
 * Includes
 */
#include "mbed.h"
#include "rtos.h" //リアルタイムOS

//#define PIDTUNING
//#define USE_CURRENT_CONTROL

/**
 * PID parameter limit
 */
#define Kp_MIN 0.0
#define Kp_MAX 1.0
#define Ki_MIN 0.0
#define Ki_MAX 1.0
#define Kd_MIN 0.0
#define Kd_MAX 1.0

DigitalOut led1(LED1);

// PIDチューニング用パラメータ
AnalogIn Kp(p11);
AnalogIn Ki(p12);
AnalogIn Kd(p13);

// SDカード,シリアル通信スレッドの許可フラグ
bool using_SD = 0 , using_serial = 0 ;



int main() {
    while(1) {

    }
}
