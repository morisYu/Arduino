#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display
int btn = 9;

void setup()
{
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");
  lcd.setCursor(0, 1);
  lcd.print("1602 lcd test");
  delay(1000);
  lcd.clear();
  delay(500);

}
void loop()
{
  if (!digitalRead(btn)) {
    lcd.clear();
    int randNumber = random(1, 7);
    int row = random(0, 3);
    int column = random(0, 19);
    Serial.print("row: ");
    Serial.print(row);
    Serial.print(" | column: ");
    Serial.print(column);
    Serial.print(" | number: ");
    Serial.println(randNumber);
    lcd.setCursor(column, row);
    lcd.print(randNumber);
    while(!digitalRead(btn)){
      
    }
  }
}
