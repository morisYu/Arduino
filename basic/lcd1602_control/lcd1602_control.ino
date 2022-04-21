/*
   LCD 1602 사용하기
   사용부품: LCD1602(기본) 1 개, LCD1602(IIC) 1 개, 저항(220 Ω) 1 개, 가변저항 1 개
   라이브러리: LiquidCrystal, LiquidCrystal_I2C (둘 다 라이브러리 관리자에서 설치)
*/

// 기본LCD 설정
#include <LiquidCrystal.h>
const int rs = 4, en = 5, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// IIC LCD 설정
// 핀연결: A4-SDA(DATA), A5-SCL(CLOCK)
// 화면 어둡거나 안나오는 경우 LCD 뒷면에 가변저항 조절하면 됨
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// LCD address: 0x3F OR ox27
LiquidCrystal_I2C lcd_IIC(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  // 기본LCD 시작
  lcd.begin(16, 2);
  lcd.print("hello, world!");

  // IIC LCD 시작
  lcd_IIC.init();
  lcd_IIC.backlight();
  lcd_IIC.print("hello, world!");

}

void loop() {
  lcd.clear();
  lcd_IIC.clear();
  lcd.setCursor(0, 0);
  lcd.print("blink");
  lcd_IIC.setCursor(0, 0);
  lcd_IIC.print("blink");
  delay(500);
  sample_blink();
  delay(1000);

  lcd.clear();
  lcd_IIC.clear();
  lcd.setCursor(0, 0);
  lcd.print("autoscroll");
  lcd_IIC.setCursor(0, 0);
  lcd_IIC.print("autoscroll");
  delay(500);
  sample_autoscroll();
  delay(1000);

  lcd.clear();
  lcd_IIC.clear();
  lcd.setCursor(0, 0);
  lcd.print("display");
  lcd_IIC.setCursor(0, 0);
  lcd_IIC.print("display");
  delay(500);
  sample_display();
  delay(1000);

  lcd.clear();
  lcd_IIC.clear();
  lcd.setCursor(0, 0);
  lcd.print("input_scroll");
  lcd_IIC.setCursor(0, 0);
  lcd_IIC.print("input_scroll");
  delay(500);
  input_scroll();
  delay(1000);
}

void sample_blink() {
  // 커서 안보임
  lcd.noBlink();
  lcd_IIC.noBlink();
  delay(3000);
  // 커서 깜빡임
  lcd.blink();
  lcd_IIC.blink();
  delay(3000);
}

void sample_autoscroll() {
  // 커서 위치 설정
  lcd.setCursor(0, 0);
  lcd_IIC.setCursor(0, 0);

  // lcd 출력
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    lcd_IIC.print(thisChar);
    delay(500);
  }

  // 커서 위치 설정
  lcd.setCursor(16, 1);
  lcd_IIC.setCursor(16, 1);

  // autoscroll 활성화
  lcd.autoscroll();
  lcd_IIC.autoscroll();

  // lcd 출력
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    lcd_IIC.print(thisChar);
    delay(500);
  }

  // autoscroll 비활성화
  lcd.noAutoscroll();
  lcd_IIC.noAutoscroll();

  // lcd 화면 내용 지움
  lcd.clear();
  lcd_IIC.clear();
}

void sample_display() {
  // 화면 끄기(출력된 내용을 지우는게 아님)
  lcd.noDisplay();
  lcd_IIC.noDisplay();
  delay(500);

  // 화면 켜기
  lcd.display();
  lcd_IIC.display();
  delay(500);
}

void input_scroll() {
  if (Serial.available() > 0) {
    char ch = 'H';
    int val = 135;
    String inputStr = Serial.readStringUntil('\n');

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(inputStr);
    lcd.setCursor(0, 1);
    lcd.print(ch);
    lcd.print(" ");
    lcd.print(val);

    lcd_IIC.clear();
    lcd_IIC.setCursor(0, 0);
    lcd_IIC.print(inputStr);
    lcd_IIC.setCursor(0, 1);
    lcd_IIC.print(ch);
    lcd_IIC.print(" ");
    lcd_IIC.print(val);

    for (int i = 0; i < 3; i++) {
      for (int positionCounter = 0; positionCounter < inputStr.length(); positionCounter++) {
        lcd.scrollDisplayLeft();
        lcd_IIC.scrollDisplayLeft();
        delay(150);
      }
      for (int positionCounter = 0; positionCounter < inputStr.length(); positionCounter++) {
        lcd.scrollDisplayRight();
        lcd_IIC.scrollDisplayRight();
        delay(150);
      }

      for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
        lcd.scrollDisplayRight();
        lcd_IIC.scrollDisplayRight();
        delay(150);
      }

      for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
        lcd.scrollDisplayLeft();
        lcd_IIC.scrollDisplayLeft();
        delay(150);
      }
    }
  }
}
