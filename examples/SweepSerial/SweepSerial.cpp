// SweepSerial
// by Valery Akhrymchuk <valeryakhrymchuk@gmail.com>

#include <Arduino.h>
#include <PWMServo.h>

PWMServo myservo;  // create servo object to control a servo

void setup() {
    myservo.attach(SERVO_PIN_A);  // attache servo on pin 9
    myservo.write(90);            // run servo to a central position

    Serial.begin(9600);           // init Serial
    Serial.println("Ready");
}

void loop() {
    if(Serial.available()) {
        int angle = (int) Serial.parseInt();  // read angle from Serial
        myservo.write(angle);                 // tell servo to go to position
        Serial.print("angle=");               // send back received angle
        Serial.println(angle);
    }
}
