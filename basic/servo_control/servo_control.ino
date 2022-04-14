/*
   Servo 모터 제어하기
   사용부품: 서보모터(180 도) 2 개, 서보모터(360 도) 1 개, 외부전원
*/

#include <Servo.h>

// 서보모터 이름 설정
Servo servoA;
Servo servoB;
Servo servoC;

int start_angle = 0;
int mid_angle = 93;
int end_angle = 180;

void setup() {
  Serial.begin(9600);
  // 서보모터 핀 설정
  servoA.attach(9);   // 180도 모터
  servoB.attach(10);  // 180도 모터
  servoC.attach(11);  // 360도 모터

  // 서보모터 위치 초기화
  servoA.write(start_angle);
  servoB.write(start_angle);
  servoC.write(mid_angle);
}

void loop() {
  if(Serial.available()>0){
    char select = Serial.read();
    if(select == 'a'){
      controlA();
    }else if(select == 'b'){
      controlB();
    }else if(select == 'c'){
      controlC();
    }else if(select == 'd'){
      controlAB();
    }
  }
}

void controlA() {
  // servoA 0 -> 180 회전
  Serial.println("A모터 180 도");
  for (int i = start_angle; i < end_angle; i++) {
    servoA.write(i);
    delay(5);
  }
  delay(1000);
  // servoA 180 -> 0 회전
  Serial.println("A모터 0 도");
  for (int i = end_angle; i > start_angle; i--) {
    servoA.write(i);
    delay(5);
  }
}

void controlB() {
  int angle = Serial.parseInt();
  Serial.print("B 각도: ");
  Serial.println(angle);
  servoB.write(angle);
  delay(1000);
  Serial.println("B 원위치");
  servoB.write(start_angle);
}

// servoA, servoB 동시 동작
void controlAB() {
  Serial.println("A, B 180 도");
  for (int i = start_angle; i < end_angle; i++) {
    servoA.write(i);
    servoB.write(i);
    delay(10);
  }
  delay(1000);
  Serial.println("A, B 0 도");
  for (int i = end_angle; i > start_angle; i--) {
    servoA.write(i);
    servoB.write(i);
    delay(15);
  }
}

void controlC() {
  while (true) {
    char ch = Serial.read();
    Serial.println(ch);
    if (ch == 's') {
      servoC.write(90);
    } else if (ch == 'g') {
      int angle = Serial.parseInt();
      servoC.write(angle);
    } else {
      break;
    }
  }
}
