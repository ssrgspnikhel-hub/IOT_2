void setup() {
Serial.begin(9600);    //   Screen Baud rate
Serial3.begin(115200);  //   Micro to ESP Comm. Baud Rate

sendtoESP("AT+RST",  2000);
sendtoESP("AT+CWMODE=1",  1000);
sendtoESP("AT+CWJAP=\"GSP-STAFF\",\"55r@G5b#\"" , 10000);
sendtoESP("AT+CIFSR",2000);

sendtoESP("AT+CIPMUX=1", 2000);
sendtoESP("AT+CIPSERVER=1,80",6000);// Server open
}

void loop() {
  int a = random(100,500);
  String data = "HTTP/1.1 200 OK \r\n"
        "Content-Type: text/html\r\n"
        "Connection:  close\r\n\r\n"
        "<!DOCTYPE html>"
        "<html>"
        "<head>"

        "<meta http-equiv='refresh' content ='15'>"  
      
        "<title>GSP_BPL</title>"

        "<style>"
        "body{font-family:Arial;text-align:center;margin-top:50px;}"
        "h1{font-size:32px;color:#EB3B6B;}" 
        "p{font-size:24px;color:#1547EB;}"
       
        "</style>" 
        "</head>"
        "<body>"
        "<h1> Iot Lab Data</h1>"
        "<p> Sensor Value <b>"+String(a)+"</b></p>"

        "<p> this page will auto refresh every 10 sec</p>"

        "</body>"
        "</html>";

 int connectionID;

 if(Serial3.available())
 {
   if(Serial3.find("+IPD,"))
   {
      connectionID = Serial3.read()+1;
      Serial.print(connectionID);
      Serial.print("Data String length = ");
      Serial.print(data.length());


      // sendToESP("AT+CIPSEND=0,5");
      String send = "AT+CIPSEND="+ String(connectionID)+","+String(data.length());
    

      sendtoESP(send, 2000);
      sendtoESP(data, 1000);
      sendtoESP("AT+CIPCLOSE="+String(connectionID) , 1000 );


    }

  }


}

void sendtoESP(String cmd,int delaytime){
  Serial3.println(cmd);
  delay(delaytime);
  while(Serial3.available()){

    Serial.write(Serial3.read());//   response from ESP

  }
}