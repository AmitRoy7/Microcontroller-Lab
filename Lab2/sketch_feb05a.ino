
#include<LiquidCrystal.h>
const int pinHigh = 8;
const int pinLow = 9;
const int led = 6;
int brightness = 0;
int fadeAmount = 10;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int msg = 0;
void setup() {
  pinMode(pinHigh, INPUT);
  pinMode(pinLow, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {


  if (digitalRead(pinHigh) == HIGH) {
    if(msg!=1)
    {
      lcd.clear();
      lcd.write("Intensifying LED");
      msg = 1;
    }
    else if(brightness==255)
    {
      lcd.clear();
      delay(1000);
      
    }
    brightness = brightness + fadeAmount;
  }
  else if (digitalRead(pinLow) == HIGH) {
    if(msg!=2)
    {
      lcd.clear();
      lcd.write("   Dimming LED");
      msg = 2;
    }
    else if(brightness==0)
    {
      lcd.clear();
      delay(1000);  
    }
    brightness = brightness - fadeAmount;
    
  }
  else
  {
    lcd.clear();
    msg = 0;
  }
  brightness = constrain(brightness, 0, 255);
  analogWrite(led, brightness);
  delay(250);


}
