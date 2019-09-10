#include <LiquidCrystal.h>

 // megjegyzes : 40 karakter hosszu lehet
LiquidCrystal lcd(9, 8, 4, 5, 6, 7);
char s1[] = "HEllo world";
char s2[]="Hello Earth";
//int counter =0;
void setup() {
  lcd.begin(16, 2);
  leftprint(s1);
  rightprint(s2);
}
void rightprint(char text[]) {
  for(int i=16;i>=0;i--) {
    lcd.setCursor(0,1);

    for(int j=0;j<16;j++) {
      lcd.print(" ");
    }

    lcd.setCursor(i,1);
    lcd.print(text);
    delay(400);
  }
}

void leftprint(char text[]) {
  for(int i = 40 - strlen(text); i <= 40 - strlen(text) + 16; i++)
  {
    lcd.setCursor(0,1);
    for(int j=0;j<16;j++)
    {
      lcd.print(" ");
    }
    lcd.setCursor(i,1 );
    lcd.print(text);
    delay(40);
  }
}
void loop(){
  delay(1000);
}
