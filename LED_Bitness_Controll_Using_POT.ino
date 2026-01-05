void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Britness control with nob");
//delay(100);  // optionsnaly
}

void loop() {
  // put your main code here, to run repeatedly:
int a,b,volt;
a=analogRead(A14);
volt=a*5/1023;
Serial.print("Voltage=");
Serial.print(volt);
Serial.println(" A");
b = map(a,0,1023,0,255);
analogWrite(6,b);
Serial.print("B step Size ");
Serial.println(b);
delay(1000);


}
