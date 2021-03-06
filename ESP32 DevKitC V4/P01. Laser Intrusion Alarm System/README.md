

<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/169498179-292768f4-47dc-42de-84a5-a47a84af742c.png" width="876" height="395"/>  
</p> 
<br>


## 개발환경
### IDE
* VSCode 
* Python 3.6 IDLE 

### 개발 보드
* [**ESP32 DevKitC V4**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html) 

### 부품
* [KY-008 (레이저 송신모듈)](https://www.devicemart.co.kr/goods/view?no=1329650)
* [[YwRobot] 아두이노 조도센서 모듈](https://www.devicemart.co.kr/goods/view?no=1287124)
* [피에조 부저](https://www.devicemart.co.kr/goods/view?no=2733)

<br>

## 하드웨어 구성

<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/169490791-545be42b-c66b-495a-9576-87ba9d80126a.png" width="812" height="504"/>  
</p> 
<br>

## 동작 방식

<br>
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/169496612-4b714f00-ed61-46d8-9082-d649d9f7a49d.png" width="928" height="476"/>  
</p> 
<br>

* 레이저 모듈에 물체가 감지되면 서버로 날짜,시간과 함께 경보알림을 전송함.

<br>

## 동작 결과
### 물체가 감지되지 않은 경우
* 클라이언트 측
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/169500293-0bd4d081-5813-4ffc-8116-074d3845abd9.png" width="802" height="322"/>  
</p> 
<br>


* 서버 측 
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/169500420-defde7cf-6fe1-420d-bad6-d4154dda626d.png" width="590" height="105"/>  
</p> 
<br>


### 물체가 감지된 경우

* 클라이언트 측 경보알림 전송
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/169499224-aa6df926-6dae-46c2-bc3b-7ef7cc72a00f.png" width="802" height="322"/>  
</p> 
<br>


* 서버 측 경보알림 수신
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/169499486-934dbc09-91a0-4cbd-a12a-f568cd2506eb.png" width="590" height="105"/>  
</p> 
<br>



## 동작 영상




https://user-images.githubusercontent.com/70312248/169500917-b6c53a6e-be3f-4905-a59e-d3ee5430e30a.mp4


