const int btn = 2;
const int ledYellow = 9;
const int ledRed = 10;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // ms

int state = 0;
int ButtonState = HIGH; 
int l_ButtonState = HIGH;   
int stableButtonState = HIGH;  

void setup() {
  pinMode(btn, INPUT_PULLUP); 
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  updateLEDs();
}

void loop() {
  ButtonState = digitalRead(btn);

  if (ButtonState != l_ButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (ButtonState != stableButtonState) {
      stableButtonState = ButtonState;
      if (stableButtonState == LOW) {
        state = (state + 1) % 4;
        updateLEDs();
      }
    }
  }
  l_ButtonState = ButtonState;
}

void updateLEDs() {
  switch (state) {
    case 0: 
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, LOW);
      break;
    case 1: 
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledRed, HIGH);
      break;
    case 2: 
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledRed, LOW);
      break;
    case 3: 
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, HIGH);
      break;
  }
}