#include <Ultrasonic.h>
#include <LiquidCrystal.h> // include the library code
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define TRIGGER_PIN 16
#define ECHO_PIN 17
//const byte intPin=2;
//const byte ledPin=13;
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() 
{
  
  Serial.begin(9600);
  lcd.begin(16, 2);
}
void loop()
{
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
  
  lcd.print("MS: ");
  lcd.print(microsec);
  lcd.print(", CM: "); 
  lcd.print(cmMsec);
  lcd.print(", IN: ");
  lcd.print(inMsec);
  delay(1000);
}
