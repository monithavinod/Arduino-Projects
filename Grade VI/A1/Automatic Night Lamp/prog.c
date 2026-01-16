// Pin definitions
#define LDR_PIN A0
#define LED_PIN 9

int ldrValue;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(LDR_PIN);
  Serial.println(ldrValue);

  // Adjust threshold according to light condition
  if (ldrValue < 400) {
    // Dark condition
    digitalWrite(LED_PIN, HIGH);
  } else {
    // Bright condition
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);
}
