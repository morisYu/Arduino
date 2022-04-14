/*
   analog 값을 읽어서 LED 밝기 조절하기
   사용부품: LED 3 개, 저항(220Ω) 3 개, 가변저항 2 개
*/

int red = 9;
int yellow = 10;
int green = 11;
int poten1 = A0;
int poten2 = A1;
int light = 0;

void setup() {
  Serial.begin(9600);
  // analogWrite로 사용할 경우 pinMode 설정 안해도 됨
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

}

void loop() {
  Serial.print("poten1: ");
  Serial.print(analogRead(poten1));
  Serial.print(" | poten2: ");
  Serial.print(analogRead(poten2));
  Serial.print(" | light: ");
  Serial.println(light);

  analogWrite(red, analogRead(poten1) / 4);
  analogWrite(yellow, analogRead(poten2) / 4);
  analogWrite(green, light++);

  if (light > 255) {
    light = 0;
  }
}
