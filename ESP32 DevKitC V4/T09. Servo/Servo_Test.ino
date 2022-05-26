#include <ESP32_Servo.h>

static const int SERVO_PIN1 = 17; //ESP32 pin GIOP19 (PWM) connected to Servo Motor

Servo servo1;

void setup() {
    Serial.begin(115200);
    servo1.attach(SERVO_PIN1);
}

void loop() {
    for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
        servo1.write(posDegrees); // 모터의 각도를 설정
        Serial.println(posDegrees);
        delay(20);
    }

    for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
        servo1.write(posDegrees); // 모터의 각도를 설정
        Serial.println(posDegrees);
        delay(20);
    }
}
