void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Brightness control with knob");
  delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a, b ;
  a = analogRead(A14);
  Serial.print("A= ");
  Serial.print(a);
  Serial.println(" ADC_Step_Size");
  b = map(a, 0, 1023, 0, 255);
  analogWrite(6,b);
  Serial.print("B= ");
  Serial.print(b);
  Serial.println(" Step_Size");
  delay(2000);
}