int led = 10;
int upbtn = 2;
int downbtn = 1;
int brightness = 128;
int p_upstate = LOW;
int p_downstate = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(upbtn, INPUT);
  pinMode(downbtn, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (p_upstate == HIGH && digitalRead(upbtn)==LOW)
  {
    brightness +=50;
    if(brightness > 255) 
      brightness = 255;
    analogWrite(led, brightness);
    delay(200);
  }
    if (p_downstate == HIGH && digitalRead(downbtn)==LOW)
  {
    brightness -=50;
    if(brightness < 0) 
      brightness = 0;
    analogWrite(led, brightness);
    delay(200);
  }
  p_upstate = digitalRead(upbtn);
  p_downstate = digitalRead(downbtn);
}
