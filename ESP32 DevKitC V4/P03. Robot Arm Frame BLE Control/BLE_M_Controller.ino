#include "BluetoothSerial.h"
#include <Wire.h>

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

/* BLE */
BluetoothSerial SerialBT;

String MACadd = "AA:BB:CC:11:22:33";
uint8_t address[6]  = {0xAA, 0xBB, 0xCC, 0x11, 0x22, 0x33};
String name = "ESP32test";  
const char *pin = "1234"; 
bool connected;

/* MPU6050 */
const int MPU_ADDR = 0x68;    
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY;   
double angleAcX, angleAcY, angleAcZ;
double angleGyX, angleGyY;
double angleFiX, angleFiY;

const double RADIAN_TO_DEGREE = 180 / 3.14159;  
const double DEG_PER_SEC = 32767 / 250;   
const double ALPHA = 1 / (1 + 0.04);

unsigned long now = 0;   
unsigned long past = 0;  
double dt = 0;           

double averAcX, averAcY, averAcZ;
double averGyX, averGyY;

enum Control{
  GO = 1,
  BACK,
  RIGHT,
  LEFT
};


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test", true); 
  Serial.println("The device started in master mode, make sure remote BT device is on!");   /* Replaceable with LED blinking */

  connected = SerialBT.connect(name);
  Serial.println("Trying Connection");  /* Replaceable with LED blinking */
  
  while (connected != true){
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app."); /* Replaceable with LED blinking */
    }
    if (SerialBT.connected() == false){
      connected = SerialBT.connect(name);
      Serial.println("Trying Connection"); /* Replaceable with LED blinking */
    }
  }
  Serial.println("Connected Succesfully!"); /* Replaceable with LED blinking */

  initSensor();
  Serial.begin(115200);
  caliSensor();     
  past = millis(); 
}


void loop() {
  getData(); 
  getDT();

  angleAcX = atan(AcY / sqrt(pow(AcX, 2) + pow(AcZ, 2)));
  angleAcX *= RADIAN_TO_DEGREE;
  angleAcY = atan(-AcX / sqrt(pow(AcY, 2) + pow(AcZ, 2)));
  angleAcY *= RADIAN_TO_DEGREE;

  angleGyX += ((GyX - averGyX) / DEG_PER_SEC) * dt;  
  angleGyY += ((GyY - averGyY) / DEG_PER_SEC) * dt;

  double angleTmpX = angleFiX + angleGyX * dt;
  double angleTmpY = angleFiY + angleGyY * dt;

  angleFiX = ALPHA * angleTmpX + (1.0 - ALPHA) * angleAcX;
  angleFiY = ALPHA * angleTmpY + (1.0 - ALPHA) * angleAcY;

/*
  Serial.print("FilteredX: ");      //Pitch
  Serial.print(angleFiX);;
  Serial.print(", FilteredY: ");    //Roll 
  Serial.print(angleFiY);
  Serial.print(", FilteredZ: ");    //Yaw
  Serial.println(" ");
*/
  SerialBT.write(getControl(angleFiX, angleFiY));

  delay(20);

}

void initSensor() {
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR);   
  Wire.write(0x6B);      
  Wire.write(0);
  Wire.endTransmission(true);
}

void getData() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, 1);  
  AcX = Wire.read() << 8 | Wire.read(); 
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  Tmp = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
}


void getDT() {
  now = millis();   
  dt = (now - past) / 1000.0;  
  past = now;
}


void caliSensor() {
  double sumAcX = 0 , sumAcY = 0, sumAcZ = 0;
  double sumGyX = 0 , sumGyY = 0, sumGyZ = 0;
  getData();
  for (int i=0;i<10;i++) {
    getData();
    sumAcX+=AcX;  sumAcY+=AcY;  sumAcZ+=AcZ;
    sumGyX+=GyX;  sumGyY+=GyY;  
    delay(50);
  }
  averAcX=sumAcX/10;  averAcY=sumAcY/10;  averAcZ=sumAcY/10;
  averGyX=sumGyX/10;  averGyY=sumGyY/10; 
}


int getControl(double Pitch, double Roll)
{
  if (Pitch < 10 ){
    return GO;
  }
  
  if (Pitch > 100 ){
    return BACK;
  }

  if (Roll > 90) {
    return RIGHT;
  }
  
  if (Roll < -100) {
    return LEFT;
  }

  return 0;
}
