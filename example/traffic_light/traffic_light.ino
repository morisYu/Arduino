/*
   보행자 신호등, 자동차 신호등 동시 작동
   자동차 신호등: 녹색(3초) -> 노란색(1초) -> 빨간색(5초)
   보행자 신호등: 빨간색(4초) -> 녹색(5초)
*/

int carRed = 13;
int carYellow = 12;
int carGreen = 11;
int personRed = 9;
int personGreen = 8;

void setup() {
  Serial.begin(9600);
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(personRed, OUTPUT);
  pinMode(personGreen, OUTPUT);

  Serial.println("Test ON");
  digitalWrite(carRed, HIGH);
  digitalWrite(carYellow, HIGH);
  digitalWrite(carGreen, HIGH);
  digitalWrite(personRed, HIGH);
  digitalWrite(personGreen, HIGH);
  delay(3000);
  Serial.println("Test OFF");
  digitalWrite(carRed, LOW);
  digitalWrite(carYellow, LOW);
  digitalWrite(carGreen, LOW);
  digitalWrite(personRed, LOW);
  digitalWrite(personGreen, LOW);
}

void loop() {
  Serial.println("carGreen ON, personRed ON");
  Serial.println("3 seconds Wait");
  digitalWrite(carRed, LOW);
  digitalWrite(carYellow, LOW);
  digitalWrite(carGreen, HIGH);
  digitalWrite(personRed, HIGH);
  digitalWrite(personGreen, LOW);
  delay(3000);
  Serial.println("carYellow ON, personRed ON");
  Serial.println("1 seconds Wait");
  digitalWrite(carRed, LOW);
  digitalWrite(carYellow, HIGH);
  digitalWrite(carGreen, LOW);
  digitalWrite(personRed, HIGH);
  digitalWrite(personGreen, LOW);
  delay(1000);
  Serial.println("carRed ON, personGreen ON");
  Serial.println("5 seconds Wait");
  digitalWrite(carRed, HIGH);
  digitalWrite(carYellow, LOW);
  digitalWrite(carGreen, LOW);
  digitalWrite(personRed, LOW);
  digitalWrite(personGreen, HIGH);
  delay(5000);
}
