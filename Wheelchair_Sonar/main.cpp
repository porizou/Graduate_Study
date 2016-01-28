#include "mbed.h"
#include "Ping.h"

DigitalOut led(LED1, 0);
Serial pc(dp16, dp15);
I2CSlave slave(dp5 , dp27);

Ping pings[2] = {Ping(dp17), Ping(dp6)};

int main() {

    slave.address(0xA0);
    char distance[2] = {};
    int i = 0;
    int status;

    while(1) {

        do{status = slave.receive();}while(!(status == I2CSlave::ReadAddressed));

        slave.write(distance, 2); led = !led;

        pings[i%2].Send();
        wait_ms(30);
        distance[i%2] = (char)pings[i%2].Read_cm() / 2;

        i++;
    }
}
