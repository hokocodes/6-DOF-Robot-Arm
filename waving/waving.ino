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



  for (uint16_t i = 350; i < SERVOMAX; i++){
    pwm.setPWM(1, 0, i);
    delay(10);
  }
    
  delay(2000);

  for (uint16_t i = SERVOMAX; i > 350; i--){
    pwm.setPWM(1, 0, i);
    delay(10);
  }
  delay(2000);

}
