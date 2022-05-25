#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup(){
    Wire.begin();
    Serial.begin(115200);
    accelgyro.initialize();
}

void loop()
{
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    Serial.print(ax); Serial.print(",");
    Serial.print(ay); Serial.print(",");
    Serial.print(az); Serial.print(",");
    Serial.print(gx); Serial.print(",");
    Serial.print(gy); Serial.print(",");
    Serial.print(gz); 
    Serial.println("");

}
