#include <SPI.h>

// MotorShield A Channel
const int A_DIRECTION = 53;
const int A_PWM = 51; 
const int A_BRAKE = 48;

// MotorShield B Channel
const int B_DIRECTION = 52;
const int B_PWM = 50;
const int B_BRAKE = 49;

//MotorShield current sensing
const int SNS0 = A0;
const int SNS1 = A1;


void setup() {
  
  Serial.begin(9600);
  Serial.println("Starting serial communications...");
  
  //Setup Channel A
  pinMode(53, OUTPUT); //Initiates Direction Channel A pin
  pinMode(48, OUTPUT); //Initiates Brake Channel A pin
  
  //Setup Channel B
  pinMode(52, OUTPUT); //Initiates Direction Channel B pin
  pinMode(49, OUTPUT); //Initiates Brake Channel B pin
  
  delay(2000);
  
}

void loop(){

}

/////////////////////????////
//  drive motor functions  //
/////////////////////////////


void engageBrake() {
  digitalWrite(A_BRAKE, HIGH);  //Engage the Brake for Channel A
  digitalWrite(B_BRAKE, HIGH);  //Engage the Brake for Channel B
}

void disengageBrake() {
  digitalWrite(A_BRAKE, LOW);  //Engage the Brake for Channel A
  digitalWrite(B_BRAKE, LOW);  //Engage the Brake for Channel B
}


void forward() {
 
  //Motor A forward @ full speed
  digitalWrite(A_DIRECTION, HIGH); //Establishes forward direction of Channel A
  digitalWrite(A_BRAKE, LOW);   //Disengage the Brake for Channel A
  analogWrite(A_PWM, 128);   //Spins the motor on Channel A at full speed

  //Motor B backward @ full speed
  digitalWrite(B_DIRECTION, LOW);  //Establishes forward direction of Channel B
  digitalWrite(B_BRAKE, LOW);   //Disengage the Brake for Channel B
  analogWrite(B_PWM, 255);    //Spins the motor on Channel B at full speed
 
}

void backward() {
 
  //Motor A forward @ full speed
  digitalWrite(A_DIRECTION, LOW); //Establishes backward direction of Channel A
  digitalWrite(A_BRAKE, LOW);   //Disengage the Brake for Channel A
  analogWrite(A_PWM, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ full speed
  digitalWrite(B_DIRECTION, HIGH);  //Establishes backward direction of Channel B
  digitalWrite(B_BRAKE, LOW);   //Disengage the Brake for Channel B
  analogWrite(B_PWM, 255);    //Spins the motor on Channel B at full speed
 
}

void left() {
 
  //Motor A forward @ full speed
  digitalWrite(A_DIRECTION, HIGH); //Establishes forward direction of Channel A
  digitalWrite(A_BRAKE, LOW);   //Disengage the Brake for Channel A
  analogWrite(A_PWM, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ half speed
  digitalWrite(B_DIRECTION, HIGH);  //Establishes backward direction of Channel B
  digitalWrite(B_BRAKE, LOW);   //Disengage the Brake for Channel B
  analogWrite(B_PWM, 128);    //Spins the motor on Channel B at half speed
 
}

void right() {
 
  //Motor A forward @ full speed
  digitalWrite(A_DIRECTION, LOW); //Establishes forward direction of Channel A
  digitalWrite(A_BRAKE, LOW);   //Disengage the Brake for Channel A
  analogWrite(A_PWM, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ half speed
  digitalWrite(B_DIRECTION, LOW);  //Establishes backward direction of Channel B
  digitalWrite(B_BRAKE, LOW);   //Disengage the Brake for Channel B
  analogWrite(B_PWM, 128);    //Spins the motor on Channel B at half speed
 
}

///////////////////////////////////////
//     Motor Consumption Function    //
///////////////////////////////////////

void MotorConsumption() {
  Serial.print("sensor 0: ");
  Serial.println(analogRead(SNS0));
  Serial.print("sensor 1: ");
  Serial.println(analogRead(SNS1));
  Serial.println("**************");
}


