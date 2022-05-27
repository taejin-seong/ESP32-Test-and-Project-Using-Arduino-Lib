#include "BluetoothSerial.h"
#include <ESP32_Servo.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

static const int SERVO_PIN1 = 17; //ESP32 pin GIOP17 (PWM) connected to Servo Motor
static const int SERVO_PIN2 = 4;  //ESP32 pin GIOP4 (PWM) connected to Servo Motor

int posDegrees1;
int posDegrees2;

Servo servo1;
Servo servo2;

enum Control{
  GO = 1,
  BACK,
  RIGHT,
  LEFT
};

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test");
  Serial.println("The device started, now you can pair it with bluetooth!"); /* Replaceable with LED blinking */

  servo1.attach(SERVO_PIN1);
  servo1.attach(SERVO_PIN2);
  posDegrees1 = 160;
  posDegrees2 = 90;  
}

void loop() {

  int ControlArm = SerialBT.read();
  delay(20);

//  Serial.print(ControlArm);

  if (ControlArm == GO)
  {
      posDegrees1--;
      servo1.write(posDegrees1);
  }

  if (ControlArm == BACK)
  {
      posDegrees1++;
      servo1.write(posDegrees1);
  }

  if (ControlArm == RIGHT)
  {
      posDegrees2--;
      servo2.write(posDegrees2);
  }

  if (ControlArm == LEFT)
  {
      posDegrees2++;
      servo2.write(posDegrees2);
  }

}