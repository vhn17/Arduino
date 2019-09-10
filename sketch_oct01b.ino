int ledpinB=7;
int ledpinR=4;
int ledpinG=6;
int i=0;
int buttonpin=A2;
int val=0;
void setup() {
  // put your setup code here, to run once:
pinMode(ledpinB , OUTPUT);
pinMode(ledpinR , OUTPUT);
pinMode(ledpinG , OUTPUT);
pinMode(buttonpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(buttonpin);

  if(val==HIGH)
  {
    while( i<3)
      {
          digitalWrite(ledpinB, HIGH);
          delay(1000);
          digitalWrite(ledpinB,LOW);
          digitalWrite(ledpinG,HIGH);
          delay(1500);
          digitalWrite(ledpinG,LOW);
          digitalWrite(ledpinR,HIGH);
          delay(1200);
          digitalWrite(ledpinR,LOW);
          i++;
      }
    i=0;
    while(i<2)
    {
    digitalWrite(ledpinG,HIGH);
    digitalWrite(ledpinB,HIGH);
    digitalWrite(ledpinR,HIGH);
      delay(1000);
    digitalWrite(ledpinG,LOW);
    digitalWrite(ledpinB, LOW);
    digitalWrite(ledpinR, LOW);
      delay(1000);
      i++;
    }
    i=0;
  }
  else
    {    
    digitalWrite(ledpinG,LOW);
    digitalWrite(ledpinB, LOW);
    digitalWrite(ledpinR, LOW);
    }
 
}
