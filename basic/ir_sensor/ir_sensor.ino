/*
   IR 송수신 센서 모듈 사용하기
   사용부품: IR 송수신 센서 모듈(FC-51) 1 개, LED 1 개, 저항(220Ω) 1 개
   플로팅 현상 있으면 INPUT_PULLUP 으로 설정
*/

int sensor = 2;
int led = 8;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  Serial.println(digitalRead(sensor));
  if(digitalRead(sensor)){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }

}
