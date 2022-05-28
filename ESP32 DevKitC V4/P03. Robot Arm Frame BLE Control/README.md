## 개발환경
### IDE
* VSCode 

### 개발 보드
* [**ESP32 DevKitC V4**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html) (2EA) 

### 부품
* [MPU-6050 6축 자이로/가속도 센서 모듈](https://www.devicemart.co.kr/goods/view?no=1247052)
* [2-DOF 로봇 프레임](https://ko.aliexpress.com/item/4000185708888.html)
* [MG996R 서보모터](https://www.devicemart.co.kr/goods/view?no=1313388) (2EA)

<br>

## 하드웨어 구성

### 컨트롤러 부
<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/170770820-49075cdf-1bb7-4fd7-8ffb-f8118a135698.png" width="519" height="515"/>  
</p> 
<br>

### 로봇 팔 프레임 제어부
<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/170773508-556b59fd-6531-473e-b96a-3091d0d5c420.png" width="769" height="513"/>  
</p> 
<br>


## 동작 방식
<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/170819835-35f05298-6f7d-4936-895a-6e1cce9b8b44.png" width="790" height="500"/>  
</p> 

* Roll, Pitch 값의 범위에 따라 **GO, Back, Right, Left** 를 선정하여 제어 신호를 결정

* 컨트롤러에서 로봇팔 프레임 제어부로 **제어 신호**를 블루투스 전송

* 로봇팔 프레임 제어부에서는 **Go**, **Back** 신호를 받았다면 **상측부의 서보모터**를 제어, **Right**, **Left** 신호를 받았다면 **하측부 서보모터**를 제어

<br>


## 동작 영상

https://user-images.githubusercontent.com/70312248/170819375-8886ab9d-11d3-42e4-a4cb-bfccf9408b28.mp4

* 상측부 제어 영상

