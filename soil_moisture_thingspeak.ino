#include <Ticker.h>



#include <ESP8266WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

Ticker ticker;
unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

float soil_moisture;
float sm_percentage;
int pump = 2;  //pump is on GPIO 2
int pump_status;
boolean timer_reached;


void send_data()
{
  timer_reached =true;
}




void setup() {
  Serial.begin(115200);  // Initialize serial
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo native USB port only
   pinMode(pump, OUTPUT);
  }
  
  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
  timer_reached = false;
  ticker.attach(15,send_data );  
}



void loop() {

   // put your main code here, to run repeatedly:
soil_moisture = analogRead(A0);
sm_percentage = map(soil_moisture,0,1023,100,0);
if(sm_percentage<=30)
{
  digitalWrite(pump, LOW);
  Serial.println("soil is DRY");
  pump_status=1;
}
else if (30<sm_percentage<40)
 {
  digitalWrite(pump, LOW);
  Serial.print("soil moisture is optimum");
}

else if (sm_percentage >=40)
{
  digitalWrite(pump, HIGH);
  Serial.println("soil moisture is wet");
  pump_status=0;
}


Serial.print("soil Moisture  = ");
Serial.println(soil_moisture);
Serial.print("soil Moisture percentage % = ");
Serial.print(sm_percentage);
Serial.println("%");

  
  if(timer_reached)
  {
  // set the fields with the values
  ThingSpeak.setField(1, sm_percentage);
  ThingSpeak.setField(2, pump_status);


  
  // write to the ThingSpeak channel
  
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
    timer_reached =false;
  }
  
  delay(15000); // Wait 20 seconds to update the channel again
}
