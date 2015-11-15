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

#include "mbed.h"
#include "ACM1602NI.h"

#define I2C_SUCCESS 0
#define I2C_FAILURE 1

ACM1602NI::ACM1602NI(PinName sda, PinName scl) : _i2c(sda, scl) {
    init();
}

ACM1602NI::ACM1602NI(I2C &i2c) : _i2c(i2c) {
    init();
}

void ACM1602NI::init() {
    writeCommand(0x01);
    wait_ms(i2c_command_wait_ms);
    writeCommand(0x38);
    wait_ms(i2c_command_wait_ms);
    writeCommand(0x0f);
    wait_ms(i2c_command_wait_ms);
    writeCommand(0x06);
    wait_ms(i2c_command_wait_ms);
    locate(0, 0);
}

int ACM1602NI::writeBytes(const char *data, int length, bool repeated) {
    wait_us(i2c_bit_wait_us);
    _i2c.start();
    for (int i = 0; i < length; i++) {
        wait_us(i2c_bit_wait_us);
        if (_i2c.write(data[i]) != 1) {
            wait_us(i2c_bit_wait_us);
            _i2c.stop();
            return I2C_FAILURE;
        }
    }
    if (!repeated) {
        wait_us(i2c_bit_wait_us);
        _i2c.stop();
    }
    return I2C_SUCCESS;
}

void ACM1602NI::character(int column, int row, int c) {
    writeCommand(address(column, row));
    writeData(c);
}

void ACM1602NI::cls() {
    writeCommand(0x01);
    wait_ms(i2c_command_wait_ms);
    locate(0, 0);
}

void ACM1602NI::locate(int column, int row) {
    _column = column;
    _row = row;
}

int ACM1602NI::_putc(int value) {
    if (value == '\n') {
        _column = 0;
        _row = (_row + 1) % rows();
    }
    else {
        character(_column, _row, value);
        _column++;
        if (_column >= columns()) {
            _column = 0;
            _row = (_row + 1) % rows();
        }
    }
    return value;
}

int ACM1602NI::_getc() {
    return -1;
}

void ACM1602NI::writeCommand(char command) {
    char bs[3] = { i2c_addr, 0x00, command };
    writeBytes(bs, 3);
}

void ACM1602NI::writeData(char data) {
    char bs[3] = { i2c_addr, 0x80, data };
    writeBytes(bs, 3);
}

int ACM1602NI::address(int column, int row) {
    return 0x80 + row * 0x40 + column;
}

int ACM1602NI::columns() {
    return display_columns;
}

int ACM1602NI::rows() {
    return display_rows;
}
