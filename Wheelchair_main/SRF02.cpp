#include "SRF02.h"

/* Creates an instance of class. Setting the pin used for I2C, the address of device and the measure range type. */
SRF02::SRF02(PinName sda, PinName scl, char addr, char type) : _i2c(sda, scl), _addr(addr)
{
    _typem = type;
}

/* Destroyer of class instance. */
SRF02::~SRF02() 
{

}

/* Start and return the range measure. */
float SRF02::read() 
{
    char command[2];
    char result[2];

    command[0] = 0x00;                          // Set the command register
    command[1] = _typem;                        // Ranging results in type indicated in a costructor
    _i2c.write(_addr, command, 2);              // Send the command to start a ranging burst

    wait(0.03);                                // Wait 70mS for complete the measure

    command[0] = 0x02;                          // The start address of measure result
    _i2c.write(_addr, command, 1, 1);           // Send address to read a measure
    _i2c.read(_addr, result, 2);                // Read two byte of measure

    float range = (result[0]<<8)+result[1];     // Convert the two byte in a float value

    return range;
}

void SRF02::change_addr(char new_addr){

    char command[2];

    command[0] = 0x00;
    command[1] = 0xA0;
    _i2c.write(_addr,command,2);

    command[0] = 0x00;
    command[1] = 0xAA;
    _i2c.write(_addr,command,2);

    command[0] = 0x00;
    command[1] = 0xA5;
    _i2c.write(_addr,command,2);

    command[0] = 0x00;
    command[1] = new_addr;
    _i2c.write(_addr,command,2);

    _addr = new_addr;
}
















