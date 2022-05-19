#define LED_PIN     18  //ESP32 pin GPIO18 connected to LED

int ledState = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, ledState);
  ledState = !ledState;
  delay(50);
}