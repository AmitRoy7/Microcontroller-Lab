#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int red1    = 6;
const int green1  = 7;
const int red2    = 8;
const int green2  = 9;

bool greenflag1, greenflag2, redflag1, redflag2;


#define in 14
#define out 19

void OUT()
{

  if (greenflag2 )
  {
    digitalWrite(red1, HIGH);
    digitalWrite(green1, LOW);
    redflag1 = true;
    greenflag1 = false;

    lcd.clear();
    lcd.print("Incoming: OFF");
    lcd.setCursor(0, 1);
    lcd.print("Outgoing: ON");
    while (!digitalRead(out));


  }
  else if (redflag2)
  {
    while (!digitalRead(out));
    digitalWrite(green2, HIGH);
    digitalWrite(red2, false);
    greenflag2 = true;
    redflag2 = false;


    lcd.clear();
    lcd.print("Incoming: ON");
    lcd.setCursor(0, 1);
    lcd.print("Outgoing: ON");
  }
  delay(1000);
}

void IN()
{

  if (greenflag1 )
  {
    digitalWrite(red2, HIGH);
    digitalWrite(green2, LOW);
    redflag2 = true;
    greenflag2 = false;


    lcd.clear();
    lcd.print("Incoming: ON");
    lcd.setCursor(0, 1);
    lcd.print("Outgoing: OFF");
    while (!digitalRead(in));

  }
  else if (redflag1)
  {
    while (!digitalRead(in));
    digitalWrite(green1, HIGH);
    digitalWrite(red1, false);
    greenflag1 = true;
    redflag1 = false;


    lcd.clear();
    lcd.print("Incoming: ON");
    lcd.setCursor(0, 1);
    lcd.print("Outgoing: ON");
  }
  delay(1000);
}

void setup()
{
  pinMode(in, INPUT);
  pinMode(out, INPUT);

  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);

  greenflag1 = true;
  greenflag2 = true;
  redflag1 = false;
  redflag2 = false;


  lcd.begin(16, 2);
  lcd.clear();
  lcd.print(" TRAFFIC CONTROL");
  delay(2000);

  lcd.clear();
  lcd.print("Incoming: ON");
  lcd.setCursor(0, 1);
  lcd.print("Outgoing: ON");

  digitalWrite(green1, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(green2, HIGH);
  digitalWrite(red2, LOW);
  delay(1000);

  Serial.begin(9600);
}

void loop()
{

  if (!digitalRead(in) )
  {
    IN();
    //while (!digitalRead(in));
    //{
    //  delay(10);
    //}
  }
  else if (!digitalRead(out) )
  {
    OUT();
    //while (!digitalRead(out));
    //{
    //  delay(10);
    //}
  }
  Serial.print(digitalRead(in));
  Serial.println("");
  Serial.print(digitalRead(out));
  Serial.println("");

}
