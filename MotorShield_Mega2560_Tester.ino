
// MotorShield A Channel
const int A_DIRECTION = 12;
const int A_PWM = 3; 
const int A_BRAKE = 9;

// MotorShield B Channel
const int B_DIRECTION = 11;
const int B_PWM = 11;
const int B_BRAKE = 8;

//MotorShield current sensing
const int SNS0 = A0;
const int SNS1 = A1;


void setup() {
  
  Serial.begin(9600);
  Serial.println("Starting serial communications...");
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Direction Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  
  //Setup Channel B
  pinMode(11, OUTPUT); //Initiates Direction Channel B pin
  pinMode(8, OUTPUT); //Initiates Brake Channel B pin
  
  delay(2000);
  
}

void loop(){

  disengageBrake();
  forward();
  delay(3000);
  engageBrake();
  delay(2000);
  disengageBrake();
  backward();
  delay(3000);
  engageBrake();
  delay(2000);
  disengageBrake();
  right();
  delay(3000);
  engageBrake();
  delay(2000);
  disengageBrake();
  left();
  delay(3000);
  engageBrake();
  delay(2000);
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


