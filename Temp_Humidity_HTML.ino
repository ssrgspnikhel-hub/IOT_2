const int temp_Pin=A6;
const int HumPin = A7;


void setup() 
{
  Serial.begin(9600); 
  Serial3.begin(115200);

  sendtoESP("AT+RST",  2000);
  sendtoESP("AT+CWMODE=1",  1000);
  sendtoESP("AT+CWJAP=\"GSP-STAFF\",\"55r@G5b#\"" , 10000);
  sendtoESP("AT+CIFSR",2000);

  sendtoESP("AT+CIPMUX=1", 2000);
  sendtoESP("AT+CIPSERVER=1,80",6000);// Server open
}

void loop() {
 float tempearture = temp();
 float humidity = Hum();
 

  
 String data = "HTTP/1.1 200 OK \r\n"
        "Content-Type: text/html\r\n"
        "Connection:  close\r\n\r\n"
        "<!DOCTYPE html>"
        "<html>"
        "<head>"

        "<meta http-equiv='refresh' content ='15'>"  
      
        "<title>GSP_HUMIDITY_AND_TEPPERATURES</title>"

        "<style>"
        "body{font-family:Arial;text-align:center;margin-top:50px;}"
        "h1{font-size:32px;color:#EB3B6B;}" 
        "p{font-size:24px;color:#1547EB;}"
       
        "</style>" 
        "</head>"
        "<body>"
        "<h1> Iot Lab Data</h1>"
        "<p> Tempearture  <b>"+String(tempearture)+"</b></p>"
        "<p> Humidity  <b>"+String(humidity)+"%,RH"+"</b></p>"
        

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


      
      String send = "AT+CIPSEND="+ String(connectionID)+","+String(data.length());
    

      sendtoESP(send, 2000);
      sendtoESP(data, 1000);
      sendtoESP("AT+CIPCLOSE="+String(connectionID) , 1000 );


    }

  }





//  Serial.println("********************************TEPERATUREs************************************ ") ;
//  Serial.print("  Teperature : ") ;
//  Serial.print(tempearture);
//  Serial.println("°C");

//  Serial.println("***************************HUMIDITY***************************") ;
//  Serial.print("   Humidity : ") ;
//  Serial.print(humidity);
//  Serial.println("%Rh");
}

float temp ()
{
  float sumTemp = 0;
  for(int i=0;i<=10;i++)
  { 
      int t = analogRead(temp_Pin);
      float Temp_Volage = (t * (5.0/1023));
      float temp = (((2.0*Temp_Volage) - 0.5)*100);
      sumTemp += temp;
      delay(50);
  }

  return (sumTemp/10);
}

float Hum ()
{
   float sumHum = 0;
  for(int i=0;i<=10;i++)
  { 
      int h = analogRead(HumPin);
      float Hum_Volage =(h * (5.0/1023));
      float Humi = (((2.0*Hum_Volage / 5.0)-0.16)/0.0062);
      sumHum += Humi;
      delay(50);
  }

  return (sumHum/10);
}


void sendtoESP(String cmd,int delaytime){
  Serial3.println(cmd);
  delay(delaytime);
  while(Serial3.available()){

    Serial.write(Serial3.read());//   response from ESP

  }
}
