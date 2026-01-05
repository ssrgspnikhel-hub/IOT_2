//ESP_Server_as-a_local_network_whithout_internet



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial3.begin(115200);
Serial.println("Enter AT Commands >>");
}

void loop() {
  // MULTIPUL  USER ACESESS IP DAL K DATA KO READ KR SKTE HAI 
while (Serial3.available() ) {
    char c = Serial3.read();
    Serial.write(c);
}

while (Serial.available()) {
    char c = Serial.read();
    Serial3.write(c);

    // COMMAND
   // AT+RST
    //AT+CWMODE=1
   // AT+CWJAP="GSP-STAFF","55r@G5b#"
   // AT+CIFSR 
   // AT+CIPMUX=1
   // AT+CIPSERVER=1,80
   // Wait 2 Second
   // open browser and tpye ip addrs
   // AT+CIPSEND=0,5 // 0 Number of Connections user , data length
   // >HELLO
   // AT+CIPCLOSE=0

}
}