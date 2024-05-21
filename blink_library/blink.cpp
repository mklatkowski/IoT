#include "Blink.h"


void Blink::init(byte red, byte green, byte blue)
{
    led_red = red;
    led_green = green;
    led_blue = blue;
    pinMode(led_red, OUTPUT);
    pinMode(led_green, OUTPUT);
    pinMode(led_green, OUTPUT);
    reset();
}

void Blink::blink(led_color color)
{
    reset();
    switch(color){

        case led_color.RED:
            analogWrite(led_red, 255);
            break;

        case led_color.BLACK:
            break;

        case led_color.GREEN:
            analogWrite(led_green, 255);
            break;

        case led_color.YELLOW:
            analogWrite(led_red, 255);
            analogWrite(led_green, 255);
            break;

        case led_color.BLUE:
            analogWrite(led_blue, 255);
            break;

        case led_color.MAGENTA:
            analogWrite(led_red, 255);
            analogWrite(led_blue, 255);
            break;

        case led_color.CYAN:
            analogWrite(led_green, 255);
            analogWrite(led_blue, 255);
            break;

        case led_color.WHITE:
            analogWrite(led_red, 255);
            analogWrite(led_green, 255);
            analogWrite(led_blue, 255);
            break;
        default:
            break;
    }
}

void Blink::reset()
{
    analogWrite(led_color.RED, 0);
    analogWrite(led_color.GREEN, 0);
    analogWrite(led_color.BLUE, 0);
}
