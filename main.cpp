/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Adafruit_SSD1306.h"

#define WAIT_TIME_MS 500 

// an I2C sub-class that provides a constructed default
class I2CPreInit : public I2C
{
public:
    I2CPreInit(PinName sda, PinName scl) : I2C(sda, scl)
    {
        frequency(400000);
        start();
    };
};

#define D_SDA                  PA_12
#define D_SCL                  PA_11

I2CPreInit gI2C(D_SDA,D_SCL);

// an SPI sub-class that provides a constructed default

Adafruit_SSD1306_I2c gOled(gI2C,NC,0x78,32,128);

int main()
{
    uint16_t x=0;

    while (true)
    {
        gOled.clearDisplay();
        gOled.printf("%u\r",x);
        
        gOled.display();
        x++;
        thread_sleep_for(WAIT_TIME_MS);
    }
}
