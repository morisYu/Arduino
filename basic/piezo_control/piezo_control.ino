/*
   Piezo 스피커 제어하기
   사용부품: Piezo 스피커(수동) 1 개
*/

// 메모장으로 헤더파일 생성, 아두이노 라이브러리폴더에 복사 후 사용 가능
#include "pitches.h"

int piezopin = 7;
int tempo = 250;
String notes[] = {"도", "레", "미", "파", "솔", "라", "시"};
int notes3[] = {131, 147, 165, 175, 196, 220, 247};
int notes4[] = {262, 294, 330, 349, 392, 440, 494};
int notes5[] = {523, 587, 659, 698, 784, 880, 988};

void setup() {
  Serial.begin(9600);
  pinMode(piezopin, OUTPUT);
}

void loop() {
  basic();
  music_A();
  music_B();
  music_C();
}

// 3옥타브 도에서 5옥타브 시까지
void basic() {
  Serial.println("3옥타브");
  for (int i = 0; i < 7; i++) {
    Serial.println(notes[i]);
    tone(piezopin, notes3[i]);
    delay(tempo);
  }

  Serial.println("4옥타브");
  for (int i = 0; i < 7; i++) {
    Serial.println(notes[i]);
    tone(piezopin, notes4[i]);
    delay(tempo);
  }

  Serial.println("5옥타브");
  for (int i = 0; i < 7; i++) {
    Serial.println(notes[i]);
    tone(piezopin, notes5[i]);
    delay(tempo);
  }

  noTone(piezopin);
  delay(1000);
}

// 관짝밈 노래
void music_A() {
  //음계
  int notes[] = {
    NOTE_D4, NOTE_D4, NOTE_A4, NOTE_G4, NOTE_F4, 0,
    NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_E4, 0,
    NOTE_D4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_F4, 0,
    NOTE_D4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_F4, 0,
    NOTE_D6, NOTE_D6, NOTE_A6, NOTE_G6, NOTE_F6, 0,
    NOTE_E6, NOTE_E6, NOTE_E6, NOTE_G6, NOTE_F6, NOTE_E6, 0,
    NOTE_D6, NOTE_D6, NOTE_F6, NOTE_E6, NOTE_F6, NOTE_E6, NOTE_F6, 0,
    NOTE_D6, NOTE_D6, NOTE_F6, NOTE_E6, NOTE_F6, NOTE_E6, NOTE_F6, 0,
  };

  //연주시간
  int duration[] = {
    4, 2, 2, 4, 4,
    4, 2, 2, 4, 2, 2,
    4, 2, 2, 2, 2, 2, 2,
    4, 2, 2, 2, 2, 2, 2,
    4, 2, 2, 4, 4,
    4, 2, 2, 4, 2, 2,
    4, 2, 2, 2, 2, 2, 2,
    4, 2, 2, 2, 2, 2, 2
  };

  int notes_size = sizeof(notes) / sizeof(int);
  int notes_speed = 2; //노래 빠르기, 숫자가 작을수록 빠르고 클수록 느림

  for (int i = 0; i < notes_size; i++) {
    int duration_note = 1000 / duration[i];
    tone(piezopin, notes[i], duration_note); // 배열순으로 노래 재생
    int pausenotes = duration_note * notes_speed;
    delay(pausenotes);
  }
  noTone(piezopin);
  delay(1000);
}

// 반짝반짝 작은별
void music_B() {
  float singspeed = 0.55; //숫자가 작을수록 빠름
  int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
  tone(piezopin, melody[0], 250);  delay(500 * singspeed);
  tone(piezopin, melody[0], 250);  delay(500 * singspeed);
  tone(piezopin, melody[4], 250);  delay(500 * singspeed);
  tone(piezopin, melody[4], 250);  delay(500 * singspeed);
  tone(piezopin, melody[5], 250);  delay(500 * singspeed);
  tone(piezopin, melody[5], 250);  delay(500 * singspeed);
  tone(piezopin, melody[4], 500);  delay(1000 * singspeed);
  tone(piezopin, melody[3], 250);  delay(500 * singspeed);
  tone(piezopin, melody[3], 250);  delay(500 * singspeed);
  tone(piezopin, melody[2], 250);  delay(500 * singspeed);
  tone(piezopin, melody[2], 250);  delay(500 * singspeed);
  tone(piezopin, melody[1], 250);  delay(500 * singspeed);
  tone(piezopin, melody[1], 250);  delay(500 * singspeed);
  tone(piezopin, melody[0], 500);  delay(1000 * singspeed);
  tone(piezopin, melody[4], 250);  delay(500 * singspeed);
  tone(piezopin, melody[4], 250);  delay(500 * singspeed);
  tone(piezopin, melody[3], 250);  delay(500 * singspeed);
  tone(piezopin, melody[3], 250);  delay(500 * singspeed);
  tone(piezopin, melody[2], 250);  delay(500 * singspeed);
  tone(piezopin, melody[2], 250);  delay(500 * singspeed);
  tone(piezopin, melody[1], 500);  delay(1000 * singspeed);
  tone(piezopin, melody[4], 250);  delay(500 * singspeed);
  tone(piezopin, melody[4], 250);  delay(500 * singspeed);
  tone(piezopin, melody[3], 250);  delay(500 * singspeed);
  tone(piezopin, melody[3], 250);  delay(500 * singspeed);
  tone(piezopin, melody[2], 250);  delay(500 * singspeed);
  tone(piezopin, melody[2], 250);  delay(500 * singspeed);
  tone(piezopin, melody[1], 500);  delay(1000 * singspeed);
  tone(piezopin, melody[0], 250);  delay(500 * singspeed);
  tone(piezopin, melody[0], 250);  delay(500 * singspeed);
  tone(piezopin, melody[4], 250);  delay(500 * singspeed);
  tone(piezopin, melody[4], 250);  delay(500 * singspeed);
  tone(piezopin, melody[5], 250);  delay(500 * singspeed);
  tone(piezopin, melody[5], 250);  delay(500 * singspeed);
  tone(piezopin, melody[4], 500);  delay(1000 * singspeed);
  tone(piezopin, melody[3], 250);  delay(500 * singspeed);
  tone(piezopin, melody[3], 250);  delay(500 * singspeed);
  tone(piezopin, melody[2], 250);  delay(500 * singspeed);
  tone(piezopin, melody[2], 250);  delay(500 * singspeed);
  tone(piezopin, melody[1], 250);  delay(500 * singspeed);
  tone(piezopin, melody[1], 250);  delay(500 * singspeed);
  tone(piezopin, melody[0], 500);  delay(1000 * singspeed);
  noTone(piezopin);
  delay(1000);
}

// 곰세마리
void music_C() {
  float singspeed = 0.75; //숫자가 작을수록 빠름
  tone(piezopin, 262, 200); delay(400 * singspeed); //도
  tone(piezopin, 262, 200); delay(300 * singspeed); //도
  tone(piezopin, 262, 200); delay(300 * singspeed); //도
  tone(piezopin, 262, 200); delay(400 * singspeed); //도
  tone(piezopin, 262, 200); delay(400 * singspeed); //도

  tone(piezopin, 330, 200); delay(400 * singspeed); //미
  tone(piezopin, 392, 200); delay(300 * singspeed); //솔
  tone(piezopin, 392, 200); delay(300 * singspeed); //솔
  tone(piezopin, 330, 200); delay(400 * singspeed); //미
  tone(piezopin, 262, 200); delay(400 * singspeed); //도

  tone(piezopin, 392, 200); delay(300 * singspeed); //솔
  tone(piezopin, 392, 200); delay(300 * singspeed); //솔
  tone(piezopin, 330, 200); delay(400 * singspeed); //미
  tone(piezopin, 392, 200); delay(300 * singspeed); //솔
  tone(piezopin, 392, 200); delay(300 * singspeed); //솔
  tone(piezopin, 330, 200); delay(400 * singspeed); //미

  tone(piezopin, 262, 200); delay(400 * singspeed); //도
  tone(piezopin, 262, 200); delay(400 * singspeed); //도
  tone(piezopin, 262, 400); delay(600 * singspeed); //도

  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 330, 200); delay(400 * singspeed); //미
  tone(piezopin, 262, 200); delay(400 * singspeed); //도

  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 392, 400); delay(800 * singspeed); //솔

  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 330, 200); delay(400 * singspeed); //미
  tone(piezopin, 262, 200); delay(400 * singspeed); //도

  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 392, 200); delay(800 * singspeed); //솔

  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 330, 200); delay(400 * singspeed); //미
  tone(piezopin, 262, 200); delay(400 * singspeed); //도

  tone(piezopin, 392, 200); delay(300 * singspeed); //솔
  tone(piezopin, 392, 200); delay(300 * singspeed); //솔
  tone(piezopin, 392, 200); delay(300 * singspeed); //솔
  tone(piezopin, 440, 200); delay(300 * singspeed); //라
  tone(piezopin, 392, 400); delay(800 * singspeed); //솔

  tone(piezopin, 523, 200); delay(400 * singspeed); //높은도
  tone(piezopin, 392, 200); delay(400 * singspeed); //솔
  tone(piezopin, 523, 200); delay(400 * singspeed); //높은도
  tone(piezopin, 392, 200); delay(400 * singspeed); //솔

  tone(piezopin, 330, 200); delay(400 * singspeed); //미
  tone(piezopin, 294, 200); delay(400 * singspeed); //레
  tone(piezopin, 262, 400); delay(800 * singspeed); //도
  noTone(piezopin);
  delay(1000);
}
