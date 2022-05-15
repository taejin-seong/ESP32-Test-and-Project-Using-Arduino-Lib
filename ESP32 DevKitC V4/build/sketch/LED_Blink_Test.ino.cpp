#include <Arduino.h>
#line 1 "d:\\ESP32\\ESP32 DevKitC V4\\LED Blink\\LED_Blink_Test.ino"
#define LED_PIN     18  //ESP32 pin GPIO18 connected to LED

int ledState = LOW;

#line 5 "d:\\ESP32\\ESP32 DevKitC V4\\LED Blink\\LED_Blink_Test.ino"
void setup();
#line 9 "d:\\ESP32\\ESP32 DevKitC V4\\LED Blink\\LED_Blink_Test.ino"
void loop();
#line 5 "d:\\ESP32\\ESP32 DevKitC V4\\LED Blink\\LED_Blink_Test.ino"
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, ledState);
  ledState = !ledState;
  delay(50);
}
