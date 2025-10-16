#include <LiquidCrystal.h>
const int numRows = 2;
const int numCols = 16;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(numCols, numRows);
  pinMode(A0, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}
float voltage;
float temp;
float tempF;
byte btn_CState = LOW;
byte btn_FState = LOW;
byte tempMode = LOW;

void loop() {
  if (digitalRead(8) && !btn_CState) {
    tempMode = LOW;
  }
  if (digitalRead(9) && !btn_FState) {
    tempMode = HIGH;
  }

  lcd.clear();
  voltage = analogRead(A0) * 5.0 / 1024.0;
  temp = voltage * 100.0;
  if (tempMode) {
    tempF = (temp * 1.8) + 32;
    lcd.print(String(tempF) + " do F");
  } else {
    lcd.print(String(temp) + " do C");
  }
  btn_CState = digitalRead(8);
  btn_FState = digitalRead(9);
  delay(100);
}