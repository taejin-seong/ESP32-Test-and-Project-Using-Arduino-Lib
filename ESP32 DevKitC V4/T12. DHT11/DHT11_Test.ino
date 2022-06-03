#include "DHT.h"

#define DHTPIN  33 // ESP33 pin GIOP27 (ADC1_5) connected to DHT11 
#define DHTTYPE DHT11 // if DHT22, Making changes to DHT11 -> DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup(){
    Serial.begin(115200);
    Serial.println(F("DHTxx Test!"));

    dht.begin();
}

void loop(){
    delay(2000); // DHT11, DHT22 센서는 온습도의 측정을 2초 이내의 간격으로 하지말아야함.

    float h = dht.readHumidity(); // 습도 읽어오기 
    float t = dht.readTemperature(); // 온도 읽어오기

    if (isnan(h) || isnan(t)){
        Serial.println(F("Failed to read from DHT sensor"));
        return;
    }

    Serial.print(F("Humidity"));
    Serial.print(h);
    Serial.print(F("% Temperature"));
    Serial.print(t);
    Serial.print(F(" °C"));
    Serial.println("");
}