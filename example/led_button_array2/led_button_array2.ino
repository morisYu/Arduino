/*
   2 개의 버튼을 눌러서 원하는 위치의 LED를 켜고, 끄기
   "onBtn"을 누르면 LED 위치를 이동
   "offBtn"을 누르면 현재 위치의 LED를 켜고 끔
*/

int leds[] = {7, 8, 9, 10, 11};
bool ledOn[] = {false, false, false, false, false};
int onBtn = 2;
int offBtn = 3;
int arrayLength = sizeof(leds) / sizeof(int);
int index = 0;
int tmp = 1;

void setup() {
  Serial.begin(9600);
  pinMode(onBtn, INPUT_PULLUP);
  pinMode(offBtn, INPUT_PULLUP);
  for (int i = 0; i < arrayLength; i++) {
    pinMode(leds[i], OUTPUT);
    Serial.print(leds[i]);
    Serial.println(" OK");
    delay(500);
  }
  for (int i = 0; i < arrayLength; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(1000);
  for (int i = 0; i < arrayLength; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void loop() {

  Serial.print("onBtn: ");
  Serial.print(digitalRead(onBtn));
  Serial.print(" | offBtn: ");
  Serial.println(digitalRead(offBtn));
  delay(100);

  // "onBtn" 누름 -> LED 위치 설정
  if (digitalRead(onBtn) == 0) {
    if (tmp == 1) {
      index++;
      if (index > 4) {
        index = 0;
      }
      // 현재 위치 표시
      if (ledOn[index] == false) {
        digitalWrite(leds[index], HIGH);
        delay(100);
        digitalWrite(leds[index], LOW);
      }
    }
    tmp = 0;
  } else {
    tmp = 1;
  }

  // "offBtn" 누름 -> 현 위치의 LED 켜고 끔
  if (digitalRead(offBtn) == 0) {
    if (ledOn[index] == false) {
      digitalWrite(leds[index], HIGH);
      ledOn[index] = true;
    } else {
      digitalWrite(leds[index], LOW);
      ledOn[index] = false;
    }
    while (digitalRead(offBtn) == 0) {
      Serial.println("off wait....");
    }
  }
}
