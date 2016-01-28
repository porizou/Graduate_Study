#include "mbed.h"
#include "main.h"

CAN can(p30 , p29);

void CAN_Thread(void const *argment) {

	char motor[2];
	bool i;

	while(!SW_ON(1));
	
	while(1) {

		if(SW_ON(1)) {
			motor[0] = 0; motor[1] = 0;
			if(can.write(CANMessage(1337, motor, 2))) led1 = 0;
			while(!SW_ON(1));
		}
    	motor[0] = (char)(roundf(fabs(motorL) * 127.0)) + (motorL > 0 ? 128 : 0);
		motor[1] = (char)(roundf(fabs(motorR) * 127.0)) + (motorR > 0 ? 128 : 0);
		do { i = can.write(CANMessage(1337, motor, 2)); } while(!i);
		led1 = !led1;
		wait(0.1);
		
	}

}

SPI spi(p11, p12, p13); // mosi, miso, sclk
DigitalOut cs(p14,1);

inline int SPI_write(int data) {
	cs = 0;
	int reply = spi.write(data);
	cs = 1;
	return reply;
}

void SPI_Thread(void const *argment) {

	uint8_t motor[2] = {};
	int data;  //送信データ
	int reply; //スレーブからの受信データ
	spi.format(16, 3);
	spi.frequency(1000000);

	while(!SW_ON(1)); //SW1が押されたら通信を開始する

	while(1) {
		//SW1が押されたらモータの操作量を0にして通信を停止
		if(SW_ON(1)) {
			data = 0;
			reply = SPI_write(data);
			led1 = 0;
			while(!SW_ON(1));
		}
		//モータの操作量-1~1をchar型のデータに変換して送信する (正転-->7bit目が1,逆転-->7bit目が0)
		motor[0] = (char)(roundf(fabs(motorL) * 127.0)) + (motorL > 0 ? 128 : 0);
		motor[1] = (char)(roundf(fabs(motorR) * 127.0)) + (motorR > 0 ? 128 : 0);
		
		data = (motor[1] << 8) + motor[0];
		reply = SPI_write(data);

		MovingDistance = reply;
		Thread::wait(5);
		led1 = !led1;
	}
}

























