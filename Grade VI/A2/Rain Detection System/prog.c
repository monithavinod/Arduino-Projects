#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// LCD I2C address (commonly 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo rainServo;

int rainPin = 7;
int buzzerPin = 6;
int servoPin = 9;

void setup() {
  pinMode(rainPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  rainServo.attach(servoPin);
  rainServo.write(0);   // Open position

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Rain Detection");
  delay(2000);
  lcd.clear();
}

void loop() {
  int rainStatus = digitalRead(rainPin);

  lcd.setCursor(0, 0);
  lcd.print("Status:       ");

  if (rainStatus == LOW) {   // Rain detected
    lcd.setCursor(0, 1);
    lcd.print("RAIN DETECTED ");
    digitalWrite(buzzerPin, HIGH);
    rainServo.write(90);     // Close roof/window
  } 
  else {
    lcd.setCursor(0, 1);
    lcd.print("NO RAIN       ");
    digitalWrite(buzzerPin, LOW);
    rainServo.write(0);      // Open roof/window
  }

  delay(500);
}
