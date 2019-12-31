#include <SoftwareSerial.h>
 
SoftwareSerial Bluetooth(3, 2); // RX, TX
 
int leftMotorIn = 8;
int leftMotorOut = 11;
int rightMotorIn = 12;
int rightMotorOut = 13;
int leftMotorEN = 9;
int rightMotorEN = 10;
 
int Data; // the data received
int lastData;
 
void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...");
  Bluetooth.println("Waiting for command");
  pinMode(leftMotorIn,OUTPUT);
  pinMode(leftMotorOut,OUTPUT);
  pinMode(rightMotorIn,OUTPUT);
  pinMode(rightMotorOut,OUTPUT);
  pinMode(leftMotorEN,OUTPUT);
  pinMode(rightMotorEN,OUTPUT);  
 
}
 
void loop() {
  if (Bluetooth.available()){ //wait for data received
    Data=Bluetooth.read();
    
    if(Data=='f'){  
      moveForward();
      Serial.println("Move forward!");
      Bluetooth.println("Move forward!");
    }
    else if(Data=='l'){  
      moveLeft();
      Serial.println("Move forward!");
      Bluetooth.println("Move forward!");
    }
    else if(Data=='r'){  
      moveRight();
      Serial.println("Move forward!");
      Bluetooth.println("Move forward!");
    }
    else if(Data=='b'){
       moveBackward();
       Serial.println("Move backward!");
       Bluetooth.println("Move backward!");
    }
    else if(Data=='s'){
       stopMoving();
       Serial.println("Stopped!");
       Bluetooth.println("Stopped!");
    }
    else{;}
  }
delay(100);
}
 
void moveForward(){
  analogWrite(leftMotorEN, 100);
  analogWrite(rightMotorEN, 100);
  digitalWrite(leftMotorIn, HIGH);
  digitalWrite(leftMotorOut, LOW);
  digitalWrite(rightMotorIn, HIGH);
  digitalWrite(rightMotorOut, LOW);
}
 
void moveBackward(){
  analogWrite(leftMotorEN, 100);
  analogWrite(rightMotorEN, 100);
  digitalWrite(leftMotorIn, LOW);
  digitalWrite(leftMotorOut, HIGH);
  digitalWrite(rightMotorIn, LOW);
  digitalWrite(rightMotorOut, HIGH);
}
 
void moveLeft(){
  analogWrite(leftMotorEN, 50);
  analogWrite(rightMotorEN, 10);
  digitalWrite(leftMotorIn, HIGH);
  digitalWrite(leftMotorOut, LOW);
  digitalWrite(rightMotorIn, LOW);
  digitalWrite(rightMotorOut, HIGH);
  delay(500);
}
 
void moveRight(){
  analogWrite(leftMotorEN, 10);
  analogWrite(rightMotorEN, 50);
  digitalWrite(leftMotorIn, LOW);
  digitalWrite(leftMotorOut, HIGH);
  digitalWrite(rightMotorIn, HIGH);
  digitalWrite(rightMotorOut, LOW);
  delay(500);
}
 
void stopMoving(){
  analogWrite(leftMotorEN, 0);
  analogWrite(rightMotorEN, 0);
  digitalWrite(leftMotorIn, HIGH);
  digitalWrite(leftMotorOut, HIGH);
  digitalWrite(rightMotorIn, HIGH);
  digitalWrite(rightMotorOut, HIGH);
}
