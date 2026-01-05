const int temp_Pin=A6;
const int HumPin = A7;


void setup() {
Serial.begin(9600); 
Serial3.begin(115200);


}

void loop() {
 float tempearture = temp();
 float humidity = Hum();
 

 Serial.println("********************************TEPERATUREs************************************ ") ;
 Serial.print("  Teperature : ") ;
 Serial.print(tempearture);
 Serial.println("°C");

 Serial.println("***************************HUMIDITY***************************") ;
 Serial.print("   Humidity : ") ;
 Serial.print(humidity);
 Serial.println("%Rh");
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
