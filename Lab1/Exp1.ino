const int pin[] = {0,1,2,3,4,5,6,7,8,9};
void setup() {

  for(int i=0;i<10;i++)
      pinMode(pin[i], OUTPUT);

}

void loop() {

for(int i=1;i<=8;i++)
  {
      digitalWrite(pin[i], HIGH);
      delay(500);
  }

  
for(int i=8;i>=1;i--)
  {
      digitalWrite(pin[i], LOW);
      delay(500);
  }
  
}

