/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

#define BUTTON1_PIN 23
#define BUTTON2_PIN 19
#define BUTTON3_PIN 5
#define BUTTON4_PIN 18

int pre_btn1_status;
int pre_btn2_status;
int pre_btn3_status;
int pre_btn4_status;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();

  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);

  pre_btn1_status = digitalRead(BUTTON1_PIN);
  pre_btn2_status = digitalRead(BUTTON2_PIN);
  pre_btn3_status = digitalRead(BUTTON3_PIN);
  pre_btn4_status = digitalRead(BUTTON4_PIN); 
}

void loop() {
    while (bleKeyboard.isConnected())
    {
        int btn1_status = digitalRead(BUTTON1_PIN);
        int btn2_status = digitalRead(BUTTON2_PIN);
        int btn3_status = digitalRead(BUTTON3_PIN);
        int btn4_status = digitalRead(BUTTON4_PIN);

        if ( (pre_btn1_status == HIGH) && (btn1_status == LOW) )
        {
            bleKeyboard.print("Hello World!"); // 1번 버튼을 누를 경우 Hello World! 전송
            bleKeyboard.releaseAll();
        }

        if ( (pre_btn2_status == HIGH) && (btn2_status == LOW) )
        {
            bleKeyboard.print(millis());    // 2번 버튼을 누를 경우 현재의 millis() 시간을 전송.
            bleKeyboard.releaseAll();
        }
        
        if ( (pre_btn3_status == HIGH) && (btn3_status == LOW) )
        {
            bleKeyboard.write(KEY_RETURN);  // 3번 버튼을 누를 경우 키보드의 Enter 키를 누름.
            bleKeyboard.releaseAll();
        }

        if ( (pre_btn4_status == HIGH) && (btn4_status == LOW) )
        {
            bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE); // 4번 버튼을 누를 경우 미디어키 재생/정지 버튼을 누름
            bleKeyboard.releaseAll();
        }

        pre_btn1_status = btn1_status;
        pre_btn2_status = btn2_status;
        pre_btn3_status = btn3_status;
        pre_btn4_status = btn4_status;
    
    }
}