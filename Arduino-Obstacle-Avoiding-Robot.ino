//This program was made by Ben Menashe
//Arduino Arduino-Obstacle-Avoiding-Robot
#include <Servo.h>
#include <NewPing.h>
//Motors pins
int LeftWheelsForward = 11; 
int LeftWheelsBackward = 10; 
int RightWheelsBackward = 9; 
int RightWheelsForward = 8; 
int LeftLed = 7;
int RightLed = 6;
int pos = 0;
//sensor pins
#define trig_pin A1 //analog input 5
#define echo_pin A0 //analog input 4
#define maximum_distance 200
int distance = 100;
NewPing sonar(trig_pin, echo_pin, 200); //Ultrasonic function
Servo servo_motor; //servo


void setup() {

  pinMode (RightWheelsForward, OUTPUT);
  pinMode (RightWheelsBackward, OUTPUT);
  pinMode (LeftWheelsForward, OUTPUT);
  pinMode (LeftWheelsBackward, OUTPUT);
  servo_motor.attach(12); //Servo Pin
  servo_motor.write(160);
  delay(2000);

}


void loop() {

  int distance = 0;
  Serial.println(sonar.ping_cm());
  delay(30);
  Serial.begin(9600);
  delay(50);
  distance = sonar.ping_cm();
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if(distance <= 20){
    CarStop();
    delay(300);
    CarBackward();
    delay(300);
    CarStop();
    delay(200);
    servo_motor.write(60);
    delay(500);
    distanceLeft = sonar.ping_cm();
    delay(100);
    servo_motor.write(160);
    CarStop();
    delay(200);
    if(distanceLeft <= distance){
      delay(200);
      CarStop();
      delay(200);
      TurnRight();
      delay(300);
      CarStop();
      delay(300);
    }
    else{
      TurnLeft();
      delay(300);
      CarStop();
      delay(300);
    }
  }
  else{
    CarForward();
  }
}


//Functions for moving the car

int CarForward(){ //Car goes straight
  digitalWrite(RightWheelsForward, HIGH);
  digitalWrite(RightWheelsBackward, LOW);
  digitalWrite(LeftWheelsForward, HIGH);
  digitalWrite(LeftWheelsBackward, LOW);  
}
int CarStop(){ //Car stops
  digitalWrite(RightWheelsForward, LOW);
  digitalWrite(RightWheelsBackward, LOW);
  digitalWrite(LeftWheelsForward, LOW);
  digitalWrite(LeftWheelsBackward, LOW);
}
int CarBackward(){ //Car goes back
  digitalWrite(RightWheelsForward, LOW);
  digitalWrite(RightWheelsBackward, HIGH);
  digitalWrite(LeftWheelsForward, LOW);
  digitalWrite(LeftWheelsBackward, HIGH);
}
int TurnRight(){ //Car goes Right
  digitalWrite(RightWheelsForward, LOW);
  digitalWrite(RightWheelsBackward, HIGH);
  digitalWrite(LeftWheelsForward, HIGH);
  digitalWrite(LeftWheelsBackward, LOW);
}
int TurnLeft(){ //Car goes Right
  digitalWrite(RightWheelsForward, HIGH);
  digitalWrite(RightWheelsBackward, LOW);
  digitalWrite(LeftWheelsForward, LOW);
  digitalWrite(LeftWheelsBackward, HIGH);
}
