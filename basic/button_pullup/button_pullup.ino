/*
   버튼 사용하기
   사용부품: 버튼 3 개, LED 3 개, 저항(220Ω) 3 개, 저항(1KΩ) 3 개
*/

int button_inputPullup = 2;
int button_pullup = 3;
int button_pulldown = 4;
int red = 8;
int yellow = 9;
int green = 10;

void setup() {
  Serial.begin(9600);
  pinMode(button_inputPullup, INPUT_PULLUP);
  pinMode(button_pullup, INPUT);
  pinMode(button_pulldown, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  Serial.print("inner: ");
  Serial.print(digitalRead(button_inputPullup));
  Serial.print(" / pullup: ");
  Serial.println(digitalRead(button_pullup));
  Serial.print(" / pulldown: ");
  Serial.println(digitalRead(button_pulldown));
  delay(100);

  // 내부 pullup 저항(평소에 전류가 통하다가 버튼을 누르면 전류가 통하지 않음)
  digitalWrite(red, digitalRead(button_inputPullup));

  // 외부 pullup 저항(평소에 전류가 통하다가 버튼을 누르면 전류가 통하지 않음)
  digitalWrite(yellow, digitalRead(button_pullup));

  // 외부 pulldown 저항(평소에 전류가 통하지 않다가 버튼을 누르면 전류가 통함)
  digitalWrite(green, digitalRead(button_pulldown));
}
