#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti   WiFiMulti;
WiFiClient  client;

void setup()
{
    Serial.begin(115200);
    delay(10);
    WiFiMulti.addAP("SSID", "PW");   //Input SSID, PW

    Serial.println("\n Waiting for WiFi...");

    while (WiFiMulti.run() != WL_CONNECTED)
    {
        Serial.println(".");
        delay(500);
    }
    
    Serial.println("WiFi connected");
    Serial.println("IP address : ");
    Serial.println(WiFi.localIP());

    delay(500);           
}


void connections(void)
{
    const uint16_t port = XXXX; // Input PORT Number
    const char * host = "XXX.XXX.XXX.XXX";  // Input IP Number 

    Serial.println("Connecting to");
    Serial.println(host);

    if (!client.connect(host, port))
    {
        Serial.println("Connection failed.");
        Serial.println("Waiting 5 second before retrying...");
        delay(5000);
        
        return ;
    }

}

void loop()
{
    connections();
    client.print("Hello World!!");
    delay(1000);
}