#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  lcd.begin(16,2);
  pinMode(7,INPUT);
  pinMode(1,OUTPUT);
  lcd.display();
  digitalWrite(1,LOW);
  lcd.print("HELLO");
}
byte btn_state=LOW;
byte mode=LOW;
void loop() {
  if(!btn_state&&digitalRead(7)){
    if(mode){
      lcd.display();
      digitalWrite(1,LOW);
    }
    else{
      lcd.noDisplay();
      digitalWrite(1,HIGH);
    }
    mode=!mode;
  }
  
  btn_state=digitalRead(7);
  delay(100);
}
