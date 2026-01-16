#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SOUND_SENSOR A0
#define GREEN_LED 2
#define YELLOW_LED 3
#define RED_LED 4
#define BUZZER 5

int soundValue;
int avgSound;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Noise Monitor");

  Serial.begin(9600);
}

void loop() {

  // 🔹 TAKE AVERAGE OF 10 READINGS
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(SOUND_SENSOR);
    delay(10);
  }
  avgSound = sum / 10;

  Serial.println(avgSound);
  lcd.setCursor(0, 1);

  // 🔹 DECISION LOGIC (STABLE)
  if (avgSound < 200) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
    lcd.print("LOW NOISE     ");
  }
  else if (avgSound >= 200 && avgSound < 450) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
    lcd.print("MEDIUM NOISE  ");
  }
  else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    lcd.print("HIGH NOISE!   ");
  }

  delay(500);   // HOLD output
}
