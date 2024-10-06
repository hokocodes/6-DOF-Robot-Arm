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
//twist base
  for (uint16_t i = SERVOMAX; i > 300; i--){
    pwm.setPWM(0, 0, i);
    delay(40);
  }
  delay(2000);

  // TWIST OUTER SHOULDER

  // for (uint16_t i = SERVOMAX; i < 300; i++){
  //   pwm.setPWM(1, 0, i);
  //   delay(40);
  // }
    
  // delay(2000);

  // for (uint16_t i = 300; i < SERVOMAX; i++){
  //   pwm.setPWM(1, 0, i);
  //   delay(40);
  // }
    
  // delay(2000);
    pwm.setPWM(1, 0, SERVOMAX);
    delay(2000);

// GO DOWN TO PICK UP OBJECT
  for (uint16_t i = SERVOMAX; i > 370; i--){
    pwm.setPWM(2, 0, i);
    delay(40);
  }
  delay(2000);

// TWIST WRIST
  pwm.setPWM(4, 0, 300);
  delay(2000);

// CLOSE GRIPPER TO PICK UP OBJECT

  for (uint16_t i = 115; i < 220; i++){
    pwm.setPWM(5, 0, i);
    delay(40);
  }
  delay(2000);
// END GRIPPER 

// TWIST SHOUDLER BASE TO MOVE OBJECT TO THE LEFT OR RIGHT
  for (uint16_t i = 300; i < SERVOMAX; i++){
    pwm.setPWM(0, 0, i);
    delay(40);
  }
  delay(2000);

// OPEN GRIPPER TO DROP OBJECT
  for (uint16_t i = 220; i > 115; i--){
    pwm.setPWM(5, 0, i);
    delay(40);
  }
  delay(2000);

// END GRIPPER 

// GO UP TO PUT SOMEWHERE ELSE
  for (uint16_t i = 370; i < SERVOMAX; i++){
    pwm.setPWM(2, 0, i);
    delay(40);
  }
  delay(2000);

}
