#ifndef DIODECONTROLLER_H_
#define DIODECONTROLLER_H_

#include "Arduino.h"


enum led_color
{
    BLACK = 0,
    RED = 6,
    GREEN = 5,
    YELLOW = 11,
    BLUE = 3,
    MAGENTA = 9,
    CYAN = 8,
    WHITE = 14
};


class Blink
{
public:
    void init(byte red, byte green, byte blue);
    void blink(led_color color);
    void reset();

private:
    byte led_red;
    byte led_green;
    byte led_blue;
};

#endif