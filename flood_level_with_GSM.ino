int l1=A0;
int l2=A1;
int l3=A2;
//int l4=A3;
int red=8;
//int ora=A5;
int yel=11;
int gre=12;
int buz =13;
int senl1,senl2,senl3;

//#include <LiquidCrystal.h>
//const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
//LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
//#include <SoftwareSerial.h>
//SoftwareSerial gsm (10,9);//(Rx,Tx)
boolean sed1 = false;
boolean sed2 = false;
boolean sed3 = false;

void setup() {
  // put your setup code here, to run once:
pinMode (l1,INPUT_PULLUP);
pinMode (l2,INPUT_PULLUP);
pinMode (l3,INPUT_PULLUP);
//pinMode (l4,INPUT_PULLUP);
pinMode (buz,OUTPUT);
//pinMode (ora,OUTPUT);
pinMode (red,OUTPUT);
pinMode (yel,OUTPUT);
pinMode (gre,OUTPUT);
//gsm.begin(9600);
//Serial.begin(9600);
//delay(100);
//lcd.begin(16,2);
//lcd.clear();
//    lcd.print ("INITIALIZING...");
//    delay(20000);
// lcd.clear();
//    lcd.print ("INITIALIZED.");
//    delay(2000);
//
//
//gsm.println("ATD+2348027951850;");
//delay(10000);
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2348027951850\"\r");
//delay(100);
//gsm.println("URGENT ATTENTION IS NEEDED!");
//gsm.println((char)26);
//delay(100);

//delay(5000);
}

// void SendMessage3(){
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2348027951850\"\r");
//delay(100);
//gsm.println("Water at critical level, evacuate!!!");
//gsm.println((char)26);
//delay(2000);
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2348035770398\"\r");
//delay(100);
//gsm.println("Water at critical level, evacuate!!!");
//gsm.println((char)26);
//delay(100);
//delay(2000);
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2348157580266\"\r");
//delay(100);
//gsm.println("Water at critical level, evacuate!!!");
//gsm.println((char)26);
//delay(100);
//delay(2000);
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2347039743194\"\r");
//delay(100);
//gsm.println("Water at critical level, evacuate!!!");
//gsm.println((char)26);
//delay(100);}

// void SendMessage2(){
//
//  gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2348027951850\"\r");
//delay(100);
//gsm.println("Now in level 3, urgent attention is needed");
//gsm.println((char)26);
//delay(2000);
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2348035770398\"\r");
//delay(100);
//gsm.println("Now in level 3, urgent attention is needed");
//gsm.println((char)26);
//delay(100);
//delay(2000);
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2348157580266\"\r");
//delay(100);
//gsm.println("Now in level 3, urgent attention is needed");
//gsm.println((char)26);
//delay(100);
//delay(2000);
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2347039743194\"\r");
//delay(100);
//gsm.println("Now in level 3, urgent attention is needed");
//gsm.println((char)26);
//delay(100);
//}
// void SendMessage1(){
//
//    gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2348027951850\"\r");
//delay(100);
//gsm.println("The water has rised to level 2");
//gsm.println((char)26);
//delay(2000);
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2348035770398\"\r");
//delay(100);
//gsm.println("The water has rised to level 2");
//gsm.println((char)26);
//delay(100);
//delay(2000);
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2348157580266\"\r");
//delay(100);
//gsm.println("The water has rised to level 2");
//gsm.println((char)26);
//delay(100);
//delay(2000);
//gsm.println("AT+CMGF=1");
//delay(100);
//gsm.println("AT+CMGS=\"+2347039743194\"\r");
//delay(100);
//gsm.println("The water has rised to level 2");
//gsm.println((char)26);
//delay(100);
//gsm.println("AT+CMGF=1");
//delay(100);
//}


void loop() {
  // put your main code here, to run repeatedly:
  senl1 = digitalRead(l1);
  senl2 = digitalRead(l2);
  senl3 = digitalRead(l3);
  //senl4 = digitalRead(l4);
  
  if ((senl3)==0) {
//    lcd.clear();
//    lcd.setCursor(0,0);
//    lcd.print ("WATER LEVEL: 4");
//    lcd.setCursor(0,1);
      digitalWrite (red, 1);
      digitalWrite (gre, 0);
       digitalWrite (yel, 0);
        //digitalWrite (ora, 0);
//    lcd.print ("EVACUATE!!!");
    delay(100);
      digitalWrite (buz, 1);
    delay(100);
    digitalWrite (buz, 0);
    delay(100);
      digitalWrite (buz, 1);
    delay(100);
    digitalWrite (buz, 0);
    delay(100);
      digitalWrite (buz, 1);
    delay(100);
    digitalWrite (buz, 0);
    delay(100);
      digitalWrite (buz, 1);
    delay(100);
    digitalWrite (buz, 0);
    delay(100);
      digitalWrite (buz, 1);
    delay(100);
    digitalWrite (buz, 0);
    delay(100);
  if(sed3){
// SendMessage3();
  sed3 = false;
  }
  }
   else { if ((senl2)==0) {
    
//    lcd.clear();
//    lcd.setCursor(0,0);
//    lcd.print ("WATER LEVEL: 3");
//    lcd.setCursor(0,1);
      digitalWrite (red, 1);
      digitalWrite (gre, 0);
       digitalWrite (yel, 1);
//        digitalWrite (ora, 1);
//    lcd.print ("WATER IS LOOMING");
    delay(500);
    digitalWrite (buz, 1);
    delay(500);
    digitalWrite (buz, 0);
    delay(100);
     digitalWrite (buz, 1);
    delay(500);
    digitalWrite (buz, 0);
    delay(100);
     digitalWrite (buz, 1);
    delay(500);
    digitalWrite (buz, 0);
    delay(100);
     digitalWrite (buz, 1);
    delay(500);
    digitalWrite (buz, 0);
    delay(100);
     digitalWrite (buz, 1);
    delay(500);
    digitalWrite (buz, 0);
    delay(100);
     digitalWrite (buz, 1);
    delay(500);
    digitalWrite (buz, 0);
    delay(100);
    sed3 = true;
     if(sed2){
// SendMessage2();
  sed2 = false;
  }
  }
 
    else { if ((senl1)==0) {
      //sed2=true;
//    lcd.clear();
//    lcd.setCursor(0,0);
//    lcd.print ("WATER LEVEL: 2");
      digitalWrite (red, 1);
      digitalWrite (gre, 1);
       digitalWrite (yel, 1);
//        digitalWrite (ora, 0);
//    lcd.setCursor(0,1);
//    lcd.print ("WATER RISING");
    delay(100);
     if(sed1){
// SendMessage1();
  sed1 = false;
  }
    }

//    else { if ((senl1)==0) {
//      sed1=true;
//    lcd.clear();
//    lcd.setCursor(0,0);
//    lcd.print ("WATER LEVEL: 1");
//      digitalWrite (red, 0);
//      digitalWrite (gre, 1);
//       digitalWrite (yel, 0);
//        digitalWrite (ora, 0);
//    delay(100);
//    }
//    else {lcd.clear();
//    lcd.print ("SAFE LEVEL");
//    delay(100);
//     digitalWrite (red, 0);
//      digitalWrite (gre, 0);
//       digitalWrite (yel, 0);
//        digitalWrite (ora, 0);
//    }
    
    }}}
