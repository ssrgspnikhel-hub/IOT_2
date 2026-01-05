void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // Serial moniter
Serial3.begin(115200); // ESP
Serial.println("For ESP-01-AT Communications");
Serial.println("type AT Command and press Enter >> ");
delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial3.available()>0)
{
    // agar ESP availval nhi hua to 0 retun hoga nhi to 1 means is available
    char data = Serial3.read(); // incoming data
    Serial.write(data);
}
// send AT command to ESP 0/1

if(Serial.available())
{
   String command = Serial.readStringUntil('\n');
   command.trim(); // unwantet charcter Remove 

   if(command.length()>0)
 {
   Serial.print(">>");
   Serial.println(command);
   Serial3.println(command);

  }


}


}
