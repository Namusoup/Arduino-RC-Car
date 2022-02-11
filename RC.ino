#define A1 11  // Motor A pins
#define A2 9
#define B1 5 // Motor B pins
#define B2 6

#define trigPin 10 // ultrasound trigger pin
#define echoPin 12 // ultrasound echo pin
void forward();
void backward();
void Left();
void Right();
void ForwardL();
void ForwardR();
void BackwardL();
void BackwardR();
void Dance();
void Stop();
void Go();


#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

int incomingByte = 0; // for incoming serial data

void setup(){

  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  mySerial.begin(9600);

  Serial.println("select direction of movement");
  Serial.println("1.forward");
  Serial.println("2.backward");
  Serial.println("3.stop");
  Serial.println("4.Right");
  Serial.println("5.Left");


}
int  input1 = 0;
int input2 = 0;
long duration, distance;  

void loop() {

  digitalWrite(trigPin, LOW);                 // trigPin LOW
  delayMicroseconds(2);                    // 2 microseconds later
  digitalWrite(trigPin, HIGH);                // trigPin HIGH
  delayMicroseconds(10);                  // 10 microseconds later
  digitalWrite(trigPin, LOW);                // trigPin LOW
  duration = pulseIn(echoPin, HIGH);   // echoPin pulse value
distance = duration * 17 / 1000;

  // send data only when you receive data:
  if (mySerial.available()) { 
    input1 = mySerial.read()- 48;
    input2 = mySerial.read()- 48;

    Serial.print("input1:  ");
    Serial.print(input1);    
    Serial.print("   input2:  ");
    Serial.println(input2);
    //}

  if (distance <= 10){ //disttance back
  input1 = 2;
  input2 = 0;
  }
  //if (Serial.available() > 0) {
    // read the incoming byte:
    //incomingByte = Serial.read();
//    input = incomingByte - 48; //convert ASCII code of numbers to 1,2,3
    //Serial.println(input);*/
    

  switch (input1 + input2) { 
    case 1:         // if input=1 ....... motors turn forward
      forward();
      Serial.print("forward");
      break;
    case 2:         // if input=2 ....... motors turn backward
      backward();
      Serial.print("back");
      break;
    case 3:         // if input=1 ....... motors turn stop
      Stop();
      Serial.print("stop");
      break;
    case 4:
      Right();
      Serial.print("right");
      break;
    case 5:
      Left();
      Serial.print("left");
      break;
    case 6:
      Dance();
      Serial.print("dance");
      break; 
    case 7:
      Go();
      Serial.print("go");
      break;
    case 8:
      ForwardL();
      Serial.print("ForwardL");
      break;
    case 9:
      ForwardR();
      Serial.print("ForwardR");
      break;
    case 10:
      BackwardL();
      Serial.print("BackwardL");
      break;
    case 11: 
      BackwardR();
      Serial.print("BackwardR");
      break;
  }

  Serial.println();
  delay(10);
  input1=0;
}

}
//255
int a = 250;
int b = 255;

void forward() {          //function of forward 
  analogWrite(A1, a);
  analogWrite(A2, 0);
  analogWrite(B1, b);
  analogWrite(B2, 0);
}

void ForwardL(){
  analogWrite(A1, a - 100);
  analogWrite(A2, 0);
  analogWrite(B1, b);
  analogWrite(B2, 0);
  }

void ForwardR(){
  analogWrite(A1, a);
  analogWrite(A2, 0);
  analogWrite(B1, b - 100);
  analogWrite(B2, 0);
  }

void backward() {         //function of backward
  analogWrite(A1, 0);
  analogWrite(A2, a);
  analogWrite(B1, 0);
  analogWrite(B2, b);
}

void BackwardL(){
  analogWrite(A1, 0);
  analogWrite(A2, a);
  analogWrite(B1, 0);
  analogWrite(B2, b - 100);
  }

  void BackwardR(){
  analogWrite(A1, 0);
  analogWrite(A2, a - 100);
  analogWrite(B1, 0);
  analogWrite(B2, b);
  }

void Stop() {              //function of stop
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
}


void Right() {
  analogWrite(A1, a); //+15
  analogWrite(A2, 0);
  analogWrite(B1, 0);
  analogWrite(B2, b - 100);
  }

void Left(){
  analogWrite(A1, 0);
  analogWrite(A2, a-100);
  analogWrite(B1, b); //+15
  analogWrite(B2, 0);
  }

void Dance(){
  analogWrite(A1, 0);
  analogWrite(A2, 255);
  analogWrite(B1, 255);
  analogWrite(B2, 0);  
  delay(2000);
      analogWrite(A1, 255);
  analogWrite(A2, 0);
  analogWrite(B1, 0);
  analogWrite(B2, 255 );  
  delay(2000);
  }

void Go() {
  if (distance <= 30) {
    int rn = random(3);
    if (rn == 0) Right();
    else if (rn == 1) Left();
    else backward();
    }
else {    
  int r = random(3);
  if (r == 0) {
    forward();
    }
  if (r == 1) {
    Right();
    }
  if (r == 2) {
    Left();
    }
  if (r == 3) {
    Dance();
    }
    
    }
    if (distance <= 25){
    delay(1000);
    }
  }
