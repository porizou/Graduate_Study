#include "mbed.h"
#include "main.h"

CAN can(p9, p10);

void CAN_Slave(void const *argment) {
	CANMessage msg ;
	while(1) {
		if(can.read(msg)) {
			motor_slots.wait();

			motorL = ((float)(msg.data[0] & 0x7f)) * (msg.data[0] >= 128 ? 1.0 : -1.0);
			motorL = motorL / 127.0;
			motorR = ((float)(msg.data[1] & 0x7f)) * (msg.data[1] >= 128 ? 1.0 : -1.0);
			motorR = motorR / 127.0;

			motor_slots.release();
			//pc.printf("motorL:%x , motorR:%x\r\n", msg.data[0],msg.data[1]);
			led2 = !led2;
		}
		led3 = !led3;
	}
}

SPISlave spi(p11, p12, p13, p14); // mosi, miso, sclk, ssel

void SPI_Slave(void const *argment) {

	char motor[2] = {};
	int  data;

	spi.format(16, 3);
	spi.frequency(1000000);
	spi.reply(fabs(MovingDistance));

	while(1) {
		while(!spi.receive());
		if(spi.receive()) {
			data = spi.read();
			motor[0] = data & 0x00ff;
			motor[1] = data >> 8;
			spi.reply(fabs(MovingDistance));
			led2 = !led2;
		}

		motorL = (((float)(motor[0] & 0x7f)) * (motor[0] >= 128 ? 1.0 : -1.0)) / 127.0;

		motorR = (((float)(motor[1] & 0x7f)) * (motor[1] >= 128 ? 1.0 : -1.0)) / 127.0;

		//pc.printf("motorL:%x , motorR:%x\r\n", motor[0],motor[1]);
		led3 = !led3;
	}
}
