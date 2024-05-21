#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3
#define LED_WHITE 9
#define LED_OFF 0

#define RED_BUTTON 2
#define GREEN_BUTTON 4

int led[] = {LED_RED, LED_GREEN, LED_BLUE, LED_WHITE, LED_OFF};

void initRGB()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, HIGH);

  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, LOW);

  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_BLUE, LOW);

  pinMode(LED_WHITE, OUTPUT);
  digitalWrite(LED_WHITE, LOW);

}

void initButtons()
{
  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

#define DEBOUNCE_PERIOD 10UL

bool isButtonPressed(int buttonPin)
{
  static int debounced_button_state = HIGH;
  static int previous_reading = HIGH;
  static unsigned long last_change_time = 0UL;
  bool isPressed = false;

  int current_reading = digitalRead(buttonPin);

  if (previous_reading != current_reading)
  {
    last_change_time = millis();
  }

  if (millis() - last_change_time > DEBOUNCE_PERIOD)
  {
    if (current_reading != debounced_button_state)
    {
      if (debounced_button_state == HIGH && current_reading == LOW)
      {
        isPressed = true;
      }
      debounced_button_state = current_reading;
    }
  }

  previous_reading = current_reading;

  return isPressed;
}

void setup()
{
  initRGB();
  initButtons();
}

int led_index = 0;

void loop()
{
  if (isButtonPressed(GREEN_BUTTON) || isButtonPressed(RED_BUTTON))
  {
    digitalWrite(led[led_index], LOW);
    led_index = (led_index + 1) % 5; 
    digitalWrite(led[led_index], HIGH);
  }
}
