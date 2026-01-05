int led=0;


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(6,OUTPUT);
pinMode(12,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  
int button_status;
button_status=digitalRead(12);
Serial.print("Button Status: ");
Serial.println(button_status);

if(button_status ==0)
{
  led=~led;
  digitalWrite(6,led);

}
delay(1000);
}
