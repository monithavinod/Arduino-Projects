Potentiometer Control:
#include <Servo.h>

Servo fingerServo;

int potPin = A0;
int servoPin = 9;
int potValue;
int angle;

void setup() {
  fingerServo.attach(servoPin);
}

void loop() {
  potValue = analogRead(potPin);

  angle = map(potValue, 0, 1023, 0, 180);

  fingerServo.write(angle);
  delay(15);
}


Push button Control:
#include <Servo.h>

Servo fingerServo;
int buttonPin = 2;
int servoPin = 9;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  fingerServo.attach(servoPin);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    fingerServo.write(90);   // Finger closed
  } else {
    fingerServo.write(0);    // Finger open
  }
}

