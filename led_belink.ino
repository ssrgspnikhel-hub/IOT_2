
int led = 2;


void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(led, HIGH);
Serial.println("LED ON ");
delay(2000);
digitalWrite(led, LOW);
Serial.println("LED OFF ");
delay(3000);

//Serial.println(led);

//Serial.println(led);
}
