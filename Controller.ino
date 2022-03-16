#define joyX A0
#define joyY A1
#include <SoftwareSerial.h>

void Analog(int xValue, int yValue);


SoftwareSerial mySerial(2, 9);
int input1 = 0;
int input2 = 0;
int switch_pin = 12;
int buttonPin = 3;     // the number of the pushbutton pin

int state = 0;
int buttonState = 0;         // variable for reading the pushbutton status

String d = "";

void setup() {
  pinMode(switch_pin, INPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
  /*while (!Serial) {
    ; 
  {*/
  Serial.println("Hello World!");
  mySerial.begin(9600);
}

 
void loop() {
  buttonState = digitalRead(buttonPin);
  delay(50);
  if (buttonState == HIGH) {
    Serial.println("button high"); // dance
    input1 = 6;
    input2 = 0;   
    delay(2000); 
  } 
  else {
    Serial.println("button Low"); // nothing
  }
  
  if(digitalRead(switch_pin) == HIGH){
    state = 0;
  }
  else {
    state = 1;
  }
  
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);   
  mySerial.print(input1);
  mySerial.print(input2);
//  Serial.print("input      ");
//  Serial.print(input);
  //mySerial.print("  ");
  // mySerial.println(yValue);
  //delay(100);
if (state == 0) {
  Analog(xValue, yValue);
  Serial.print(d);
  Serial.print(xValue);
  Serial.print("  ");
  Serial.println(yValue);
  

}

if (state == 1) {
  Serial.println("one"); // follow
  input1 = 7;
  input2 = 0;
  delay(1000);
  }
  mySerial.print(input1);
  mySerial.print(input2);
  delay(200);
}

void Analog(int xValue, int yValue) {
  
  if (xValue >= 540) {
    if (yValue > 200 and yValue < 800) {
      input1 = 1;
      input2 = 0;
      d = "Forward";
    }
    else if (yValue <= 200) {
      input1 = 1;
      input2 = 7;
      d = "ForwardL";
      }
    else if (yValue >= 800) {
      input1 = 1;
      input2 = 8;
      d = "ForwardR";
      }
  }

  
  if (xValue <= 480) {
    if (yValue > 200 and yValue < 800) {
      input1 = 2;
      input2 = 0;
      d = "Backward";
      }

    else if (yValue <= 200) {
      input1 = 2;
      input2 = 8;
      d = "BackwardL";
      }
    else if (yValue >= 800){
      input1 = 2;
      input2 = 9;
      d = "BackwardR";
      }
  }
  
  if (xValue > 480 and xValue < 540 and yValue > 480 and yValue < 540){
    input1 = 3;
    input2 = 0;
    d = "Stop";
    }
    
  if (yValue >= 540) {
    if (xValue > 200 and xValue < 800){
      input1 = 4; 
      input2 = 0;
      d = "Right";
    }
  }
  
  if (yValue <= 480) {
    if (xValue > 200 and xValue < 800){
      input1 = 5; 
      input2 = 0;
      d = "Left";
    }
  }
}
