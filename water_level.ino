int l1=A1;
int l2=A2;
int l3=A3;
int l4=A4;
int l5=A5;
int con = 13;
int senl1,senl2,senl3,senl4,senl5;
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



void setup() {
  // put your setup code here, to run once:
pinMode (l1,INPUT_PULLUP);
pinMode (l2,INPUT_PULLUP);
pinMode (l3,INPUT_PULLUP);
pinMode (l4,INPUT_PULLUP);
pinMode (l5,INPUT_PULLUP);
pinMode (con,OUTPUT);
digitalWrite(con,0);
lcd.begin(16,2); 
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Initializing...");
lcd.setCursor(0,1);
lcd.print("Please wait");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Initialized....");
lcd.setCursor(0,1);
lcd.print("     Welcome");
delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:
  senl1 = digitalRead(l1);
  senl2 = digitalRead(l2);
  senl3 = digitalRead(l3);
  senl4 = digitalRead(l4);
  senl5 = digitalRead(l5);

  if ((senl5)==0) {
    //lcd.print ("WATER LEVEL");
   lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water Level: 5");
lcd.setCursor(0,1);
lcd.print("Pump State: Off");
    delay(100);
    digitalWrite (con, 1);
    }
   else { if ((senl4)==0) {
          lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water Level: 4");
lcd.setCursor(0,1);
lcd.print("Pump State: ");
    delay(100);
    }
    else { if ((senl3)==0) {
          lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water Level:3");
lcd.setCursor(0,1);
lcd.print("Pump State: ");
    delay(100);
    }
    else { if ((senl2)==0) {
     lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water Level: 2");
lcd.setCursor(0,1);
lcd.print("Pump State: On");
    delay(100);
    delay(100);
    digitalWrite (con, 0);
    }
    else { if ((senl1)==0) {
      lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water Level: 1");
lcd.setCursor(0,1);
lcd.print("Pump State: ");
    
    delay(100);
    }
    else {
      lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water Level: 0");
lcd.setCursor(0,1);
lcd.print("Pump State: ");
    delay(100);
    }
}}}}}
