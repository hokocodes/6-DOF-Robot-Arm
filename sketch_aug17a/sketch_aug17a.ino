#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
// twelve servo objects can be created on most boards

int pos = 0;   // variable to store the servo position

void setup() {
  Serial.begin(115200);

  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  servo5.attach(12);
  servo6.attach(13);
    // attaches the servo on pin 9 to the servo object
  
}

Servo servo_arr[6] = {servo1, servo2, servo3, servo4, servo5, servo6};

void loop() {
  for (int i = 0; i < 6; i++) {
    Serial.println(i);
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo_arr[i].write(pos); 
      // servo_arr[0].write(pos);             // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo_arr[i].write(pos);   
      // servo_arr[0].write(pos);           // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
    
}