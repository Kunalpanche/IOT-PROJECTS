#include<Servo.h>
Servo my_servo;
char incoming_data ;
String data;
void setup() {
 Serial.begin(9600);
 my_servo.attach(8);
 my_servo.write(0);

}

void loop() {
  
 while(Serial.available()>0) 
 {
  delay(1);
  String data = Serial.readString();
  Serial.println(data);

  if((data=="ON")||(data=="Lock")||(data=="LOCK")||(data=="LOCK ")||(data=="Lock ")||(data=="lock ")||(data=="lock"))//Change this line According to your need
  {
    Serial.println("door close");
    my_servo.write(90);
    delay(100);//change delay accroding to your need
//    my_servo.write(180);//if you want to close the lock automatically then uncomment this line and also adjust delay 
   
  }
  else if((data=="OFF")||(data=="Unlock")||(data=="UNLOCK")||(data=="UnLock")||(data=="unlock")||(data=="lock ")||(data=="Unlock ")||(data=="UNLOCK ")||(data=="UnLock "))//Change this line According to your need
  
  {
    Serial.println("door open");
    my_servo.write(0);
    delay(100);
 
  }
  
 
 }
 data="";
}
