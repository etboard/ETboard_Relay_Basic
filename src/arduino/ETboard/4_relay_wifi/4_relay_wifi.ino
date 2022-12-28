/******************************************************************************************
 * FileName     : 4. relay_WiFi
 * Description  : 이티보드를 이용하여 html페이지에서 버튼을 누르면 릴레이를 제어해 보기
 * Author       : 윤승열
 * Created Date : 2022.10.19
 * Reference    : ET보드(ESP32)는 2.4GHz WiFi만 지원함
 * Modified     :
******************************************************************************************/

// 이 라이브러리를 통해 Arduino 보드를 인터넷에 연결할 수 있습니다.
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

const char* ssid = "myiptime";                      // 와이파이 아이디
const char* password = "12341234";                  // 와이파이 비밀번호

WebServer server(80);                              // 서버에서 사용할 포트 설정

const int relay = D9;                              // 릴레이의 핀번호
const int led = D2;                                // 빨간 LED의 핀번호
char htmlPage[] = "<font size=16>Click <a href=\"/relay_on\"> On button </a> to turn On relay<br></font>"\
                  "<font size=16>Click <a href=\"/relay_off\"> Off button </a> to turn Off relay<br></font>";


void handleRoot() {                                // root(/)로 접속했을 때 처리하는 함수
  Serial.println("root call!");                    // 페이지로 접속했다고 시리얼로 알려줌
  server.send(200, "text/html", htmlPage); 
}


void handleD2On() {                                // relay_on로 접속했을 때 처리하는 함수
  Serial.println("relay On call!");                // 페이지로 접속했다고 시리얼로 알려줌
  digitalWrite(led, HIGH);
  digitalWrite(relay, HIGH);
  server.send(200, "text/html", htmlPage);
}


void handleD2Off() {                               // relay_off)로 접속했을 때 처리하는 함수
  Serial.println("relay Off call!");               // 페이지로 접속했다고 시리얼로 알려줌
  digitalWrite(led, LOW);
  digitalWrite(relay, LOW);
  server.send(200, "text/html", htmlPage);
}


void setup(void) {
  pinMode(led, OUTPUT);                           // LED를 출력상태로 설정
  pinMode(relay, OUTPUT);                   
  digitalWrite(led, LOW);                         // LED를 끈 상태로 설정
  digitalWrite(relay, LOW);                       // relay를 끈상태로 설정
  Serial.begin(115200);                           // 시리얼 통신속도 설정
  WiFi.mode(WIFI_STA);                            // 연결모드로 설정
  WiFi.begin(ssid, password);                     // WiFi에 접속을 시도
  Serial.println("");
  
  while (WiFi.status() != WL_CONNECTED) {        // 연결이 될 때까지 계속 대기
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());                // 연결이 됐다면 할당받은 아이피를 출력함

  server.on("/", handleRoot);                    // root(/)로 접속했을 때 처리하는 함수랑 연결
  server.on("/relay_on", handleD2On);            // relay_on로 접속했을 때 처리하는 함수와 연결
  server.on("/relay_off", handleD2Off);          // relay_off로 접속했을 때 처리하는 함수와 연결
 
  server.begin();                                // 서버 시작
  Serial.println("HTTP server started");
}


void loop(void) {
  server.handleClient();                         // 클라이언트의 접속을 받음
  delay(2);
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
