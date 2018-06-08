#include<LiquidCrystal.h>

float temp;
const int buttonpin = 8;
bool flag;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void setup() {
  flag = true;
  pinMode(buttonpin, INPUT);
//  Serial.begin(9600);
 lcd.begin(16,2);
}

void loop() {

  if (digitalRead(buttonpin) == HIGH) {
    flag = !flag;
    delay(300);
  }
  temp = analogRead(A0);
  temp = temp * 0.48828125;
  if(flag)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp: "); 
    lcd.print(temp,2);
    lcd.print("*C");
  }
  else
  {
    temp = 5.0*temp;
    temp /= 9.0;
    temp += 32.0;
    
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(temp,2);
    lcd.print("*F");
  }
  delay (500);
}

