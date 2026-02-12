float soil_moisture;
float sm_percentage;
int pump = 2;  //pump is on GPIO 2


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(pump, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
soil_moisture = analogRead(A0);
sm_percentage = map(soil_moisture,0,1023,100,0);
if(sm_percentage<=30)
{
  digitalWrite(pump, LOW);
  Serial.println("soil is DRY");
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
}


Serial.print("soil Moisture  = ");
Serial.println(soil_moisture);
Serial.print("soil Moisture percentage % = ");
Serial.print(sm_percentage);
Serial.println("%");
delay(2000);
}
