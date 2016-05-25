/*
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
 * Copyright (c) 2016 Edward Yang
 * All rights reserved.
 *
 */

#include "DS3231.h"


uint8_t bcd(uint8_t val) {
    return( (val/10*16) + (val%10) );
}

uint8_t dec(uint8_t val){
    return( (val/16*10) + (val%16) );
}

void get(ts *t) {
    Wire.beginTransmission(DS3231_I2C);
    Wire.write(0);
    Wire.endTransmission();
    Wire.requestFrom(DS3231_I2C, 7);

    t->sec = dec(Wire.read() & 0x7f);
    t->min = dec(Wire.read());
    t->hour = dec(Wire.read());
    t->dayOfWeek = dec(Wire.read());
    t->day = dec(Wire.read());
    t->month = dec(Wire.read());
    t->year = dec(Wire.read());
}

void set(ts t) {
    Wire.beginTransmission(DS3231_I2C);
    Wire.write(0);
    Wire.write(bcd(t.sec));
    Wire.write(bcd(t.min));
    Wire.write(bcd(t.hour));
    Wire.write(bcd(t.dayOfWeek));
    Wire.write(bcd(t.day));
    Wire.write(bcd(t.month));
    Wire.write(bcd(t.year));
    Wire.endTransmission();
}
