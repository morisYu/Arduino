/*
   초음파센서 사용하기
   사용부품: 초음파센서(HC-SR04) 1 개
*/

int ECHO = 8;
int TRIG = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  long duration, distance;

  // TRIG에서 초음파를 내보냄
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // 초음파가 물체에 부딪힌 후 ECHO로 되돌아오는 시간 측정(마이크로초로 측정됨)
  duration = pulseIn(ECHO, HIGH);

  // 초음파 속도(340 m/s), m 단위를 cm 로 변환, microsecnod 단위를 s 단위로 변환
  // 초음파가 왕복을 했기 때문에 편도거리를 구하기 위해서 2 로 나눠줌
  distance = ((float)(340 * duration) / 10000) / 2;

  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
