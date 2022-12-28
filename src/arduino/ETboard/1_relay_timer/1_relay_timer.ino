/******************************************************************************************
 * FileName     : 1. relay_ONOFF
 * Description  : 릴레이와 이티보드를 사용하여 ON,OFF제어 해보기
 * Author       : 윤승열
 * Created Date : 2022.10.19
 * Reference    : 보드매니저에서 이티보드로 설정한다.
 * Modified     : 
******************************************************************************************/

void setup() {
  pinMode(D9, OUTPUT);            // 핀 모드 설정
  pinMode(D2, OUTPUT);            // 핀 모드 설정
  Serial.begin(115200);                 
}


void loop() { 
 digitalWrite(D9, HIGH);          // 릴레이 켜기
 digitalWrite(D2, HIGH);          // LED ON
 Serial.println("릴레이ON");
 delay(3000);                     // 3초 후
 digitalWrite(D9, LOW);           // 릴레이 끄기
 digitalWrite(D2, LOW);           // LED OFF
 Serial.println("릴레이OFF");
 delay(3000);                     // 3초 후
 }
 
//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
