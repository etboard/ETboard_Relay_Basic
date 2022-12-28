/******************************************************************************************
 * FileName     : 2. relay_button_2
 * Description  : 릴레이와 이티보드의 버튼 2개를 사용하여 led제어 해보기
 * Author       : 윤승열
 * Created Date : 2022.10.19
 * Reference    : 
 * Modified     : 
******************************************************************************************/

int button_red = D6;                                  // 빨강 버튼
int button_blue = D7;                                 // 파랑 버튼
int relay = D9;                                       // 릴레이
//int relay = D2;                                       // 릴레이
//int relay = D3;                                       // 릴레이
//int relay = D4;                                       // 릴레이
//int relay = D5;                                       // 릴레이
//int relay = D6;                                       // 릴레이
//int relay = D7;                                       // 릴레이
//int relay = A4;                                       // 릴레이
int red_led = D2;                                     // 빨강 LED


void setup() {
  pinMode(button_red, INPUT_PULLUP);                  // 입력 모드
  pinMode(button_blue, INPUT_PULLUP);                 // 입력 모드
  pinMode(relay, OUTPUT);                             // 출력 모드
  pinMode(red_led, OUTPUT);                           // 출력 모드
  Serial.begin(115200);                               // 통신속도 설정
}


void loop() {
 int button_red_status = digitalRead(button_red);     // 빨강 버튼의 값을 저장
 int button_blue_status = digitalRead(button_blue);   // 파랑 버튼의 값을 저장
 
 // 버튼이 눌렸는지 체크 버튼이 눌리면 LOW 눌리지 않으면 HIGH   
  if(button_red_status == LOW){                       // 빨강 버튼 누르면
   Serial.println("빨강버튼 눌림");            
   digitalWrite(relay, HIGH);                         // relay 동작
   digitalWrite(red_led, HIGH);                       // 빨강 led ON
   Serial.println("relay ON");          
  }
  if(button_blue_status == LOW){                      // 파란버튼을 누르면
    Serial.println("파랑버튼 눌림");          
    digitalWrite(relay, LOW);                         // relay 멈춤
    digitalWrite(red_led, LOW);                       // 빨강 led oFF
    Serial.println("relay OFF");        
  }
  delay(100);                                         // 0.1초 대기
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
