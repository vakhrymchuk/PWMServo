// SweepMicroseconds
// by Valery Akhrymchuk <valeryakhrymchuk@gmail.com>

#include <Arduino.h>
#include <PWMServo.h>

PWMServo myservo;  // create servo object to control a servo

void setup() {
    myservo.attach(SERVO_PIN_A);  // attaches the servo on pin 9 to the servo object
}

void loop() {
    for (int mcs = MIN_PULSE_WIDTH; mcs <= MAX_PULSE_WIDTH; mcs++) {
        myservo.writeMicroseconds(mcs);  // tell servo to go to position
        delay(1);                        // waits 1ms for the servo to reach the position
    }

    for (int mcs = MAX_PULSE_WIDTH; mcs >= MIN_PULSE_WIDTH; mcs--) {
        myservo.writeMicroseconds(mcs);  // tell servo to go to position
        delay(1);                        // waits 1ms for the servo to reach the position
    }
}
