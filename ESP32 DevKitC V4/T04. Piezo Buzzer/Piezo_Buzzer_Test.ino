#define PIEZO_PIN  23 //ESP32 pin GIOP18 (PWM) connected to Piezo Buzzer             

void setup()            
{                
  pinMode(PIEZO_PIN, OUTPUT);    
}


void loop() 
{
/*
  analogWrite(PIEZO_PIN, 64);           // PWM 25% 
  delay(1000);                       
  analogWrite(PIEZO_PIN, 128);          // PWM 50% 
  delay(1000);                       
  analogWrite(PIEZO_PIN, 256);          // PWM 100% 
  delay(1000);                       
*/
  for (int i = 0; i < 256; i ++)
  {
    analogWrite(PIEZO_PIN, i);
    delay(1000);
  }
}