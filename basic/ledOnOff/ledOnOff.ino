/*
    LED 켜고 끄기
    사용부품: LED 3 개, 저항(220Ω) 3 개
*/

int red = 8;
int yellow = 9;
int green = 10;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char ch = Serial.read();
    switch (ch) {
      case 's':
        led_on();
        break;
      case 'n':
        led_off();
        break;
      case '1':
        led1();
        break;
      case '2':
        led2();
        break;
      case '3':
        led3();
        break;
    }
  }
}

// LED 3 개 동시에 켜기
void led_on() {
  Serial.println("led_on");
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, HIGH);
}

// LED 3 개 동시에 끄기
void led_off() {
  Serial.println("led_off");
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}

// LED 3 개를 동시에 켜고 끄기
void led1() {
  Serial.println("led1 start");
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);
}

// LED 를 1 개씩 교대로 켜기
void led2() {
  Serial.println("led2 start");
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(500);
}

// LED 를 1 개씩 켜고, 역순으로 1 개씩 끄기
void led3() {
  Serial.println("led3 start");
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}
