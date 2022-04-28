/*
 * 2 개의 버튼을 눌러서 LED를 순차적으로 켜고, 끄기
 * "onBtn"을 누르면 LED가 순차적으로 켜지며, 중간에 버튼을 떼면 남은 LED는 안켜짐
 * "offBtn"을 누르면 LED가 역순으로 꺼지며, 중간에 버튼을 떼면 남은 LED는 안꺼짐
 */

int leds[] = {7, 8, 9, 10, 11};
bool ledOn[] = {false, false, false, false, false};
int onBtn = 2;
int offBtn = 3;
int arrayLength = sizeof(leds) / sizeof(int);

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
}

void loop() {
  int index = 0;
  Serial.print("onBtn: ");
  Serial.print(digitalRead(onBtn));
  Serial.print(" | offBtn: ");
  Serial.println(digitalRead(offBtn));
  delay(100);

  // "onBtn" 누름
  if (digitalRead(onBtn) == false) {
    // 앞에서부터 현재 불이 꺼져있는 LED 위치를 확인
    for (int i = 0; i < arrayLength; i++) {
      if (ledOn[i] == false) {
        index = i;
        Serial.println("-------------------");
        Serial.println(index);
        break;
      }
    }

    // 불이 꺼져있는 LED 부터 불을 켬
    for (int j = index; j < arrayLength; j++) {
      digitalWrite(leds[j], HIGH);
      ledOn[j] = true;
      delay(1000);
      if (digitalRead(onBtn) == true) {
        break;
      }
    }
    while (digitalRead(onBtn) == false) {
      Serial.println("on wait....");
    }
  }

  // "offBtn" 누름
  if (digitalRead(offBtn) == false) {
    // 뒤에서부터 현재 불이 켜져있는 LED 위치를 확인
    for (int i = arrayLength - 1; i >= 0 ; i--) {
      if (ledOn[i] == true) {
        index = i;
        Serial.println("-------------------");
        Serial.println(index);
        break;
      }
    }

    // 불이 켜져있는 LED를 뒤에서부터 불을 끔
    for (int i = index; i >= 0; i--) {
      digitalWrite(leds[i], LOW);
      ledOn[i] = false;
      delay(1000);
      if (digitalRead(offBtn) == true) {
        break;
      }
    }
    while (digitalRead(offBtn) == false) {
      Serial.println("off wait....");
    }
  }
}
