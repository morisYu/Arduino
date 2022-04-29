/*
   가변저항으로 원하는 위치의 LED를 켜고, 끄기
   가변저항의 노브를 움직여서 LED 위치를 이동
   "offBtn"을 누르면 현재 위치의 LED를 켜고 끔
*/

int leds[] = {5, 6, 9, 10, 11};
bool ledOn[] = {false, false, false, false, false};
int offBtn = 3;
int arrayLength = sizeof(leds) / sizeof(int);
int index = 0;
int tmp = 0;

void setup() {
  Serial.begin(9600);
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
  index = map(analogRead(A0), 0, 1023, 0, 4);
  Serial.print("offBtn: ");
  Serial.print(digitalRead(offBtn));
  Serial.print(" | poten: ");
  Serial.print(analogRead(A0));
  Serial.print(" | index: ");
  Serial.println(index);
  delay(100);

  if (index != tmp) {
    if (ledOn[index] == true) {
      digitalWrite(leds[index], LOW);
      delay(100);
      digitalWrite(leds[index], HIGH);
    } else {
      digitalWrite(leds[index], HIGH);
      delay(100);
      digitalWrite(leds[index], LOW);
    }
    tmp = index;
  }

  // "offBtn" 누름 -> 현 위치의 LED를 켜기
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
