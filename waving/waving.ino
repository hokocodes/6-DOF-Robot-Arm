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

  Serial.println("Moving to minimum position (0°)...");
  pwm.setPWM(1, 0, 400);  // Move to 0°
  delay(1000);  // Wait for 1 second

  pwm.setPWM(2, 0, 430);  // Move to 0°
  delay(1000);  // Wait for 1 second

  pwm.setPWM(3, 0, 450);
  delay(1000);


  pwm.setPWM(5, 0, 115);
  delay(1000);

  pwm.setPWM(5, 0, 220);
  delay(1000);

  for (uint16_t i = 320; i < 360; i++){
    pwm.setPWM(1, 0, i);
    delay(30);
  }
    
  delay(1000);

  for (uint16_t i = 360; i < 320; i--){
    pwm.setPWM(1, 0, i);
    delay(30);
  }

}
