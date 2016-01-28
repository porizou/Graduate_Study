#include "mbed.h"
#include "Ping.h"

DigitalOut led(LED1, 0);
Serial pc(dp16, dp15);
I2CSlave slave(dp5 , dp27);

Ping* ping[2] = {
	new Ping(dp17), //front
	new Ping(dp11)  //back
};

char distance[2] = {0};
int status;

int main() {

	slave.address(0xA0);

	while(1) {

		do{status = slave.receive();}while(!(status == I2CSlave::ReadAddressed));

		slave.write(distance, 2); led = 1;

		pc.printf("front:%d,back:%d\r\n",distance[0],distance[1]);

		for (int i = 0; i < 2; i++) {
			ping[i]->Send();
			wait_ms(30);
			distance[i] = (char)ping[i]->Read_cm() / 2;
		}
	}
}

#include "mbed.h"
#include "Ping.h"

DigitalOut led(LED1, 0);
Serial pc(dp16, dp15);
I2CSlave slave(dp5 , dp27);

Ping ping(dp11);
int status;

int main() {

	slave.address(0xA0);

	while(1) {

		do{status = slave.receive();}while(!(status == I2CSlave::ReadAddressed));

		slave.write(distance, 2); led = 1;

		ping.Send();
		wait_ms(30);

		distance[0] = (char)ping.Read_cm() / 2; 
	}
}














