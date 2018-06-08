#include<LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int red1    = 6;
const int green1  = 7;
const int red2    = 8;
const int green2  = 9;

const int in = 14;
const int out = 19;

void OUT()
{
	lcd.clear();
	lcd.print("Lane1: OFF");
	lcd.setCursor(0,1);
	lcd.print("Lane2: ON");
	
digitalWrite(green2,HIGH);
	digitalWrite(red2,LOW);
	digitalWrite(red1,HIGH);
	digitalWrite(green1,LOW);
    	delay(3000);
}


void IN()
{
lcd.clear();
	lcd.print("Lane1: ON");
	lcd.setCursor(0,1);
	lcd.print("Lane2: OFF");

	digitalWrite(green1,HIGH);
	digitalWrite(red1,LOW);
	digitalWrite(red2,HIGH);
	digitalWrite(green2,LOW);
	
	delay(3000);
}
void NEUTRAL()
{
	lcd.clear();
	lcd.print("Lane1: ON");
	lcd.setCursor(0,1);
	lcd.print("Lane2: ON");
	
digitalWrite(green1,HIGH);
	digitalWrite(red1,LOW);
	digitalWrite(green2,HIGH);
	digitalWrite(red2,LOW);
	
delay(100);
}

void setup()
{
	pinMode(in, INPUT);
	pinMode(out, INPUT);
	
pinMode(red1,OUTPUT);
	pinMode(green1,OUTPUT);
	pinMode(red2,OUTPUT);
	pinMode(green2,OUTPUT);
	
lcd.begin(16,2);
lcd.clear();
lcd.print(" TRAFFIC CONTROL");
delay(2000);

lcd.clear();
lcd.print("Lane1: ON");
lcd.setCursor(0,1);
lcd.print("Lane2: ON");
  
   	digitalWrite(green1,HIGH);
	digitalWrite(red1,LOW);
	digitalWrite(green2,HIGH);
	digitalWrite(red2,LOW);
	delay(1000);
}

void loop()
{
	if(digitalRead(in) && !digitalRead(out))
	{
		IN();
	}
	else if(!digitalRead(in) && digitalRead(out))
	{
		OUT();
	}
	else
	{
		NEUTRAL();
	}
}

