// Gas Leakage Detection System using MQ-2 Sensor

int gasSensorPin = A0;
int buzzerPin = 8;
int gasValue = 0;
int threshold = 400;   // Adjust after testing

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue > threshold) {
    digitalWrite(buzzerPin, HIGH);   // Gas detected
  } else {
    digitalWrite(buzzerPin, LOW);    // Normal condition
  }

  delay(500);
}

