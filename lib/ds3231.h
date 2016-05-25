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

#ifndef DS3232RTC_h
#define DS3232RTC_h

#include "Wire.h"


#define DS3231_I2C 0x68

struct ts {
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t dayOfWeek; // 1 = Sunday, 7 = Saturday
    uint8_t day;
    uint8_t month;
    uint8_t year;
};

/**
 * Converts decimal to binary-coded decimal
 */
uint8_t bcd(uint8_t val);

/**
 * Converts binary-coded decimal to decimal
 */
uint8_t dec(uint8_t val);

/**
 * Read the time
 */
void get(ts *t);

/**
 * Set the time
 */
void set(ts t);


#endif
