## Note

<br>

[OTA_Web_Updater_Test.ino](https://github.com/taejin-seong/ESP32-Test-and-Project-Using-Arduino-Lib/tree/master/ESP32%20DevKitC%20V4/T06.%20OTA%20Web%20Updater) 와
[OTA_Web_Updater_DFU_Src_Test.ino](https://github.com/taejin-seong/ESP32-Test-and-Project-Using-Arduino-Lib/tree/master/ESP32%20DevKitC%20V4/T06.%20OTA%20Web%20Updater%20DFU%20Src)
 는 `Examples for ESP32 Module` → `ArduinoOTA` → **`OTAWebUpdater.ino`** 예제를 참고함.
 
새로 업데이트 되는 펌웨어가 다음번에도 OTA DFU를 수행할 수 있도록 하려면 **기존 OTA 프로그램의 틀은 그대로 유지하고** 업로드 이후 동작할 내역들만 바꿔줘야함.
 
 <br>
 <br>
 
 ```C
 const char* host = "esp32";
 const char* ssid = "//";
 const char* password = "//";
 ```
 * 이 부분에서는 사용하고 있는 WiFi 공유기의 SSID와 패스워드를 입력하면 됨.

 <br>
 <br>
 
<p align="left">
   <img src="https://user-images.githubusercontent.com/70312248/169790338-3b4da6bd-a2d4-4614-ba46-116ab75d1f73.PNG" width="399" height="148"/>  
</p> 

* OTA DFU를 위한 웹페이지에 접속하기 위해 **접속 IP (ESP32 IP)를 브라우저에 url 입력해야함.**

  + ESP32 IP는 처음 OTA 프로그램을 업로드할 때 시리얼 모니터에 나타나므로 이를 입력하면 됨.

  + 본 테스트에서는 `192.168.0.22`으로 ESP32 IP이므로 이를 통해 주소창에 입력하여 접속함.

* 웹페이지를 접속하면 위 그림과 같이 **Username**과 **Password**를 입력해야하는데 초기 Username과 Password는 `admin`,`admin` 임.

  + 아래 그림 참고
   
<br>

<p align="left">
   <img src="https://user-images.githubusercontent.com/70312248/169790561-dca39ec9-a100-4193-97b4-d0b7a140fdc9.PNG" width="1127" height="320"/>  
</p> 

<br>
<br>


<p align="left">
   <img src="https://user-images.githubusercontent.com/70312248/169792554-68ecc69d-551f-49f5-846a-898f69b565f8.png" width="389" height="125"/>  
</p> 

* 웹페이지에 **Username**과 **Password**를 넣으면 위와 같은 창이 뜨는데 이 창에서 `파일선택`버튼을 눌러 `.bin`파일을 선택한 후 `Update` 버튼을 누르면 무선 펌웨어 업데이트가 완료됨.

<br>
<br>


<p align="left">
   <img src="https://user-images.githubusercontent.com/70312248/169790546-dff876c8-9f18-4fc2-b26b-ce1f075bd421.PNG" width="597" height="288"/>  
</p> 

* **VS Code** 개발환경에서 `.bin`파일은 본 테스트 환경과 동일하다면 즉, `arduino.json`에서 **`"output: ".\\build"`** 으로 설정하였다면 `build`폴더 아래에 위 그림과 같이 저장되어 있음.


<br>

* OTA DFU를 진행하기 위해서는 **먼저 포트에 ESP32를 연결하고** 기본 OTA Web Updater 코드를 다운로드한 다음,  <br>
 **그 이후에 포트에 ESP32를 연결하지 않고** OTA DFU할 파일을 빌드하여 `.bin`파일을 생성시킬 텐데,  <br>
  이 때 `arduino.json`에 설정되어 있는 시리얼 포트가 잡히지 않아 다운로드가 되지 않는다고 에러가 뜬다. <br> 
  하지만, 빌드는 정상적으로 된 상태이므로  컴파일된 `.bin` 파일은 생성된다. 따라서 에러는 무시하고 생성된 `.bin`파일을  OTA Web Updater에 사용하면 된다.

<br>

* 로그인 페이지가 HTML과 JS로만 이루어져 있기 때문에 보안상 이슈가 있음. 


