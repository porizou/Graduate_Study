
#ifndef SRF02_H
#define SRF02_H

#include "mbed.h"

#define INCHES_RESULT       0x50    // For result in inches
#define CENTIMETERS_RESULT  0x51    // For result in centimeters
#define MICROSECONDS_RESULT 0x52    // For result in micro-seconds


class SRF02
{
    public:
        enum measure_type{INCHES=0x050,CENTIMETERS=0x51,MICROSECONDS=0x52};
        /** Creates an instance of class. Setting the pin used for I2C, the address of device and the measure range type.
         *
         * @param sda A pin used for SDA I2C signal.
         * @param scl A pin used for SCL I2C signal.
         * @param addr The address of I2C SRF02 device.
         * @param measure_type The of mesure response (0-inches,1-centimeters,2-micro-seconds).
         */
        SRF02(PinName sda, PinName scl, char addr, char type);
      
        /* Destroyer of class instance. */
        ~SRF02();
      
        /** Start and return the range measure.
         *
         * @returns The value of measure.
         */
        float read();

        void change_addr(char new_addr);
      
    private:
        I2C _i2c;      // I2C object to comunicate with SRF02
        char _addr;     // Address of sensor
        char _typem;   // Type of mesure
};

#endif
