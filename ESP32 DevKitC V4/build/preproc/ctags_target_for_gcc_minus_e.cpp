# 1 "d:\\ESP32\\ESP32 DevKitC V4\\P04. IOT Thermo-Hygrometer\\TH_Sensor_MQTT_Pub.ino"
# 2 "d:\\ESP32\\ESP32 DevKitC V4\\P04. IOT Thermo-Hygrometer\\TH_Sensor_MQTT_Pub.ino" 2
# 3 "d:\\ESP32\\ESP32 DevKitC V4\\P04. IOT Thermo-Hygrometer\\TH_Sensor_MQTT_Pub.ino" 2
# 4 "d:\\ESP32\\ESP32 DevKitC V4\\P04. IOT Thermo-Hygrometer\\TH_Sensor_MQTT_Pub.ino" 2





DHT dht(33 /* ESP33 pin GIOP27 (ADC1_5) connected to DHT11 */, DHT11);

const char* ssid = "Home";
const char* password = "257535411186f";
const char* mqttServer = "192.168.0.22";

WiFiClient espClient;
PubSubClient client(espClient);

int ledState = 0x0;
long lastMsg = 0;
float Humi = 0;
float Temp = 0;

void setup(){
    Serial.begin(115200);

    pinMode(18 /*ESP32 pin GPIO18 connected to LED*/, 0x03);

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
      digitalWrite(18 /*ESP32 pin GPIO18 connected to LED*/, 0x1);
  }
  else{
      digitalWrite(18 /*ESP32 pin GPIO18 connected to LED*/, 0x0);
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
