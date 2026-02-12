int trig = 21;
int echo = 20;
float time, cm, inches;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial3.begin(115200);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
sendtoESP("AT+RST",  2000);
sendtoESP("AT+CWMODE=1", 1000);
sendtoESP("AT+CWJAP=\"GSP-STAFF\",\"55r@G5b#\"", 8000);
sendtoESP("AT+CIFSR" ,2000);
sendtoESP("AT+CIPMUX=1", 5000);
sendtoESP("AT+CIPSERVER=1,80" , 5000);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig, LOW);
delayMicroseconds(5);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

time = pulseIn(echo, HIGH);
 cm = 0.0343* (time/2);  // distance in cm speed is 0.0343 cm/usec
 inches = cm/2.54;


 /*Serial.println("*******************");
 Serial.print("Distance in cm:");
 Serial.print(cm);
 Serial.println("cm");
 
 Serial.print("Distance in Inches:");
 Serial.print(inches);
 Serial.println("in");

 Serial.println("***********************");
 delay(1000);*/

 String data = "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n\r\n"
        "<!DOCTYPE html>"
        "<html>"
        "<head>"
        "<meta http-equiv='refresh' content= '15'>"
        "<title>GSP BHOPAL</title>"
        "<style>"
        "body{font-family:Times New Roman;text-align:center;margin-top:50px;}"
        "h1{font-size:32px;color:#1D03FF}"
        "p{font-size:24px;color:#C90202}"
        "p1{font-size:20px;color:#0795E8}"
        "p2{font-size:20px;color:#00A80E}"
        "</style>"
        "</head>"
        "<body>"
        "<h1> IoT Lab Data</h1>"
        "<p> cm =<b>"+String(cm)+"<b> cm</p>"
        "<p1> inches =<b>"+String(inches)+"inch<b></p>"
        "<p2> This page will auto refresh every 15 sec</p1>"
        "</body>"
        "</html>";
int connectionID;
if (Serial3.available()) 
{
  if (Serial3.find("+IPD,")) 
  {
    connectionID = Serial3.read()-48;
    Serial.print("connection ID: ");
    Serial.println(connectionID);
    Serial.print("Data String length =");
    Serial.println(data.length());

    String send = "AT+CIPSEND="+ String(connectionID) +","+ String(data.length())+"\r\n";
    
    sendtoESP(send, 2000);
    sendtoESP(data, 1000);
    sendtoESP("AT+CIPCLOSE="+ String(connectionID), 1000);
  }
}
}








void sendtoESP(String cmd, int delayTime)
{
  Serial3.println(cmd);
  delay(delayTime); 
  while(Serial3.available())
  {
    Serial.write(Serial3.read()) ;  // responds frome ESP
  }
}