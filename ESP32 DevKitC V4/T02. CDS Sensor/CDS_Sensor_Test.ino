#define CDS_PIN     35  //ESP32 pin GPIO35 (ADC1_7) connected to Light Sensor

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.println(analogRead(CDS_PIN));
    delay(100);
}