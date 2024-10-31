#include <Arduino.h>

const uint8_t buttonPin = 0;
const uint8_t led1Pin = 14;
const uint8_t led2Pin = 2;
uint16_t timer1 = 2000;

volatile bool buttonPressed = true;

void ICACHE_RAM_ATTR handleButtonPress() {
  static uint16_t lastInterruptTime = 0;
  uint16_t interruptTime = millis();

  if (interruptTime - lastInterruptTime > 200) {
    buttonPressed = !buttonPressed;
    (timer1<=200)? timer1=2000 : timer1 -= 200;
  }

  lastInterruptTime = interruptTime;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1Pin, HIGH);
  delay(timer1);
  digitalWrite(led2Pin, LOW);
  delay(timer1);
  digitalWrite(led1Pin, LOW);
  delay(timer1);
  digitalWrite(led2Pin, HIGH);
  delay(timer1);
}
