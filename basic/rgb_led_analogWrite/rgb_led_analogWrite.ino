/*
   analog 값을 읽어서 LED 밝기 조절하기, PWM 실습
   사용부품: RGB_LED 1 개, 저항(220Ω) 1 개, 가변저항 3 개, 버튼 1 개
*/

int B = 9;
int G = 10;
int R = 11;
int poten1 = A0;
int poten2 = A1;
int poten3 = A2;
int button = 2;

void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (Serial.available() > 0) {
    char ch = Serial.read();
    switch (ch) {
      case '1':
        pwm();
        break;
      case '2':
        control();
        break;
      case '3':
        randomColor();
        break;
      default:
        Serial.println("1 OR 2 OR 3 input");
        break;
    }
  }
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 0);

}

// 가변저항 2 개로 LED 켜지는 시간, 꺼지는 시간 조절
void pwm() {
  while (digitalRead(button)) {
    Serial.print("ONtime: ");
    Serial.print(analogRead(poten1));
    Serial.print(" | OFFtime: ");
    Serial.println(analogRead(poten2));

    analogWrite(R, 255);
    delayMicroseconds(analogRead(poten1) * 10);
    analogWrite(R, 0);
    delayMicroseconds(analogRead(poten2) * 10);
  }
}

// 가변저항 3 개로 RGB LED 색상 제어
void control() {
  while (digitalRead(button)) {
    int red = map(analogRead(poten1), 0, 1023, 0, 255);
    int green = map(analogRead(poten2), 0, 1023, 0, 255);
    int blue = map(analogRead(poten3), 0, 1023, 0, 255);

    Serial.print("R: ");
    Serial.print(red);
    Serial.print(" | G: ");
    Serial.print(green);
    Serial.print(" | B ");
    Serial.println(blue);

    analogWrite(R, red);
    analogWrite(G, green);
    analogWrite(B, blue);
  }
}

// 랜덤으로 RGB LED 색상 바꾸기
void randomColor() {
  while (digitalRead(button)) {
    analogWrite(R, random(256));
    analogWrite(G, random(256));
    analogWrite(B, random(256));
    delay(2000);
  }
}
