# 1 "d:\\ESP32\\ESP32 DevKitC V4\\test\\test.ino"
# 2 "d:\\ESP32\\ESP32 DevKitC V4\\test\\test.ino" 2
# 3 "d:\\ESP32\\ESP32 DevKitC V4\\test\\test.ino" 2







const char* ssid = "Home"; //WiFi SSID
const char* password = "257535411186f"; //WiFi Password
const uint16_t port = 9190; //Port Number
const char * host = "192.168.0.2"; //Host IP

struct tm timeinfo; // time infomation struct 

const char* ntpServer = "kr.pool.ntp.org";
const long gmtOffset_sec = 32400; // South Korea : GMT+9 = 9*32400 = 32400
const int summerTime = 0; // South Korea : No Summer Time

const uint8_t pwmChannel = 0;
uint8_t ledState = 0x0;
uint16_t cdsValue;

void setup() {

    /* WiFi */
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("...");
    }

    Serial.println("WiFi connected with IP: ");
    Serial.println(WiFi.localIP());

    configTime(gmtOffset_sec, summerTime, ntpServer);

    /* LED, Laser, Piezo */
    pinMode(18 /*ESP32 pin GPIO18 connected to LED*/, 0x03);
    pinMode(17 /*ESP32 pin GPIO36 connected to Laser Sensor */, 0x03);
    ledcAttachPin(26 /*ESP32 pin GIOP26 (PWM) connected to Piezo Buzzer       */, pwmChannel); // Attach channel to Piezo pin
}

void loop() {

    WiFiClient client;

    if (!client.connect(host, port))
    {
        Serial.println("Connection to host failed");
        delay(1000);

        return;
    }

    Serial.println("Connected to server successful!");
    Serial.println("Intruder Alert System Start...");

    digitalWrite(17 /*ESP32 pin GPIO36 connected to Laser Sensor */, 0x1); // Open the laser head
    cdsValue = analogRead(35 /*ESP32 pin GPIO35 (ADC1_7) connected to Light Sensor*/); // Read CDS Sensor Value

//    Serial.println(cdsValue);     // Check CDS Sensor Value

    if (cdsValue < 2200)
    {
        if (!getLocalTime(&timeinfo))
        {
            client.println("Failed to obtain time");
        }

        /* Data & Time */
        client.print(&timeinfo,"%Y-%B-%d %A %H:%M:%S");
        client.print("Intruder Detected!");

        /* beep & warning light */
        digitalWrite(18 /*ESP32 pin GPIO18 connected to LED*/, ledState);
        ledcWriteNote(pwmChannel, NOTE_G, 5);
        ledState = !ledState;
        delay(300);

        client.stop();
    }
    /* init */
    digitalWrite(18 /*ESP32 pin GPIO18 connected to LED*/, 0);
    ledcWrite(pwmChannel, 0);
}
