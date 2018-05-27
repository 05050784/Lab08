#include <Ultrasonic.h>
#include <LiquidCrystal.h> // include the library code
LiquidCrystal lcd(12, 11, 5, 4, 3, 7);
#define TRIGGER_PIN 16
#define ECHO_PIN 17
const byte intPin=2;
const byte ledPin=13;
volatile boolean ledState=LOW;
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(intPin, INPUT_PULLUP);
  //digitalWrite(ledPin, ledState);
  attachInterrupt(2, int0, LOW);
  Serial.begin(9600);
  lcd.begin(16, 2);
}
void loop()
{
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
  Serial.print("111");
  /*if (ledState)
  {
    Serial.print("222");
    lcd.print("MS: ");
    lcd.print(microsec);
    lcd.print(", CM: "); 
    lcd.print(cmMsec);
    lcd.print(", IN: ");
    lcd.print(inMsec);
    delay(1000);
  }
  else
  {
    Serial.print("333");
    delay(1000);
  }*/
}
void int0() 
{ //interrupt handler
  delay(1000);
   float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
   inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
    lcd.print("MS: ");
    lcd.print(microsec);
    lcd.print(", CM: "); 
    lcd.print(cmMsec);
    lcd.print(", IN: ");
    lcd.print(inMsec);
    ledState=!ledState; //reverse state
    delay(10000);
}
