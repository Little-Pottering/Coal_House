#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

SoftwareSerial mySoftwareSerial(2, 5); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int sensor_pin = 16;
int led1 = 4;
int val;
int state = 0;
// ESP8266 connection to L298N motor controller
int enA = D5; // PWM for Motor A
int in1 = D7;  // Control Rotation of Motor A
int in2 = D6;  // Control Rotation of Motor A

int motor_speed = 300; 

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(sensor_pin, INPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
    
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.setTimeOut(400);
  myDFPlayer.volume(18);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);

}

void loop(){
  val = digitalRead(sensor_pin);
  if (val==LOW){
    //delay(4000); 
    digitalWrite(led1, HIGH);   
    //delay(4000);            
    myDFPlayer.play(1);
    delay(6000);
 {
  digitalWrite(in1, LOW); // Input1 LOW = move forward
  digitalWrite(in2, HIGH);  // Input2 HIGH = move forward
  
  {
    analogWrite(enA, motor_speed); // PWM output
    delay(4000);
    (val==1);
  }
}
    delay(5000);
    
  }
  else {
    (val==1);
    digitalWrite(in1, LOW); // stop motor
    digitalWrite(in2, LOW);  // stop motor
    delay(12000); 
    digitalWrite(led1, LOW); 
    myDFPlayer.disableLoopAll(); 

         
  }
}
