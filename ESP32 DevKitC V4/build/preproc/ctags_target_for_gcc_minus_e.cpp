# 1 "d:\\ESP32\\ESP32 DevKitC V4\\LED Blink\\LED_Blink_Test.ino"


int ledState = 0x0;

void setup() {
  pinMode(18 /*ESP32 pin GPIO18 connected to LED*/, 0x03);
}

void loop() {
  digitalWrite(18 /*ESP32 pin GPIO18 connected to LED*/, ledState);
  ledState = !ledState;
  delay(50);
}
