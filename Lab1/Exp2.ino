const int pin[] = {0,1,2,3,4,5,6,7,8,9};
int i;
bool flag;
void setup() {

  for(int i=0;i<10;i++)
      pinMode(pin[i], OUTPUT);

  i = 1;
  flag = true;
}

void loop() {


      digitalWrite(pin[i], HIGH);
      delay(500);
      digitalWrite(pin[i], LOW);
    if(i==8)
      flag = false;
     if(i==1)
      flag = true;

      if(flag)  i++;
      else i--;

  
}

