# 1 "d:\\ESP32\\ESP32 DevKitC V4\\T10. ESP32 BLE Slave\\BLE_Serial_Slave_Test.ino"
//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

# 8 "d:\\ESP32\\ESP32 DevKitC V4\\T10. ESP32 BLE Slave\\BLE_Serial_Slave_Test.ino" 2
# 17 "d:\\ESP32\\ESP32 DevKitC V4\\T10. ESP32 BLE Slave\\BLE_Serial_Slave_Test.ino"
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
// delay(20);
}
