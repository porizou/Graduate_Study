#ifndef _MAIN_H_
#define _MAIN_H_


#include "mbed.h"
#include "rtos.h" //リアルタイムOS
#include "motordriver.h"
#include "read_velocity.h"

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

#define PWM_FREQUENCY 10000

extern DigitalOut led1;
extern DigitalOut led2;
extern DigitalOut led3;
extern Serial pc;

extern Motor motor_right;
extern Motor motor_left;

extern CAN can;
extern SPISlave spi;

// PIDチューニング用パラメータ
extern AnalogIn Kp;
extern AnalogIn Ki;
extern AnalogIn Kd;

extern bool using_SD, using_serial;

extern float motorL;
extern float motorR;

extern int MovingDistance;

void CAN_Slave(void const *argment);
void SPI_Slave(void const *argment);

void VelocityThread(void const *velocitycontroll);

extern Semaphore motor_slots;


#endif
