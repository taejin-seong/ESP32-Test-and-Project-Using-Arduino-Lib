# 1 "d:\\ESP32\\ESP32 DevKitC V4\\P02. BLE Keyboard\\BLE_Keyboard.ino"
/**

 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete

 */
# 4 "d:\\ESP32\\ESP32 DevKitC V4\\P02. BLE Keyboard\\BLE_Keyboard.ino"
# 5 "d:\\ESP32\\ESP32 DevKitC V4\\P02. BLE Keyboard\\BLE_Keyboard.ino" 2

BleKeyboard bleKeyboard;






int pre_btn1_status;
int pre_btn2_status;
int pre_btn3_status;
int pre_btn4_status;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();

  pinMode(23, 0x05);
  pinMode(19, 0x05);
  pinMode(5, 0x05);
  pinMode(18, 0x05);

  pre_btn1_status = digitalRead(23);
  pre_btn2_status = digitalRead(19);
  pre_btn3_status = digitalRead(5);
  pre_btn4_status = digitalRead(18);
}

void loop() {
    while (bleKeyboard.isConnected())
    {
        int btn1_status = digitalRead(23);
        int btn2_status = digitalRead(19);
        int btn3_status = digitalRead(5);
        int btn4_status = digitalRead(18);

        if ( (pre_btn1_status == 0x1) && (btn1_status == 0x0) )
        {
            bleKeyboard.print("Hello World!"); // 1번 버튼을 누를 경우 Hello World! 전송
            bleKeyboard.releaseAll();
        }

        if ( (pre_btn2_status == 0x1) && (btn2_status == 0x0) )
        {
            bleKeyboard.print(millis()); // 2번 버튼을 누를 경우 현재의 millis() 시간을 전송.
            bleKeyboard.releaseAll();
        }

        if ( (pre_btn3_status == 0x1) && (btn3_status == 0x0) )
        {
            bleKeyboard.write(KEY_RETURN); // 3번 버튼을 누를 경우 키보드의 Enter 키를 누름.
            bleKeyboard.releaseAll();
        }

        if ( (pre_btn4_status == 0x1) && (btn4_status == 0x0) )
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
