<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/176612583-e1f8d303-d9c5-4adf-ad32-465a3c6cc23c.png" width="560" height="400"/>  
</p> 
<br>

## 개발환경
### IDE
* VSCode 
* Node-RED

### 개발 보드
* [**ESP32 DevKitC V4**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html) 
* [**Raspberry Pi 3B+**](https://www.devicemart.co.kr/goods/view?no=1377518)

### 부품
* [DHT11 온습도 센서모듈](https://www.devicemart.co.kr/goods/view?no=1278926)

<br>

## 시스템 구성

### ESP32 DevKitC V4 구성

<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/176618452-eba4e520-0ee6-4f2f-9427-de4ff367c9a4.png" width="872" height="516"/>  
</p> 
<br>

### Node-RED 구성

<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/176641331-418213f3-6057-49c7-9b72-78e9329ce98f.png" width="1365" height="550"/>  
</p> 

* [클립보드](https://github.com/taejin-seong/ESP32-Test-and-Project-Using-Arduino-Lib/blob/master/ESP32%20DevKitC%20V4/P04.%20IOT%20Thermo-Hygrometer/flows.json) 소스코드 참고

<br>



## 동작 방식

### 인터페이스 개요

<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/176630456-d2a37c81-a6ad-49b8-9b9f-4fb34a6ab35a.png" width="898" height="519"/>  
</p> 
<br>

* **해당 프로젝트는 MQTT 프로토콜을 기반으로 IOT 프로그램을 수행함.**

<br>

* 라즈베리파이 3B+와 ESP32 DevKit C는 같은 **로컬 네트워크**에 연결되어 있음. 
* 라즈베리파이 3B+에는 **Mosquitto 브로커 서버** 와 **Node-RED** 프로그램이 설치되어있음.
* 즉, 라즈베리파이 3B+은 MQTT 프로토콜에서의 브로커 서버 역할과 함께 Client 역할도 수행함.
* ESP32의 Port는 1883으로 설정하였으며 Node-RED의 Port는 1880 (기본값)임.
* ESP32와 Node-RED는 Mosquitto 서버에 연결되어 있으며 포트로 구분됨.

<br>

### MQTT 프로토콜 과정

<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/176638981-365e4d8a-fd3a-412e-8f00-c9fd1ba26205.png" width="900" height="409"/>  
</p> 
<br>

* ESP32는 DHT11 센서모듈에서 온도와 습도 값을 읽어 **MQTT Broker에 게시(Publish)를 요청함.**
* 온도 측정 값은 MQTT Broker의 **esp/temperature 주제(Topic)에 게시됨.**
* 습도 측정 값은 MQTT Broker의 **esp/humidity 주제(Topic)에 게시됨.**
* Node-RED는  **MQTT Broker의 esp/temperature와 esp/humidity 주제(Topic)를 구독(Subscrib)하며**, Node-RED Dashboard의 온도와 습도 게이지(Gauge)에 각각 출력(표시)함. 

<br>


## 동작 결과

### 테스트 환경

<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/176646779-74152269-3873-4b1a-ae18-b77985077529.png" width="1191" height="561"/>  
</p> 
<br>

* 2022년 6월 30일 목요일 새벽 03:49 여름, 장마철로 인해 계속 비가 오는 중
* 서울 습도 97%, 외부 온도 22.4도, 체감온도 25.5도  
* **테스트는 거주 중인 방안에서 실행되었으며** 컴퓨터 2대, 모니터 3대, 그외 각종 전자기기 등이 작동 중. 냉방장치 (에어컨, 선풍기)는 작동하지 않은 상태.
     따라서 대략 30~31도가 나오는 것이 맞음.
    
 <br>
    
* 이러한 상황에서 선풍기를 가동시켜 온습도의 변화율을 Node-RED DashBoard를 통해 관찰.


<br>

![결과 1](https://user-images.githubusercontent.com/70312248/176513234-ab5a7d28-6679-4d99-9a37-3921e7fb69d9.gif)

<br>


    
