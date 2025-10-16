#include <LiquidCrystal.h>
const int numRows = 2;
const int numCols = 16;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(numCols, numRows);
  pinMode(A0, INPUT);
  pinMode(13, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(0,LOW);
}
float voltage;
float temp;
float tempF;
//float tempF;
byte btn_State=LOW;
byte tempMode=LOW;

void loop() {
  lcd.clear();
  if (digitalRead(13) && !btn_State) {
    tempMode=!tempMode;
  }
  

  voltage = analogRead(A0) * 5.0 / 1024.0;
  temp = voltage * 100.0;
  //tempF = (temp*1.8)+32;
  
  if (tempMode) {
    tempF = (temp * 1.8) + 32;
    lcd.print(String(tempF) + " do F");
  } else {
    lcd.print(String(temp) + " do C");
  }

  if (temp < 17) {
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
  } else if (temp <= 30) {
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
  } else {
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
  }
  btn_State = digitalRead(13);
  delay(200);
}
