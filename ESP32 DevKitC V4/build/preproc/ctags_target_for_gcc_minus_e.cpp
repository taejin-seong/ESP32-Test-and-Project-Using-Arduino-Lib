# 1 "d:\\ESP32\\ESP32 DevKitC V4\\T14. ESP32 MQTT Publish\\ESP32_MQTT_Publish_Test.ino"
# 2 "d:\\ESP32\\ESP32 DevKitC V4\\T14. ESP32 MQTT Publish\\ESP32_MQTT_Publish_Test.ino" 2
# 3 "d:\\ESP32\\ESP32 DevKitC V4\\T14. ESP32 MQTT Publish\\ESP32_MQTT_Publish_Test.ino" 2

const char* ssid = "Home";
const char* password = "257535411186f";
const char* mqttServer = "broker.mqtt-dashboard.com";;
const int mqttPort = 1883;
//const char* mqttUser = "yourMQTTuser";
//const char* mqttPassword = "yourMQTTpassword";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");

  client.setServer(mqttServer, mqttPort);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP32Client")) {

      Serial.println("connected");

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);

    }
  }

  client.publish("esp/test", "Hello, Subscriber! I'm ESP32 Publisher ");

}

void loop() {
  client.loop();
}
