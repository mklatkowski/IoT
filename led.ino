#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

#define RED_BUTTON 2


void initRGB()
{

    pinMode(LED_RED, OUTPUT);
    digitalWrite(LED_RED, HIGH);

    pinMode(LED_GREEN, OUTPUT);
    digitalWrite(LED_GREEN, HIGH);

    pinMode(LED_BLUE, OUTPUT);
    digitalWrite(LED_BLUE, HIGH);
}

void setup()
{
    initRGB();
}

bool isWorking = true;

void blinkRedBuiltinLed()
{
    const unsigned long BlinkChangePeriod = 500UL;
    static int ledState = LOW;
    static unsigned long lastBlinkChange = 0UL;

    if (millis() - lastBlinkChange >= BlinkChangePeriod)
    {
        if (ledState == HIGH)
        {
            ledState = LOW;
        }
        else
        {
            ledState = HIGH;
        }

        if(isWorking){
          digitalWrite(LED_RED, ledState);
        }
        else{
          digitalWrite(LED_RED, LOW);
        }
        lastBlinkChange += BlinkChangePeriod;
    }
}

void blinkGreenBuiltinLed()
{
    const unsigned long BlinkChangePeriod = 1000UL;
    static int ledState = LOW;
    static unsigned long lastBlinkChange = 0UL;

    if (millis() - lastBlinkChange >= BlinkChangePeriod)
    {
        if (ledState == HIGH)
        {
            ledState = LOW;
        }
        else
        {
            ledState = HIGH;
        }

        if(isWorking){
          digitalWrite(LED_GREEN, ledState);
        }
        else{
          digitalWrite(LED_GREEN, LOW);
        }
        lastBlinkChange += BlinkChangePeriod;
    }
}

void blinkBlueBuiltinLed()
{
    const unsigned long BlinkChangePeriod = 1500UL;
    static int ledState = LOW;
    static unsigned long lastBlinkChange = 0UL;

    if (millis() - lastBlinkChange >= BlinkChangePeriod)
    {
        if (ledState == HIGH)
        {
            ledState = LOW;
        }
        else
        {
            ledState = HIGH;
        }

        if(isWorking){
          digitalWrite(LED_BLUE, ledState);
        }
        else{
          digitalWrite(LED_BLUE, LOW);
        }
        lastBlinkChange += BlinkChangePeriod;
    }
}

void checkNineSec(){
  const unsigned long StatePeriod = 9000UL;
  const unsigned long BreakPeriod = 2000UL;
  static unsigned long lastStateChange = 0UL;
  if(millis() - lastStateChange >= StatePeriod && isWorking){
    isWorking = false;
    lastStateChange +=StatePeriod;
  }

  if(millis()- lastStateChange >=BreakPeriod && !isWorking){
    isWorking = true;
    lastStateChange += BreakPeriod;
  }

}

void loop()
{
    blinkRedBuiltinLed();
    blinkGreenBuiltinLed();
    blinkBlueBuiltinLed();
    checkNineSec();

}
