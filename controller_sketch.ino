#include <SoftwareSerial.h>
 
SoftwareSerial Bluetooth(13, 12); // RX, TX
 
#define up_button  8
#define down_button A1
#define left_button 9
#define right_button  12
 
#define stick_button  A0
#define level_stick A3
#define vertical_stick  A2
 
void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...");
  Bluetooth.println("Waiting for command");
  
  pinMode (left_button, INPUT);
  pinMode (right_button, INPUT);
  pinMode (up_button, INPUT);
  pinMode (down_button, INPUT);
 
  pinMode (stick_button  , INPUT);
  pinMode (level_stick   , INPUT);
  pinMode (vertical_stick, INPUT);
}
 
void loop() {
  int left_state = digitalRead (left_button);
  int right_state = digitalRead (right_button);
  int up_state = digitalRead (up_button);
  int down_state = digitalRead (down_button);
  int stick_state = digitalRead (stick_button);
  int level_value = analogRead (level_stick);
  int vertical_value = analogRead (vertical_stick);
  if(level_value > 800){
    Bluetooth.println("l");
    Serial.println("l");
  }else if(level_value == 0){
    Bluetooth.println("r");
    Serial.println("r");
  }else if(vertical_value > 800){
    Bluetooth.println("b");
    Serial.println("b");
  }else if(vertical_value == 0){
    Bluetooth.println("f");
    Serial.println("f");
  }else{
    Bluetooth.println("s");
    Serial.println("s");
  }
  delay (500);
}
