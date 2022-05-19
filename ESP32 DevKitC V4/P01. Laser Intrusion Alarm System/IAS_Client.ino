#include <WiFi.h>
#include "time.h"

#define LED_PIN     18  //ESP32 pin GPIO18 connected to LED
#define CDS_PIN     35  //ESP32 pin GPIO35 (ADC1_7) connected to Light Sensor
#define LASER_PIN   17  //ESP32 pin GPIO36 connected to Laser Sensor 
#define PIEZO_PIN   26  //ESP32 pin GIOP26 (PWM) connected to Piezo Buzzer       
#define CDS_REF     2200

const char*     ssid            = "\\";  //WiFi SSID
const char*     password        = "\\";  //WiFi Password
const uint16_t  port            = \\;    //Port Number
const char *    host            = "\\";  //Host IP

struct tm       timeinfo;                               // time infomation struct 

const char*     ntpServer       =   "kr.pool.ntp.org";
const long      gmtOffset_sec   =   32400;              // South Korea : GMT+9 = 9*32400 = 32400
const int       summerTime      =   0;                  // South Korea : No Summer Time

const uint8_t   pwmChannel      =   0;      
uint8_t         ledState        =   LOW;
uint16_t        cdsValue;

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
    pinMode(LED_PIN, OUTPUT);
    pinMode(LASER_PIN, OUTPUT);            
    ledcAttachPin(PIEZO_PIN, pwmChannel);  // Attach channel to Piezo pin
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
    
    digitalWrite(LASER_PIN, HIGH); // Open the laser head
    cdsValue = analogRead(CDS_PIN); // Read CDS Sensor Value
    
//    Serial.println(cdsValue);     // Check CDS Sensor Value

    if (cdsValue < CDS_REF)
    {
        if (!getLocalTime(&timeinfo))
        {
            client.println("Failed to obtain time");
        }
        
        /* Data & Time */  
        client.print(&timeinfo,"%Y-%B-%d %A %H:%M:%S");
        client.print("Intruder Detected!");    
        
        /* beep & warning light */
        digitalWrite(LED_PIN, ledState);
        ledcWriteNote(pwmChannel, NOTE_G, 5);
        ledState = !ledState;
        delay(300);

        client.stop();
    }
    /* init */
    digitalWrite(LED_PIN,  0);              
    ledcWrite(pwmChannel, 0);
}