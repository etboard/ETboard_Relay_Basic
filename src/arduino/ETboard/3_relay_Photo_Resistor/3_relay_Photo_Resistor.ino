/******************************************************************************************
 * FileName     : 3. relay_Photo_Resistor
 * Description  : 이티보드의 조도센서를 이용하여 릴레이 제어
 * Author       : 윤승열
 * Created Date : 2022.10.19
 * Reference    : 
 * Modified     : 
******************************************************************************************/

int sensor = A1;                               // 조도센서
int relay = D9;                                // 릴레이
int red_led = D2;                              // 빨강 LED


void setup(){
 pinMode(red_led, OUTPUT);                    // 핀 모드 설정
 pinMode(relay, OUTPUT);                      // 핀 모드 설정
}


void loop(){
 int sensor_result = analogRead(sensor);      // 센서가 측정한 값 저장
  
 digitalWrite(red_led, LOW);
 digitalWrite(relay, LOW);
                                          
 if(sensor_result < 1200){                   // 센서측정값이 1200미만 이라면 relay on
  digitalWrite(relay, HIGH);                 // 릴레이 ON
  digitalWrite(red_led, HIGH);               // 빨강 LED ON
  Serial.println("relay ON");
 }
 
 else {                                     // 아니라면
  digitalWrite(relay, LOW);                 // 릴레이 OFF
  digitalWrite(red_led, LOW);               // 빨강 LED OFF
  Serial.println("relay OFF");
 }
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
