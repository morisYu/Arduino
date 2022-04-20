/*
   조도센서를 사용해서 자동으로 불이 켜지도록 하기
   사용부품: 조도센서 2 개, LED 2 개, 저항(220Ω) 2 개, 저항(10KΩ) 2 개
   조도센서는 어두울수록 저항값이 높아짐.
   조도센서 회로가 서로 반대로 되어있어서 값이 반대로 측정됨.
*/

#define photo1 A0;
#define photo2 A1;
int red = 9;
int green = 10;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  int R = analogRead(A0);
  int G = analogRead(A1);
  Serial.print("red: ");
  Serial.print(R);
  Serial.print(" green: ");
  Serial.println(G);
  delay(100);

  // G는 어두울수록 값이 높음
  if (G > 512) {
    digitalWrite(green, HIGH);
  } else {
    digitalWrite(green, LOW);
  }

  // R은 어두울수록 값이 낮음
  if (R < 400) {
    analogWrite(red, 255);
  } else if (R >= 400 && R < 700) {
    analogWrite(red, 150);
  } else if (R >= 700 && 900) {
    analogWrite(red, 50);
  } else {
    analogWrite(red, 0);
  }

}
