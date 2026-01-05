void setup() {
  // put your setup code here, to run once:

//pinMode(6,OUTPUT);
Serial.begin(9600);
Serial.println("Reding Analog Voltage");
delay(1000);
}

void loop() {
// LED ON OFF Code
// digitalWrite(6,HIGH);
// Serial.println("LED_on");
// delay(500);
// digitalWrite(6,LOW);
// Serial.println("LED_off");
// delay(500);

float a ,v;
a = analogRead(A14);
Serial.println(a);
v= (a*5/1023);
Serial.print("Voltage = ");
Serial.print(v);
delay(1000);

}
