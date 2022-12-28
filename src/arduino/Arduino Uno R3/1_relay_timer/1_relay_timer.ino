/******************************************************************************************
 * FileName     : relay_ONOFF
 * Description  : 릴레이와 아두이노를 사용하여 ON,OFF제어 해보기
 * Author       : 윤승열
 * Created Date : 2022.10.18
 * Reference    : 
 * Modified     : 보드매니저에서 아두이노로 설정한다.
******************************************************************************************/

void setup() {
  pinMode(9, OUTPUT);            // 핀 모드 설정
  pinMode(LED_BUILTIN, OUTPUT); 
  Serial.begin(115200);                 
}


void loop() { 
 digitalWrite(9, HIGH);          // 릴레이 켜기
 digitalWrite(LED_BUILTIN, HIGH); // LED ON
 Serial.println("릴레이ON");
 delay(3000);                     // 3초 후
 digitalWrite(9, LOW);           // 릴레이 끄기
 digitalWrite(LED_BUILTIN, LOW);       // LED OFF
 Serial.println("릴레이OFF");
 delay(3000);                     // 3초 후
    }
//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
