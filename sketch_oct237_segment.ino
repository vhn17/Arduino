int leda = 12;
int ledb = 11;
int ledc = 10;
int ledd = 9;
int lede = 8;
int ledf = 7;
int ledg = 6;

int a0 = 3;
int a1 = 2;
int a2 = 5;
int a3 = 4;
int button = A2;
int off;
int counter = 0;
int segment[10][7] =
{
  {1, 1, 1, 1, 1, 1, 0}, //0
  {1, 1, 0, 0, 0, 0, 0}, //1
  {1, 0, 1, 1, 0, 1, 1}, //2
  {1, 1, 1, 0, 0, 1, 1}, //3
  {1, 1, 0, 0, 1, 0, 1}, //4
  {0, 1, 1, 0, 1, 1, 1}, //5
  {0, 1, 1, 1, 1, 1, 1}, //6
  {1, 1, 0, 0, 0, 1, 0}, //7
  {1, 1, 1, 1, 1, 1, 1}, //8
  {1, 1, 1, 0, 1, 1, 1}, //9
};
void digit0write(int digit0)
{
  digitalWrite(a0, HIGH);
  digitalWrite(a1, LOW);
  for (int i = 6; i < 13; i++)
  {
    digitalWrite(i , 1 - segment[digit0][12 - i]);
  }
}
void digit1write(int digit1)
{
  digitalWrite(a0, LOW);
  digitalWrite(a1, HIGH);
  for (int i = 6; i < 13; i++)
  {
    digitalWrite(i , 1 - segment[digit1][12 - i]);
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(a0, OUTPUT);
  digitalWrite(a0, LOW);
  pinMode(a1, OUTPUT);
  digitalWrite(a1, LOW);
  pinMode(a2, OUTPUT);
  digitalWrite(a2, LOW);
  pinMode(a3, OUTPUT);
  digitalWrite(a3, LOW);
  pinMode(button, INPUT_PULLUP);
  for (int i = 12; i > 5; i--)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);

  }

}
void loop() {
  off = digitalRead(button);
  if (off == LOW) {
    for (int digit1 = 0; digit1 < 10; digit1++)
    {
      for (int digit0 = 0; digit0 < 10; digit0++)
      {
        for (int i = 0; i < 10; i++)
        {
          digit0write(digit0);
          delay(5);
          digit1write(digit1);
          delay(5);
        }
      }
    }
  } else {
      for (int i = 2 ; i < 6; i++)
        digitalWrite(i, LOW);
  }
}
