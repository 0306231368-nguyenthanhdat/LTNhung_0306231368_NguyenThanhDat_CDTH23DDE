const int red1 = 12;
const int yellow1 = 11;
const int green1 = 10;

const int red2 = 9;
const int yellow2 = 8;
const int green2 = 7;

const int timeGreen = 5000; 
const int timeYellow = 2000; 
const int timeDelay = 500;

void setup() {
  // Cài đặt các chân là OUTPUT
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  // Tắt hết đèn lúc khởi động
  allOff();
}

void loop() {
  digitalWrite(green1, HIGH);
  digitalWrite(red2, HIGH);
  delay(timeGreen);

  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);
  delay(timeYellow);

  allOff();

  digitalWrite(green2, HIGH);
  digitalWrite(red1, HIGH);
  delay(timeGreen);

  digitalWrite(green2, LOW);
  digitalWrite(yellow2, HIGH);
  delay(timeYellow);

  allOff();
  delay(timeDelay);
}

void allOff() {
  digitalWrite(red1, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
}
