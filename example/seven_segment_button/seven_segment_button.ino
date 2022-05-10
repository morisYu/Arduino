/*
 * 버튼 2 개로 7세그먼트 제어하기
 * addBtn 을 누르면 숫자가 증가
 * subBtn 을 누르면 숫자가 감소
 */

int seg[7] = {2, 3, 4, 5, 6, 7, 8};
int addBtn = 10;
int subBtn = 11;
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
int count = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    pinMode(seg[i], OUTPUT);
  }
  pinMode(addBtn, INPUT_PULLUP);
  pinMode(subBtn, INPUT_PULLUP);
}

void loop() {
  int add = digitalRead(addBtn);
  int sub = digitalRead(subBtn);
  Serial.print("add: ");
  Serial.print(add);
  Serial.print(" sub: ");
  Serial.print(sub);
  Serial.print(" count: ");
  Serial.println(count);
  if(add == false){
    count++;
    while(!digitalRead(addBtn)){
      
    }
  }
  if(sub ==false){
    count--;
    while(!digitalRead(subBtn)){
      
    }
  }
  if(count>9){
    count = 0;
  }
  if(count<0){
    count = 9;
  }
  led(count);
}

void led(int num) {
  switch (num) {
    case 0:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], sw[0][i]);
      }
      break;
    case 1:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], sw[1][i]);
      }
      break;
    case 2:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], sw[2][i]);
      }
      break;
    case 3:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], sw[3][i]);
      }
      break;
    case 4:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], sw[4][i]);
      }
      break;
    case 5:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], sw[5][i]);
      }
      break;
    case 6:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], sw[6][i]);
      }
      break;
    case 7:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], sw[7][i]);
      }
      break;
    case 8:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], sw[8][i]);
      }
      break;
    case 9:
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg[i], sw[9][i]);
      }
      break;
  }
}
