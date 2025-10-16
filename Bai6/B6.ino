#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  lcd.begin(16,2);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(6,INPUT);
  lcd.setCursor(6, 0);
  lcd.print("HELLO");
}
byte btn_L_state=LOW;
byte btn_R_state=LOW;
byte btn_D_state=LOW;
byte mode=HIGH;
void loop() {
  if(!btn_L_state&&digitalRead(6)){
    lcd.scrollDisplayLeft();
    lcd.scrollDisplayLeft();
  }
  if(!btn_D_state&&digitalRead(7)){
    mode?lcd.noDisplay():lcd.display();
    mode=!mode;
  }
  if(!btn_R_state&&digitalRead(8)){
    lcd.scrollDisplayRight();
    lcd.scrollDisplayRight();
  }
  
  btn_L_state=digitalRead(6);
  btn_D_state=digitalRead(7);
  btn_R_state=digitalRead(8);

  delay(100);
}