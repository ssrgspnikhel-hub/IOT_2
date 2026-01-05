// 

void setup() {
 
Serial.begin(9600);    //   Screen Baud rate
Serial3.begin(115200);  //   Micro to ESP Comm. Baud Rate

sendtoESP("AT+RST",  2000);
sendtoESP("AT+CWMODE=1",  1000);
sendtoESP("AT+CWJAP=\"GSP-STAFF\",\"55r@G5b#\"" , 5000);
sendtoESP("AT+CIFSR",2000);


sendtoESP("AT+CIPMUX=1", 2000);
sendtoESP("AT+CIPSERVER=1,80",2000);// Server open

sendtoESP("AT+CIPCLOSE=0", 1000);
sendtoESP("AT+CIPSERVER=0", 3000); // Server close command

}

void loop() {
 int connectionsID;
int  a = random(10-500);
String data = String("Random Number is = " + String(a));
if(Serial3.available()){

  if(Serial3.find("+IPD,")){
    connectionsID=Serial3.read()-48;  // 0 = to ASCII VALUE 48
    String send = "AT+CIPSEND="+String(connectionsID) + data.length();
    sendtoESP(send, 2000)
//sendtoESP("AT+CIPSEND= String(connectinID),"+String(num.length()),3000);

  
}

}


void sendtoESP(String cmd,int delaytime){
  Serial3.println(cmd);
  delay(delaytime);
  while(Serial3.available()){
    Serial.write(Serial3.read());//   response from ESP
  }
}