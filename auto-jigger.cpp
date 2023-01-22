// KB Auto Jigger
// Design by Kevin Beard
// Programmed by Kurtsley

#include <Arduino.h>
#include "Servo.h"

int led = 13;
int start_pos = 40; 
Servo myservo; 

void setup() {
  pinMode (9, OUTPUT);
  pinMode(led, OUTPUT);
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  myservo.write(start_pos);
}

void jig(int start_angle, int end_angle, int up_jig_speed, int down_jig_speed, int up_delay_time, int down_delay_time, int repeat) {
  int pos = start_angle;
  while (repeat > 0) {
    for (pos = start_angle; pos <= end_angle; pos += up_jig_speed) {
      myservo.write(pos);
      digitalWrite(led, HIGH);
      delay(up_delay_time);
    }
    for (pos = end_angle; pos >= start_angle; pos -= down_jig_speed) {
      myservo.write(pos);
      digitalWrite(led, LOW);
      delay(down_delay_time);
    }
    repeat--;
  }
}

void loop() {

  jig(40, 120, 50, 2, 10, 70, 1);
  delay(2000);
  jig(40, 70, 50, 2, 10, 30, 3);
  delay(5000);
  jig(40, 120, 50, 2, 10, 70, 1);
  delay(2000);
  jig(40, 70, 50, 2, 10, 30, 3);
  delay(5000);
  jig(40, 120, 50, 2, 10, 70, 1);
  delay(2000);
  jig(40, 70, 50, 2, 10, 30, 3);
  delay(5000);
  jig(40, 120, 50, 2, 10, 70, 1);
  jig(40, 100, 50, 2, 10, 60, 1);
  jig(40, 80, 50, 2, 10, 50, 1);
  jig(40, 70, 50, 2, 10, 30, 3);
  delay(5000);
  jig(40, 120, 50, 2, 10, 70, 1);
  jig(40, 100, 50, 2, 10, 60, 1);
  jig(40, 80, 50, 2, 10, 50, 1);
  jig(40, 70, 50, 2, 10, 30, 3);
  delay(5000);

}