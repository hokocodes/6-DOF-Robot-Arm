#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  100 // Minimum pulse length count (out of 4096)
#define SERVOMAX  500 // Maximum pulse length count (out of 4096)
#define SERVO_FREQ 50  // Analog servos run at ~50 Hz updates

uint8_t wristServo = 0;  // Assuming the wrist is connected to channel 2

void setup() {
  Serial.begin(9600);
  Serial.println("Waving motion for wrist!");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}

void loop() {
  pwm.setPWM(1, 0, SERVOMAX);
  delay(1000);
  Serial.println("Set arm position");

  pwm.setPWM(3, 0, 430);
  delay(1000);
  Serial.println("Set WRIST JOINT");

  // GO UP TO PUT SOMEWHERE ELSE
  for (uint16_t i = 370; i < 450; i++){
    pwm.setPWM(2, 0, i);
    delay(25);
  }
  delay(1000);
  Serial.println("move elbow up");
//twist base
  for (uint16_t i = SERVOMAX; i > 300; i--){
    pwm.setPWM(0, 0, i);
    delay(25);
  }
  delay(1000);
  Serial.println("Twisted base.");




// GO DOWN TO PICK UP OBJECT
  for (uint16_t i = 450; i > 320; i--){
    pwm.setPWM(2, 0, i);
    delay(25);
  }
  delay(1000);
  Serial.println("Twisted elbow 1st time");

// TWIST WRIST
  pwm.setPWM(4, 0, 300);
  delay(1000);
  Serial.println("Twisted wrist");

// gripper
// OPEN GRIPPER TO DROP OBJECT
  for (uint16_t i = 220; i > 115; i--){
    pwm.setPWM(5, 0, i);
    delay(25);
  }
  delay(2000);
  Serial.println("Open gripper to drop object 1st time");

// CLOSE GRIPPER TO PICK UP OBJECT

  for (uint16_t i = 115; i < 220; i++){
    pwm.setPWM(5, 0, i);
    delay(25);
  }
  delay(1000);
  Serial.println("Close gripper");
// end gripper


// GO UP TO PUT SOMEWHERE ELSE
  for (uint16_t i = 320; i < 470; i++){
    pwm.setPWM(2, 0, i);
    delay(25);
  }
  delay(1000);
  Serial.println("move elbow up");

  

// TWIST SHOUDLER BASE TO MOVE OBJECT TO THE LEFT OR RIGHT
  for (uint16_t i = 300; i < SERVOMAX; i++){
    pwm.setPWM(0, 0, i);
    delay(25);
  }
  delay(1000);
  Serial.println("Twist base 2nd time");


// GO DOWN TO PICK UP OBJECT
  for (uint16_t i = 470; i > 320; i--){
    pwm.setPWM(2, 0, i);
    delay(25);
  }
  delay(1000);
  Serial.println("Twisted elbow 2nd time");


// gripper
// OPEN GRIPPER TO DROP OBJECT
  for (uint16_t i = 220; i > 115; i--){
    pwm.setPWM(5, 0, i);
    delay(25);
  }
  delay(1000);
  Serial.println("Open gripper to drop object 2nd time");

  // CLOSE GRIPPER TO PICK UP OBJECT
  for (uint16_t i = 115; i < 220; i++){
    pwm.setPWM(5, 0, i);
    delay(25);
  }
  delay(1000);
  Serial.println("Close gripper 2nd time");

// end gripper



}
