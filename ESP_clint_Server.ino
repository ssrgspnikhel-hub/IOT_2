void sendtoESP(String cmd,int delaytime){
  Serial3.println(cmd);
  delay(delaytime);
  while(Serial3.available()){
    Serial.write(Serial3.read());//   response from ESP
  }
}

void setup() {
 
Serial.begin(9600);
Serial3.begin(115200);// Microcontroller or ESP to Conversion
Serial.println("AT+Cmmond Begin........");

sendtoESP("AT", 1000);
sendtoESP("AT+RST", 2000);
sendtoESP("AT+CWMODE=1", 1000);
sendtoESP("AT+CWJAP=\"GSP-STAFF\",\"55r@G5b#\"", 5000); // WIFI CONNECTING TIME 
}

void loop() {
  int a = random(0,100);
  int b = random(200,500);


sendtoESP("AT+CIFSR", 2000);
sendtoESP("AT+CIPMUX=0", 2000);
sendtoESP("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80", 1000);

String url = "GET /update?api_key=H7A1WIDBCYWNBKQ6&field1=" + String(a) 
+"&field2=" + String(b) 
+ "HTTP/1.1\r\nHost: api.thingspeak.com\r\n\Connections: close\r\n\r\n";



int Len = url.length();
Serial.println((String(Len) + " hello "));


sendtoESP("AT+CIPSEND="+String(Len),2000);// 51 is String length data // maximum string length 26400

sendtoESP(url,5000);
//sendtoESP("AT+CIPCLOSE",2000);
//sendtoESP("AT+CIPCLOSE",2000);

delay(16000);// 





}
