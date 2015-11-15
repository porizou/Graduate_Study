/* mbed SRF02 Ultrasonic Ranger Sensor Library
 * Created by bobboteck at 16/11/2011
 *
 * Based on: Chris Styles [http://mbed.org/users/chris/] Library for SRF08 
 *           "http://mbed.org/users/chris/programs/SRF08/603nk/docs/"
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef SRF02_H
#define SRF02_H

#include "mbed.h"

#define INCHES_RESULT       0x50    // For result in inches
#define CENTIMETERS_RESULT  0x51    // For result in centimeters
#define MICROSECONDS_RESULT 0x52    // For result in micro-seconds
/** Library for the SRF02 Ultrasonic Ranger Sensor, using the I2C bus for the
 * comunication. Remeber that sensor can function in serial mode if MODE pin
 * is connected to the ground, but this libary not support this mode.
 *
 * Example:
 * @code
 *  // Continuously measuring range
 *  #include "mbed.h"
 *  #include "SRF02.h"
 *  // Create instance of class SRF02 for device at address 0xE0 and take mesure in cm
 *  SRF02 srf02(p28, p27, 0xE0, 1);
 *  DigitalOut led1(LED1);
 * 
 *  int main() 
 *  {
 *      led1=1;
 *      while(1)
 *      {
 *          printf("Measured range : %.2f cm\n\r",srf02.read());
 *          wait(0.5);
 *          led1=!led1;
 *      }
 *  }
 * @endcode
 */
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
        SRF02(PinName sda, PinName scl, int addr, char type);
      
        /* Destroyer of class instance. */
        ~SRF02();
      
        /** Start and return the range measure.
         *
         * @returns The value of measure.
         */
        float read();
      
    private:
        I2C _i2c;      // I2C object to comunicate with SRF02
        int _addr;     // Address of sensor
        char _typem;   // Type of mesure
};

#endif
