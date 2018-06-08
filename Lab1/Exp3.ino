const int pin[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int i,j;
void setup() {

  for (int i = 0; i < 10; i++)
    pinMode(pin[i], OUTPUT);
}

void loop() {

  for(i=1;i<=8;i++)
  {
    for(j=1;j<=i;j++)
    {
      digitalWrite(pin[j], HIGH);
      delay(200);
    }
    for(j=2;j<=i;j++)
    {
      digitalWrite(pin[j], LOW);
    }
    if(i==8)
      digitalWrite(pin[1],LOW);
    delay(200);
  }

  for(int i=8;i>=1;i--)
  {
    for(int j=8;j>=i;j--)
    {
      digitalWrite(pin[j], HIGH);
      delay(200);
    }
    for(int j=7;j>=i;j--)
    {
      
      digitalWrite(pin[j], LOW);
    }
    
    if(i==1)
      digitalWrite(pin[8],LOW);
    delay(200);
  }
}

