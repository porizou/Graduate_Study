/* An I2C text LCD library for Displaytronic ACM1602NI-FLW-FBW-M01
 * Copyright 2013, 2014, Takuo WATANABE (wtakuo)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ACM1602NI_H
#define ACM1602NI_H

#include "mbed.h"

/** An I2C text LCD library for Displaytronic ACM1602NI-FLW-FBW-M01.
 * The device does not work with default I2C library due to its slow I2C responce.
 * This library adds some extra waits so that the device can answer to the I2C commands.
 * The interface is basically the same as TextLCD by Simon Ford.
 * 
 * This LCD device is manufactured by Xiamen Zettler Electronics Co. Ltd. and distributed by
 * Akizuki Denshi Tsusho Co. Ltd.
 * http://akizukidenshi.com/catalog/g/gP-05693/
 * http://akizukidenshi.com/download/ds/xiamen/ACM1602NI-FLW-FBW-M01_DISPLAYTRONIC_%20SPEC%20VER1.2.pdf
 *
 * Example:
 * @code
 * #include "mbed.h"
 * #include "ACM1602NI.h"
 *
 * // I2C pins: p9 = sda, p10 = scl
 * ACM1602NI lcd(p9, p10);
 *
 * // You can specify an I2C object instead.
 * // I2C i2c(p9, p10);
 * // ACM1602NI lcd(i2c);
 *
 * int main() {
 *     lcd.printf("Hello, World!\n");
 *     lcd.printf("ACM1602NI\n");
 * }
 * @endcode
 */
class ACM1602NI : public Stream {
public:
    /** Create an ACM1602NI object connected to the specified I2C pins.
     *
     * @param sda  I2C data pin
     * @param scl  I2C clock pin
     */
    ACM1602NI(PinName sda, PinName scl);

    /** Create an ACM1602NI object connected to the specified I2C port.
     *
     * @param i2c  I2C port
     */
    ACM1602NI(I2C &i2c);

    /** Initialize the device and clear screen
     */
    void init();

    /** Locate to a screen column and row
     *
     * @param column  The horizontal position from the left, indexed from 0
     * @param row     The vertical position from the top, indexed from 0
     */
    void locate(int column, int row);

    /** Clear the screen and locate to 0,0 */
    void cls();

    int rows();
    int columns();

#if DOXYGEN_ONLY
    /** Write a character to the LCD
     *
     * @param c The character to write to the display
     */
    int putc(int c);

    /** Write a formated string to the LCD
     *
     * @param format A printf-style format string, followed by the
     *               variables to use in formating the string.
     */
    int printf(const char* format, ...);
#endif

protected:
    static const int i2c_addr = 0x50 << 1;
    static const int i2c_bit_wait_us = 20;
    static const int i2c_command_wait_ms = 4;

    static const int display_columns = 16;
    static const int display_rows = 2;

    I2C _i2c;
    int _column, _row;

    virtual int _putc(int value);
    virtual int _getc();

    int address(int column, int raw);
    void character(int column, int row, int c);

    int writeBytes(const char *data, int length, bool repeated = false);
    void writeCommand(char command);
    void writeData(char data);
};

#endif
