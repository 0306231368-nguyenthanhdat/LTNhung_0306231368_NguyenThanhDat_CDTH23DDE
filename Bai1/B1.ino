int ledPins[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  randomSeed(analogRead(A0));
}

void loop() {
  for (int i = 0; i < 10; i++) {
    int rand = random(0, 10);
    if (rand % 2 == 1) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
  delay(1000);
}
