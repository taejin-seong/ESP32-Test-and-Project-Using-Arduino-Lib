#include <Arduino.h>
#line 1 "d:\\ESP32\\ESP32 DevKitC V4\\T11. Joystick\\Joystick_Test.ino"
const int X_PIN   = 27; // X 축 아날로그 입력 핀, ESP32 pin GIOP27 (ADC2_7) connected to Joystick 
const int Y_PIN   = 26; // Y 축 아날로그 입력 핀, ESP32 pin GIOP26 (ADC2_9) connected to Joystick 
const int S_Pin   = 25; // Select 디지털 입력 핀, ESP32 pin GIOP32 connected to Joystick 

#line 5 "d:\\ESP32\\ESP32 DevKitC V4\\T11. Joystick\\Joystick_Test.ino"
void setup();
#line 12 "d:\\ESP32\\ESP32 DevKitC V4\\T11. Joystick\\Joystick_Test.ino"
void loop();
#line 5 "d:\\ESP32\\ESP32 DevKitC V4\\T11. Joystick\\Joystick_Test.ino"
void setup() {
  // 모니터용 시리얼 시작
  Serial.begin(115200);
  // Select 디지털 입력핀 설정, 풀업 상태로 설정.
  pinMode(S_Pin, INPUT_PULLUP);   
}

void loop() {
 // sel 핀 읽어오기
 int sel = digitalRead(S_Pin);
 // y 축 핀 아날로그 입력 읽어오기
 int y = analogRead(Y_PIN);
 // x 축 핀 아날로그 입력 읽어오기
 int x = analogRead(X_PIN);

//ESP32는 아날로그의 입력범위가 0~4095 (12bit 해상도)
// 0-255로 변경 (12bit (0~4095)-> 8bit (0~255))
 x >>=4;
 y >>=4;

 // 출력!
 Serial.print("x: ");
 Serial.print(x);
 Serial.print(", y: ");
 Serial.print(y);
 Serial.print(", push: ");
 Serial.println(sel);
 
 //100ms 대기
 delay(100);
}
