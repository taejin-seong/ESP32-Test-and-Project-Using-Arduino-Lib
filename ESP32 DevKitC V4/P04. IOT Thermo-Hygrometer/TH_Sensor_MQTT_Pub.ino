#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define LED_PIN     18  //ESP32 pin GPIO18 connected to LED
#define DHTPIN      33 // ESP33 pin GIOP33 (ADC) connected to DHT11 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = ".."; // WIFI SSID
const char* password = ".."; // WIFI Password
const char* mqttServer = "192.168.0.22"; // MQTT Server IP (Raspberry Pi 3b+)

WiFiClient espClient;
PubSubClient client(espClient);

int ledState = LOW;
long lastMsg = 0;
float Humi = 0;
float Temp = 0;

void setup(){
    Serial.begin(115200);
    
    pinMode(LED_PIN, OUTPUT);   
    
    dht.begin();

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  client.setServer(mqttServer, 1883); 
  client.setCallback(callback);
    
}

void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  if ((char)payload[0] == '1'){
      digitalWrite(LED_PIN, HIGH);
  }
  else{
      digitalWrite(LED_PIN, LOW);
  }
}

float getHumi(){

    float h = dht.readHumidity(); 
    return h;
}

float getTemp(){

    float t = dht.readTemperature();
    return t;
}

void reconnect(){

while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client")) {
 
      Serial.println("connected");
 
    } 
    else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void loop(){

    if (!client.connected()){
        reconnect();
    }
    client.loop();

    long now = millis();
    if (now - lastMsg > 2000){
        lastMsg = now;

        Temp = getTemp();
        char tempString[10];
        dtostrf(Temp, 4, 2, tempString);
        client.publish("esp/temperature", tempString);

        Humi = getHumi();
        char humiString[10];
        dtostrf(Humi, 4, 2, humiString);
        client.publish("esp/humidity", humiString);
    }
    delay(20);
}
