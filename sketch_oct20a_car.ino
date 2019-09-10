#include <SoftwareSerial.h>
#include <Servo.h>

int bluetoothTx = 3;
int bluetoothRx = 2;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
// Motor 1 - control forward and back
int Motor1A = 9;
int Motor1B = 10;
//Motor 2 - control left and right
int Motor2A = 11;
int Motor2B = 12;
int ledPinFront = 8;
int ledPinBack = 7;
int PinVolume = 6;
int echopin = 5;
int trigpin = 4;
int sebesseg = 0;
int flag1 = -1;
int flag2 = -1;
bool volumeon = false;
bool turnoff = false;

void setup()
{
  //Setup Bluetooth serial connection to android
  bluetooth.begin(115200);
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);
  pinMode( Motor1A, OUTPUT );
  pinMode( Motor1B, OUTPUT );
  digitalWrite( Motor1A, LOW );
  digitalWrite( Motor1B, LOW );
  pinMode( Motor2A, OUTPUT );
  pinMode( Motor2B, OUTPUT );
  digitalWrite( Motor2A, LOW );
  digitalWrite( Motor2B, LOW );
  pinMode(ledPinFront, OUTPUT);
  digitalWrite(ledPinFront, LOW);
  pinMode(ledPinBack, OUTPUT);
  digitalWrite(ledPinBack, LOW);
  pinMode(PinVolume, OUTPUT);
  digitalWrite(PinVolume, LOW);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  digitalWrite(trigpin, LOW);

}


void sensor()
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  double duration = pulseIn(echopin, HIGH);
  double distance = (duration / 2) / 29.3867;
  // Serial.begin(9600);
  // Serial.print(distance);
  //Serial.println(" ");
  if (distance <= 30 && distance > 0) {
    digitalWrite(PinVolume, HIGH);
    flag1 = 0;
    flag2 = 0;
    digitalWrite( Motor1A, LOW );
    analogWrite( Motor1B, LOW );
    digitalWrite( Motor2A, LOW );
    analogWrite( Motor2B, LOW );
    turnoff = true;
  } else {
    if (volumeon == false) // !volumeon
      digitalWrite(PinVolume, LOW);
    turnoff = false;
  }
  //delay(300);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  // bluetooth.begin(9600);
  if (bluetooth.available()) {
    char toSend = (char)bluetooth.read();

    //   Serial.begin(9600);
    //   if (toSend != 'S')
    //    Serial.print(toSend);
    sensor();

    if (toSend == 'W')
      digitalWrite(ledPinFront, HIGH);
    if (toSend == 'w')
      digitalWrite(ledPinFront, LOW);
    if (toSend == 'U')
      digitalWrite(ledPinBack, HIGH);
    if (toSend == 'u')
      digitalWrite(ledPinBack, LOW);
    if (toSend == 'V') {
      digitalWrite (PinVolume, HIGH);
      volumeon = true;
    }
    if (toSend == 'v') {
      digitalWrite (PinVolume, LOW);
      volumeon = false;
    }

    if (toSend == 'S') {
      flag1 = 0;
      flag2 = 0;
      digitalWrite( Motor1A, LOW );
      analogWrite( Motor1B, LOW );
      digitalWrite( Motor2A, LOW );
      analogWrite( Motor2B, LOW );
    }

    if (toSend == '0' || toSend == '1' || toSend == '2' || toSend == '3' ||
        toSend == '4' || toSend == '5' || toSend == '6' || toSend == '7' ||
        toSend == '8' || toSend == '9' )
      sebesseg = toSend - 48;

    if (turnoff == false) {
      if (toSend == 'F' || toSend == 'G' || toSend == 'I') {
        if (flag1 != 1)
        {
          flag1 = 1;
          analogWrite( Motor1A, 50 + sebesseg * 23 );
          digitalWrite( Motor1B, LOW );
        }
      }

      if (toSend == 'B' || toSend == 'H' || toSend == 'J') {
        if (flag1 != 2)
        {
          flag1 = 2;
          digitalWrite( Motor1B, HIGH );
          analogWrite( Motor1A, 125);
        }
      }

      if (toSend == 'L' || toSend == 'G' || toSend == 'H') {
        if (flag2 != 1)
        {
          flag2 = 1;
          analogWrite( Motor2B, 200);
          analogWrite( Motor2A, 0 );
        }
      } else if (toSend == 'R' || toSend == 'I' || toSend == 'J') {
        if (flag2 != 2)
        {
          flag2 = 2;
          analogWrite( Motor2A, 210);
          analogWrite( Motor2B, 0);
        }
      }
    } else  if (toSend == 'B' || toSend == 'H' || toSend == 'J') {
      if (flag1 != 2)
      {
        flag1 = 2;
        digitalWrite( Motor1B, HIGH );
        analogWrite( Motor1A, 125);
      }
    } else if (flag2 != 3) {
      flag2 = 3;
      digitalWrite( Motor2A, LOW );
      digitalWrite( Motor2B, LOW );
    }
  }
}
