#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11



#define BLYNK_TEMPLATE_ID "TMPL31XRv7_nV"
#define BLYNK_TEMPLATE_NAME "LED CONTROLED"
#define BLYNK_AUTH_TOKEN "8IS8zdNOSvD83WaWY5CGf2MWj27TifiE"



#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "GSP-STUDENT";
char pass[] = "65@Ssr#b5";

BlynkTimer timer;
DHT dht(DHTPIN,DHTTYPE);

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if(pinValue ==0)
  {
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2, LOW);
  
  }
}

BLYNK_WRITE(V1)
{
  int pinValue1 = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue1 ==0 )
  {
    digitalWrite(16, HIGH);
  }
  else
  {
    digitalWrite(16, LOW);
  
  }
}





void sensor_data()
{
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if(isnan(t)||isnan(h))
  {
    Serial.println("Failed to read from sensor ");
  }
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  dht.begin();
  pinMode(2, OUTPUT);
  pinMode(16, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.c loud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, sensor_data);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
