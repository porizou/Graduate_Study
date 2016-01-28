/*
 * cp /Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/Debug/Wheelchair_motorcontroll.bin /Volumes/MBED/ && diskutil unmount /Volumes/MBED/
 * screen /dev/tty.usbmodem1412 9600
 */

/**
 * Includes
 */
#include "main.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
Serial pc(USBTX, USBRX);

// PIDチューニング用パラメータ
AnalogIn Kp(p16);
AnalogIn Ki(p19);
AnalogIn Kd(p20);

Motor  motor_right(p22 , p30 , p29 , PWM_FREQUENCY);
Motor  motor_left (p21 , p23 , p24 , PWM_FREQUENCY);

// SDカード,シリアル通信スレッドの許可フラグ
bool using_SD = 0 , using_serial = 0 ;

float motorL = 0.0;
float motorR = 0.0;

Semaphore motor_slots(2);

int main() {

	Thread VelocityControll(VelocityThread, NULL, osPriorityNormal);
	//Thread can_thread(CAN_Slave, NULL, osPriorityNormal);
	Thread spi_thread(SPI_Slave, NULL, osPriorityNormal);
    while(1) {
    	//motor_slots.wait();
    	motor_right.rotate(motorR);
    	motor_left.rotate(motorL);
    	//motor_slots.release();
    	led1 = !led1;
    }
}
