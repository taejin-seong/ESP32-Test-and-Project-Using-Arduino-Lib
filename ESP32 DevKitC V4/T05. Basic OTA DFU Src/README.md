## Note

<br>

[Basic_OTA_Test.ino](https://github.com/taejin-seong/ESP32-Test-and-Project-Using-Arduino-Lib/tree/master/ESP32%20DevKitC%20V4/T05.%20Basic%20OTA) 와
[Basic_OTA_DFU_Src_Test.ino](https://github.com/taejin-seong/ESP32-Test-and-Project-Using-Arduino-Lib/tree/master/ESP32%20DevKitC%20V4/T05.%20Basic%20OTA%20DFU%20Src)
 는 `Examples for ESP32 Module` → `ArduinoOTA` → **`BasicOTA.ino`** 예제를 참고함.
 
새로 업데이트 되는 펌웨어가 다음번에도 OTA DFU를 수행할 수 있도록 하려면 **기존 OTA 프로그램의 틀은 그대로 유지하고** 업로드 이후 동작할 내역들만 바꿔줘야함.
 
 <br>
 <br>
 
 ```C
 const char ssid = "//";
 const char password = "//";
 ```
 * 이 부분에서는 사용하고 있는 WiFi 공유기의 SSID와 패스워드를 입력하면 됨.

 <br>
 <br>
 
<p align="left">
   <img src="https://user-images.githubusercontent.com/70312248/169761686-38b8bb12-7469-4c6e-a20d-0299a4926921.PNG" width="672" height="310"/>  
</p> 

* `setup()` 함수에는 먼저 **`WiFi.mode(WIFI_STA);`** 으로 WiFi를 스테이션 모드로 접속하도록 되어 있음.

* `setup()`함수 아래에 주석처리 된 부분은 필요에 맞게 활성화 시켜 수정하면 됨.
    
    +  **`ArduinoOTA.setPort();`**
        - 포트 지정
    
    +  **`ArduinoOTA.setHostname("//");`**
        - 호스트 (ESP32) 이름 지정
      
    +  **`ArduinoOTA.setPassword("//");`**
        - ESP32 패스워드 지정, 설정 시 해당 ESP32로 OTA DFU를 진행할 때마다 지정된 패스워드를 입력해야함. 

<br>
<br>
<br>

<p align="left">
   <img src="https://user-images.githubusercontent.com/70312248/169763125-0a823e25-0440-46c9-a9ee-4829ffb033f5.PNG" width="776" height="147"/>  
</p> 

* **VS Code 개발환경**에서는 Arduino IDE과 달리 Network Port를 추가시키기 위해 `./vscode` → `arduino.json`에서  **`"port": "EPS32 IP"`** 입력시켜주어야 함. 

  + **`"ESP32 IP"`** 를 WiFi 공유기 설정관리자를 통해 확인해서 입력해야 함. 본 테스트에서는 `192.168.0.22`로 잡혀있음.

* 그리고 빌드를 시키면 아래와 같이 OTA DFU가 완료됨.

<br>

<p align="left">
   <img src="https://user-images.githubusercontent.com/70312248/169765818-633df956-9d82-4d3f-a67a-202dacac167f.PNG" width="797" height="909"/>  
</p> 

<br>

....

<br>

<p align="left">
   <img src="https://user-images.githubusercontent.com/70312248/169766111-f79a85a4-5785-4362-8cc8-b335f8f2c9e4.PNG" width="1176" height="920"/>  
</p>

