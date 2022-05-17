/*
   스위치를 눌렀을 때 1~3 사이의 난수 발생
   스위치를 눌렀을 때 초록, 노랑, 빨강 순으로 켜지고 꺼지는 것을 3 번 반복
   발생한 난수는 시리얼 모니터에 출력
   값:색상 -> 1:초록, 2:초록+노랑, 3:초록+노랑+빨강
*/

int btn = 2;
int green = 11;
int yellow = 12;
int red = 13;

void setup() {
  Serial.begin(9600);
  pinMode(btn, INPUT_PULLUP);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

  digitalWrite(green, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, HIGH);
  delay(3000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
}

void loop() {
  if (digitalRead(btn) == 0) {
    int dice = tactSwitch();
    ledControl(dice);
    while (digitalRead(btn) == 0) {}
  }
}

int tactSwitch() {
  int result = random(1, 4);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  delay(500);
  for (int i = 0; i < 3; i++) {
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    delay(100);
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    delay(100);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    delay(100);
  }
  Serial.println(result);
  return result;
}

void ledControl(int num) {
  switch (num) {
    case 1:
      digitalWrite(green, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(red, LOW);
      break;
    case 2:
      digitalWrite(green, HIGH);
      digitalWrite(yellow, HIGH);
      digitalWrite(red, LOW);
      break;
    case 3:
      digitalWrite(green, HIGH);
      digitalWrite(yellow, HIGH);
      digitalWrite(red, HIGH);
      break;
  }
}
