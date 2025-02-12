#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define trigPin 8 
#define echoPin 9 
#define Buzzer 12

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("welcome");
  delay(2000);
 
}

void loop()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
    distance= duration/58.2;

  lcd.print(distance); 
   
  delay(250); 

  
 if (distance < 20 ){
   digitalWrite (13,HIGH);
   digitalWrite(Buzzer, HIGH);
 }
 else
 { digitalWrite (13,LOW);
   digitalWrite(Buzzer,LOW);
 }
}