#include <LiquidCrystal_I2C.h>

#define LED_RED 6
#define LED_BLUE 3
#define POTENTIOMETER A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    pinMode(LED_RED, OUTPUT);
    analogWrite(LED_RED, 0);
    pinMode(LED_BLUE, OUTPUT);
    analogWrite(LED_BLUE, 0);

    lcd.init();
    lcd.backlight();

    lcd.setCursor(2, 1);
    lcd.print(".");

    Serial.begin(9600);
 while (!Serial)
 { /* just wait */
 }
}

int prev = 0;

void loop()
{
    int value1 = analogRead(A0);
      int value = min(max(0, value1 - 10), 1003); //1003 = 1023 - 10 - 10
      int voltage = map(value, 0, 1003, 0, 50);
      int r = map(value, 0, 1003, 0, 10000);
      int val2 = voltage % 10;
      int val1 = voltage / 10;
      lcd.setCursor(0, 0);
      lcd.print("     ");
      lcd.setCursor(0, 0);
      lcd.print(value1);

      lcd.setCursor(1, 1);
      lcd.print(" ");
      lcd.setCursor(1, 1);
      lcd.print(val1);
      lcd.setCursor(3, 1);
      lcd.print(" ");
      lcd.setCursor(3, 1);
      lcd.print(val2);

      lcd.setCursor(5, 1);
      lcd.print("     ");
      lcd.setCursor(5, 1);
      lcd.print(r);

      String str = String(value1) + " " + String(voltage) +" "+ String(r);
      Serial.println(str);

    // if (value - prev > 2 || value - prev < -2)
    // {
    //   value = min(max(0, value - 10), 1003); //1003 = 1023 - 10 - 10
    //   int voltage = map(value, 0, 1003, 0, 50);
    //   int r = map(value, 0, 1003, 0, 10000);
    //   int val2 = voltage % 10;
    //   int val1 = voltage / 10;
    //   lcd.setCursor(0, 0);
    //   lcd.print("     ");
    //   lcd.setCursor(0, 0);
    //   lcd.print(value);

    //   lcd.setCursor(1, 1);
    //   lcd.print(" ");
    //   lcd.setCursor(1, 1);
    //   lcd.print(val1);
    //   lcd.setCursor(3, 1);
    //   lcd.print(" ");
    //   lcd.setCursor(3, 1);
    //   lcd.print(val2);

    //   lcd.setCursor(5, 1);
    //   lcd.print("     ");
    //   lcd.setCursor(5, 1);
    //   lcd.print(r);
    // }
    prev = value;
}
