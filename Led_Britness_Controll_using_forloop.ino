void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 
 
 
 //{stp-step Britness up in dwon



// analogWrite(6,0);
// delay(1000);
// analogWrite(6,64);
// delay(1000);
// analogWrite(6,128);
// delay(1000);
// analogWrite(6,192);
// delay(1000);
// analogWrite(6,255);
// delay(1000);
// analogWrite(6,200);
// delay(1000);
//                                 }
 

 
 for(int a=0;a<255;a++){
  analogWrite(6,a);
  delay(10);
 }
 delay(100);
 for(int a=255;a>0;a--){
  analogWrite(6,a);
  delay(10);
 }
  delay(100);
}
