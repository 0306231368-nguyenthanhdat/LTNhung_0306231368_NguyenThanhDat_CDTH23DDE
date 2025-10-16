#include <Keyboard.h>  

void setup() {
  Serial.begin(9600);
  Keyboard.begin(); 
}

void loop() {
  if (Serial.available()) {
    char currentKey = Serial.read();

    if (currentKey == 'a') {
      Keyboard.write('a');
    } else if (currentKey == 'b') {
      Keyboard.write('b');
    } else if (currentKey == 'c') {
      Keyboard.write('c');
    } else if (currentKey == 'd') {
      Keyboard.write('d');
    } else if (currentKey == 'e') {
      Keyboard.write('e');
    }
  }
}
