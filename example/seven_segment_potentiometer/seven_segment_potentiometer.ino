/*
 * 가변저항으로 7세그먼트(common anode 타입) 제어하기
 * map() 으로 가변저항 값에 따라 숫자 증감
 * common cathode 타입과 sw가 반대로 되어야 함
 * digitalWrite에서 ! 사용
 */

int seg[7] = {2, 3, 4, 5, 6, 7, 8};
int sw[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 1, 1}
};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    pinMode(seg[i], OUTPUT);
  }
}

void loop() {
  int resistor = analogRead(0);
  int count = map(resistor, 0, 1023, 0, 9);
  Serial.print("resistor: ");
  Serial.print(resistor);
  Serial.print(" count: ");
  Serial.println(count);
 
  led(count);
}

void led(int num) {
  switch (num) {
    case 0:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], !sw[0][i]);
      }
      break;
    case 1:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], !sw[1][i]);
      }
      break;
    case 2:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], !sw[2][i]);
      }
      break;
    case 3:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], !sw[3][i]);
      }
      break;
    case 4:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], !sw[4][i]);
      }
      break;
    case 5:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], !sw[5][i]);
      }
      break;
    case 6:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], !sw[6][i]);
      }
      break;
    case 7:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], !sw[7][i]);
      }
      break;
    case 8:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], !sw[8][i]);
      }
      break;
    case 9:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], !sw[9][i]);
      }
      break;
  }
}
