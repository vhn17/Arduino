const int ledr = 9;
const int ledg = 10;
const int ledb = 11;
int button = A2;
int redcolor;
int greencolor;
int bluecolor;
int color = 0;
int i=11;
int t = 1000;
int t1 = 800;

void setup(){
  for(int i=9; i<=11;i++) {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
  pinMode(button,INPUT_PULLUP);
}
void loop(){
  for (int i = 9; i <= 11; i++) {
    digitalWrite(i,LOW);
  }
  if (digitalRead(button) == LOW) {
    villog1();
    delay(t/2);
    villog2();
    delay(t);
    showSpectrum();
    delay(t/2);
  } else {
    for(int i = 9; i <= 11; i++){
      digitalWrite(i,LOW);
    }
  }
}
void villog1()
{
  int i;
  for (i = 9; i <= 11; i++) {
    digitalWrite(i,HIGH);
    delay(t1);
    digitalWrite(i,LOW);
    delay(t1);
  }
}
void villog2()
{
  for (i = 9;i <= 11; i++) {
    digitalWrite(i,1);
  }
  delay(t);
  for (i = 9; i <= 11; i++) {
    digitalWrite(i,0);
  }
  delay(t);
  for (i = 9; i <= 11; i++) {
    digitalWrite(i,1);
  }
  delay(t);
  for(i = 9; i <= 11; i++)
  {
    digitalWrite(i,0);
  }
  delay(t);
  for(i = 9; i <= 11; i++) {
    digitalWrite(i,1);
  }
  delay(t);
  for(i = 9; i <= 11; i++) {
    digitalWrite(i,0);
  }
  delay(t);
}
void showSpectrum()
{
  for (int i=0 ; i<768 ; i++) {
    showRGB(i);
    delay(20);
  }
}

void showRGB(int color)
{
  if (color <= 255) {
    redcolor = 255-color;
    greencolor = color;
    bluecolor = 0;
  } else if (color <= 511) {
    redcolor = 0;
    greencolor = 255 - (color - 256);
    bluecolor = color;
  } else if (color >= 512) {
    redcolor = color - 512;
    greencolor = 0;
    bluecolor = 255 - (color - 512);
  }
  analogWrite(ledr,redcolor);
  analogWrite(ledg,greencolor);
  analogWrite(ledb,bluecolor);
}
